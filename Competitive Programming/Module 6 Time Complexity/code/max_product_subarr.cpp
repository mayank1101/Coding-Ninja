//We assumes that the given input array always has a positive output
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
        int max_product = 1, min_product = 1, max_so_far = 1;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                max_product =max_product * arr[i];
                min_product = min(1, min_product * arr[i]);
            }
            else if(arr[i] == 0){
                max_product = min_product = 1;
            }
            else if(arr[i] < 0){
                int temp = max_product;
                max_product = min(min_product*arr[i],1);
                min_product = temp * arr[i];
            }
            max_so_far = max(max_so_far, max_product);
        }
        cout << max_so_far << "\n";
    }
    return 0;
}
