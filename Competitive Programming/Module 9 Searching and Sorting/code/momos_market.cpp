//CodeZen Momos Market
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& A, int start, int end, long amnt)
{
	if(start > end){
		return -1;
	}
	if(amnt >= A[end]){
		return end;
	}
	int mid = (start+end)>>1;
	if(A[mid] == amnt){
		return mid;
	}
	if(mid>0 && (amnt < A[mid] && amnt >= A[mid-1])){
		return mid-1;
	}
	if(amnt < A[mid]){
		return binarySearch(A,0,mid-1,amnt);
	}
	else{
		return binarySearch(A,mid+1,end,amnt);
	}
}

int main()
{
	int n,days,price,sum=0;
	cin>>n;
	vector<int> prefixSum;
	for(int i=0;i<n;i++){
		cin>>price;
		sum += price;
		prefixSum.push_back(sum);
	}
	cin>>days;
	long amnt;
	while(days--)
	{
		cin>>amnt;
		int ans = binarySearch(prefixSum,0,n-1,amnt);
		if(ans != -1){
			amnt -= prefixSum[ans];
		}
		cout << (ans+1) << " " << amnt << "\n";
	}
	return 0;
}