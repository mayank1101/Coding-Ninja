#include<iostream>
using namespace std;
#include "queueUsingDynamicArray.h"


int main()
{
	queueUsingDynamicArray<char> q(3);
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