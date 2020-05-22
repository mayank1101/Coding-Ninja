#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadaneAlgo(int arr[], int n)
{
    ll curr_sum = 0, max_so_far = INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];
        max_so_far = max(max_so_far, curr_sum);
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_so_far;
}

ll maxSumSubArr(int arr[], int n, int k)
{
    ll kadaneSum = kadaneAlgo(arr,n);
    if(k == 1){
        return kadaneSum;
    }
    //find maximum prefix sum
    ll curr_prefix_sum = 0, max_prefix_sum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_prefix_sum += arr[i];
        max_prefix_sum = max(curr_prefix_sum, max_prefix_sum);
    }
    ll sum_of_elements = curr_prefix_sum; //sum of elements of A

    //find maximum suffix sum
    ll curr_suffix_sum=0, max_suffix_sum=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        curr_suffix_sum += arr[i];
        max_suffix_sum = max(curr_suffix_sum, max_suffix_sum);
    }
    ll ans;
    if(sum_of_elements < 0){
        ans = max((max_prefix_sum + max_suffix_sum), kadaneSum);
    }
    else{
        ans = max((max_prefix_sum + (sum_of_elements*(k-2)) + max_suffix_sum), kadaneSum);
    }
    return ans;
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout << maxSumSubArr(arr,n,k) << "\n";
    }
	return 0;
}
