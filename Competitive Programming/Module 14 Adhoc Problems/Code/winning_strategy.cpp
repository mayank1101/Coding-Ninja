#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n,dist=0;;
    cin>>n;
    bool flag = true;
    string ans ="";
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dist = abs(arr[i] - (i+1));
        if(dist > 2){
            flag = false;
        }
    }
    if(flag){
        int swaps=0;
        ans = "YES";
        for(int i=n-1;i>0;i--){
            if(arr[i] == i+1){
                continue;
            }
            else if((i-1 >= 0) && (arr[i-1] == i+1)){
                swap(arr[i-1],arr[i]);
                    swaps += 1;
                continue;
            }
            else if((i-2 >= 0) && (arr[i-2] == i+1)){
                swap(arr[i-2],arr[i-1]);
                swap(arr[i-1],arr[i]);
                swaps += 2;
                continue;
            }
        }
        cout <<  ans << "\n" << swaps;
    }
    else{
        ans="NO";
        cout << ans;
    }
    cout << "\n";
    return 0;
}