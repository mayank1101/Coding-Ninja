//find contiguous sub array with maximum sum
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long n;
        cin>>n;
        LL *arr = new LL[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        LL curr_subarr_sum = 0;
        LL max_subarr_sum = INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr_subarr_sum += arr[i];
            if(curr_subarr_sum > max_subarr_sum){
                max_subarr_sum = curr_subarr_sum;
            }
            if(curr_subarr_sum < 0){
                curr_subarr_sum = 0;
            }
        }
        cout << max_subarr_sum << "\n";
    }
	return 0;
}
