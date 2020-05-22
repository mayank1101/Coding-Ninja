#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("encyin.txt","r",stdin);
    freopen("encyout.txt","w",stdout);

    int n,q;
    cin>>n>>q;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<q;i++){
        int pgno;
        cin>>pgno;
        cout << arr[pgno-1] << "\n";
    }
    return 0;
}
