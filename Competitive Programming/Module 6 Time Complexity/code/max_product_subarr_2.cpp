//Here product can be 0 or positive or negative
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int max_product = arr[0], min_product = arr[0], max_so_far = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] < 0){
                swap(max_product, min_product);
            }
            max_product = max(arr[i], max_product*arr[i]);
            min_product = min(arr[i], min_product*arr[i]);

            max_so_far = max(max_so_far, max_product);
        }
        cout << max_so_far << "\n";
    }
    return 0;
}
