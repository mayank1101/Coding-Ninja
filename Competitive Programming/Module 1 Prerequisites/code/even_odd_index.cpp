#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum_even=0, sum_odd=0;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if((i%2 == 0) && (arr[i]%2 == 0)){
            sum_even += arr[i];
        }
        else if((i%2 != 0) && (arr[i]%2 != 0)){
            sum_odd += arr[i];
        }
    }
    cout << sum_even << " " << sum_odd << "\n";
	return 0;
}
