/*
 * exprtree.cpp (originally tree_examples.cpp)
 *
 *  Created on: 5.01.2015 г.
 *      Author: trifon
 * Contributor: radoslav
 */

#include "bintree.cpp"
#include "lstack.cpp"

class SElement
{
public:
    virtual ~SElement() {}
    virtual SElement* clone() = 0;

    template <typename T>
    virtual T& operator*() = 0;

    template <typename T>
    virtual T& get() = 0;
};

template <typename T>
class SType : public SElement
{
public:
    T data;

    SType(const T& _data = T()): data(_data) {}

    SType* clone()
    {
        return new SType(data);
    }

    T& operator*() { return data; }
    T& get() { return data; }
};

class SBinaryTreeIterator : public BinaryTreeIterator<SElement*>
{
public:
    template <typename T>
	T& operator*()
    {
		return ptr->data->get();
	}
};

class SBinaryTree : public BinaryTree<SElement*>
{
	void deleteNode(TreeNode<SElement*>* node) {
		if (node != NULL) {
            delete node->data;
            deleteNode(node->left);
			deleteNode(node->right);
			delete node;
		}
	}

	TreeNode<SElement*>* copyNode(TreeNode<SElement*>* src) {
		if (src == NULL)
			return NULL;
		return new TreeNode<SElement*>(src->data->clone(),
                            copyNode(src->left),
                            copyNode(src->right));
	}

public:
	SBinaryTree(): root(NULL) {}

    template <typename T>
	SBinaryTree(const T& data):
            root(new TreeNode<SElement*>(new SType<T>(data))) {}

    template <typename T>
	SBinaryTree(const T& data, SBinaryTree& left, SBinaryTree& right)
    {
		root = new TreeNode<SElement*>(new SType<T>(data));
		adoptLeft(left.root);
		adoptRight(right.root);
	}

	SBinaryTree(const SBinaryTree& other): root(copyNode(other.root)) {}

	SBinaryTree& operator=(const SBinaryTree& other)
    {
		if (&other != this)
        {
			deleteNode(root);
			root = copyNode(other.root);
		}

		return *this;
	}

	~SBinaryTree()
    {
		deleteNode(root);
	}
};

void createTree(LinkedStack<SBinaryTree>& rstack, char op) {
	SBinaryTree rtree = rstack.pop();
	SBinaryTree ltree = rstack.pop();
	rstack.push(SBinaryTree(op, ltree, rtree));
}

int priority(char op) {
	switch (op) {
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
    case '^':return 3;

	default:return -1;
	}
}

int pow(int a, int n)
{
    if (a == 0)
        return 0;
    else if (a == 1 || n <= 0)
        return 1;
    else if (n % 2)
        return a * pow(a, n - 1);
    else
    {
        int b = pow(a, n / 2);
        return b * b;
    }
}

SBinaryTree createExpressionTree(char const* expr) {
	LinkedStack<char> opstack;
	LinkedStack<SBinaryTree> rstack;

	while(*expr) {
		if (    *expr >= '0' && *expr <= '9' ||
                *expr == '-' && *(expr + 1) >= '0' && *(expr + 1) <= '9'    )
			rstack.push(SBinaryTree(atoi(*expr)));

            while (*expr && *(expr + 1) >= '0' && *(expr + 1) <= '9')
                expr++;
		else
		if (*expr == '(')
			opstack.push(*expr);
		else
		if (*expr == ')') {
			char op = opstack.pop();
			while (op != '(') {
				createTree(rstack, op);
				op = opstack.pop();
			}
		} else {
			// *expr е операция
			// първо: вадим всички операции
			// с по-висок или равен приоритет
			while (!opstack.empty() &&
				   priority(opstack.last()) >=
				   priority(*expr))
				createTree(rstack,opstack.pop());
			opstack.push(*expr);
		}
		expr++;
	}
	while (!opstack.empty())
		createTree(rstack, opstack.pop());

	return rstack.pop();
}

double calculate(SBinaryTreeIterator it) {
	if (*it >= '0' && *it <= '9')
		// листо
		return *it - '0';
	switch (*it) {
	case '+': return calculate(++it) + calculate(it++);
	case '-': return calculate(++it) - calculate(it++);
	case '*': return calculate(++it) * calculate(it++);
	case '/': return calculate(++it) / calculate(it++);
	default: return 0;
	}
}

int const MAX = 100;

void testExpressionTree() {
	char expr[MAX];
	cin.getline(expr, MAX);
	BinaryTree<char> t = createExpressionTree(expr);
	cout << t << endl;
	cout << calculate(t.iterator()) << endl;
}

