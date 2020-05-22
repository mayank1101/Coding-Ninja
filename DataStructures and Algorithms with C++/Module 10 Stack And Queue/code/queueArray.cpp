#include<iostream>
using namespace std;
#include "queueUsingArray.h"


int main()
{
	queueUsingArray<char> q(6);
	q.enqueue('m');
	q.enqueue('a');
	q.enqueue('y');
	q.enqueue('a');
	q.enqueue('n');
	q.enqueue('k');
	cout << q.getSize() << "\n";
	cout << q.front() << "\n";
	cout << q.dequeue() << "\n";
	cout << q.dequeue() << "\n";
	cout << q.getSize() << "\n";
	cout << q.front() << "\n";
}