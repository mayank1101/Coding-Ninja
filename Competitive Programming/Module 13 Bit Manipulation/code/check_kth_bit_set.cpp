// check kth bit from right is set or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num,k;
	cin>>num>>k;
	if(num & (1<<k)){
		cout << "Yes"
	}
	else{
		cout << "No"
	}
	cout << "\n";
	return 0;
}