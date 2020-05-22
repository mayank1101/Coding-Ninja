//check number is even or odd
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if((n & 1) == 1){
		cout << n << " is odd";
	}
	else{
		cout << n << " is even";
	}
	cout << "\n";
	return 0;
}