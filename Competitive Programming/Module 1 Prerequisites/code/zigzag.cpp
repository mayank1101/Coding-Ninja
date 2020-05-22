#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n]; //create 2d array dynamically
    for(int i=0;i<n;i++){
        arr[i] = new int[n]; //create row dynamically
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //print array in zigzag manner top-bottom bottom-top
    for(int col=0;col<n;col++){
        if(col%2==0){
            for(int row=0;row<n;row++){
                cout << arr[row][col] << " ";
            }
        }
        else{
            for(int row=n-1;row>=0;row--){
                cout << arr[row][col] << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
