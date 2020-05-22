//clear all the bits from LSB to kth bit

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int mask = ~((1<<k+1) - 1)
	int ans = n & mask;
	cout << ans << "\n";
	return 0;
}