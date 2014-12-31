/*
 * main.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: radoslav
 */

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
queue<T> merge(queue<T> q1, queue<T> q2)
{
	queue<T> q;

	while (!q1.empty() && !q2.empty())
	{
		T f1 = q1.front(), f2 = q2.front();

		if (f1 < f2)
		{
			q.push(f1);
			q1.pop();
		}
		else
		{
			q.push(f2);
			q2.pop();
		}
	}

	while (!q1.empty())
	{
		q.push(q1.front());
		q1.pop();
	}

	while (!q2.empty())
	{
		q.push(q2.front());
		q2.pop();
	}

	return q;
}

template <typename T>
queue<T> sortMerge(queue<T> q)
{
	queue<T> l, r;

	if (q.empty())
		return q;

	while (!q.empty())
	{
		l.push(q.front());
		q.pop();
		r.push(q.front());
		q.pop();
	}

	l = sortMerge(l);
	r = sortMerge(r);
	return merge(l, r);
}

int main()
{
	queue<int> q;
	int n;

	do
	{
		cin >> n;
		q.push(n);
	}
	while (n);

	q = sortMerge(q);

	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}
