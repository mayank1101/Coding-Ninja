#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		int n,x;
		cin>>n;
		vector<int> arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>x;
			arr.push_back(x);
		}

		//sort
		sort(arr.begin(), arr.end());

		//remove duplicate
		vector<int> output;
		output.push_back(arr[0]);
		for(int i=1;i<n;i++)
		{
			if(arr[i] != arr[i-1]){
				output.push_back(arr[i]);
			}
		}
		for(int i=1;i<n;i++)
		{
			cout << output[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}