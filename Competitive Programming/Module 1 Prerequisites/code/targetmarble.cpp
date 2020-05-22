#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n,target;
    cin>>n>>target;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int curr_sum = arr[0];
    int start=0, end=-1, i=0; //i keeps track of curr element
    bool flag = false;
    for(i=1;i<=n;i++)
    {
        while(curr_sum > target && start < i-1){
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == target){
            cout << "true\n";
            end = i-1;
            flag = true;
            break;
        }
        if(i < n){
            curr_sum += arr[i];
        }
    }
    if(flag){
        for(int i=start;i<=end;i++){
            cout << arr[i] << " ";
        }
    }
    else{
        cout << "false";
    }
    cout << "\n";
    return 0;
}
