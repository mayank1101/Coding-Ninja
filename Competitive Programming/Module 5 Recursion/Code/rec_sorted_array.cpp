#include<bits/stdc++.h>
using namespace std;

bool isSorted2(int arr[], int n)
{
    if(n == 0 || n == 1){
        return true;
    }
    bool isSmallerSorted = isSorted2(arr+1, n-1);
    if(!isSmallerSorted){
        return false;
    }
    else{ //remaning smaller array is sorted now do comparison
        if(arr[0] > arr [1]){
            return false;
        }
        else{
            return true;
        }
    }
}


bool isSorted1(int arr[], int n)
{
    if(n == 0 || n ==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    bool isSmallerSorted = isSorted1(arr+1, n-1);
    return isSmallerSorted;
}

int main()
{
    int n;
    cin>>n;
    int *arr =new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //recursion method 1
    if(isSorted1(arr,n)){
        cout << "Array is sorted\n";
    }
    else{
        cout << "Array is unsorted\n";
    }

    cout << "Method 2\n";

    //recursion method 2
    if(isSorted2(arr,n)){
        cout << "Array is sorted\n";
    }
    else{
        cout << "Array is unsorted\n";
    }
    return 0;
}
