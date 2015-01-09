/*
 * tree_examples.cpp
 *
 *  Created on: 5.01.2015 г.
 *      Author: trifon
 */

#include "bintree.cpp"
#include "lstack.cpp"

typedef BinaryTree<int> BIntTree;

int priority(char op) {
	switch (op) {
	case '+':
	case '-':return 1;
	case '*':
	case '/':return 2;
	default:return -1;
	}
}

void createTree(LinkedStack<BinaryTree<char> >& rstack, char op) {
	BinaryTree<char> rtree = rstack.pop();
	BinaryTree<char> ltree = rstack.pop();
	rstack.push(BinaryTree<char>(op, ltree, rtree));
}

BinaryTree<char> createExpressionTree(char const* expr) {
	LinkedStack<char> opstack;
	LinkedStack<BinaryTree<char> > rstack;

	while(*expr) {
		if (*expr >= '0' && *expr <= '9')
			rstack.push(BinaryTree<char>(*expr));
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

double calculate(BinaryTreeIterator<char> it) {
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

