#include<bits/stdc++.h>
using namespace std;

vector<int> getVotersList(int arr[], int n)
{
	vector<int> ans;
	sort(arr, arr+n);
	for(int i=0;i<n;)
	{
		int cnt=0;
		int k=i;
		while(j<n && (arr[j] == arr[i])){
			cnt++;
			j++;
		}
		if(cnt >= 2){
			ans.push_back(arr[i]);
		}
		i=j;
	}
	return ans;
}

int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int total_size = n1+n2+n3;
	int arr[total_size];
	for(int i=0;i<total_size;i++){
		cin>>arr[i];
	}
	vector<int> voter_list = getVotersList(arr, total_size);
	cout << voter_list.size() << "\n";
	vector<int>::iterator it;
	for(it=voter_list.begin();it != voter_list.end(); it++)
	{
		cout << *it << "\n";
	}
	return 0;
}