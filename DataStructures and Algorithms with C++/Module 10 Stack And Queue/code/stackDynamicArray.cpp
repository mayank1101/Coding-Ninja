#include<iostream>
using namespace std;

#include "stackUsingDynamicArray.h"

int main()
{
	stackUsingDynamicArray<char> s(6);
	s.push('m');
	s.push('a');
	s.push('y');
	s.push('a');
	s.push('n');
	s.push('k');

	cout << s.size() << "\n";
	cout << s.top() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.size() << "\n";
	cout << s.top() << "\n";
	return 0;
}