#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int** arr = new int* [n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int i=0,j=0,sum=0;
    while((i <= n-1) && (j <= n-1))
    {
        sum += arr[i++][j++];
    }
    i=0,j=n-1;
    while((i <= n-1) && (j >= 0))
    {
        sum += arr[i++][j--];
    }
    for(int i=1;i<n-1;i++)
    {
        sum += arr[0][i]; //top row
        sum += arr[n-1][i]; //bottom row
        sum += arr[i][0]; //leftmost col
        sum += arr[i][n-1]; //rightmost col
    }
    if(n%2 != 0){
        sum = sum - arr[n/2][n/2];
    }
    cout << sum << "\n";
	return 0;
}
