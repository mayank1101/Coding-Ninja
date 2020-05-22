//Variation
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int i=0,j=1;
	int cnt_pairs=0;
	while(j < n){
		if((arr[j] - arr[i]) >= k){
			cnt_pairs += (n-j);
			i++;
		}
		else{
		    j++;
		}
	}
	cout << cnt_pairs << "\n";
	return 0;
}