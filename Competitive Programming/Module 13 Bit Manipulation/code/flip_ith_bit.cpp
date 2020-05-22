//flip ith bit from the left
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	cin>>n>>i;
	n =  n ^ (1<<i); // n xor 2^i
	cout << n << "\n";
	return 0;
}