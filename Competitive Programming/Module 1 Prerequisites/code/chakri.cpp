#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n, maxprofit=0;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int cp = arr[i];
        for(int j=i+1;j<n;j++)
        {
            int sp = arr[j];
            int profit = sp - cp;
            if(profit <= 0){
                continue;
            }
            if(profit > maxprofit){
                maxprofit = profit;
            }
        }
    }
    cout << maxprofit << "\n";
    return 0;
}
