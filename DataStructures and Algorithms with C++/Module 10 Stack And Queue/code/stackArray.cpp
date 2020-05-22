#include<iostream>
using namespace std;

#include "stackUsingArray.h"

int main()
{
	stackUsingArray<int> s(5);
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.isEmpty() << "\n";
	cout << s.size() << "\n";
	cout << s.top() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.top() << "\n";
	cout << s.pop() << "\n";
	cout << s.top() << "\n";
	return 0;
}