#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[10001];
    memset(arr,0,sizeof(arr));
    int p1,p2;
    for(int i=0;i<n;i++)
    {
        cin>>p1>>p2;
        arr[p1]++;
        arr[p2]++;
    }
    //find player with max friends
    int max = -1;
    for(int i=0;i<10001;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    //print player id with max friends
    for(int i=0;i<1001;i++){
        if(arr[i] == max){
            cout << i << "\n";
        }
    }
    return 0;
}
