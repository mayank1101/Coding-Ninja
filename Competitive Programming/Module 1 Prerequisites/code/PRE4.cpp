#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n/2;i++){
        int comb = arr[i] + arr[n-1-i];
        cout << (comb/10) << " " << (comb%10) << "\n";
    }
    return 0;
}
