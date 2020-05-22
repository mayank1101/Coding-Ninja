#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("tripin.txt","r",stdin);
    freopen("tripout.txt","w",stdout);

    int n,count_trp=0;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%3 == 0){
            count_trp++;
        }
    }
    if(count_trp == 0){
        cout << "Nothing here!\n";
    }
    else{
        for(int i=0;i<n;i++){
            if(arr[i]%3 == 0){
                cout << (i+1) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
