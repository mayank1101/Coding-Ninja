#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long merge(int A[],  int start, int mid, int end)
{
    int i=start,j=mid,k=0;
    int T[end-start+1];
    long long inv_cnt=0;
    while(i <= mid-1 && j <= end){
        if(A[i] <= A[j]){
            T[k++] = A[i++];
        }
        else{
            T[k++] = A[j++];
            inv_cnt += (mid-i);
        }
    }
    while(i <= mid-1){
        T[k++] = A[i++];
    }
    while(j <= end){
        T[k++] = A[j++];
    }
    for(int i=start,k=0;i<=end;i++,k++){
        A[i] = T[k];
    }
    return inv_cnt;
}


long long mergeSort(int A[], int start, int end)
{
    long long inv_cnt=0;
    if(start < end){
        int mid = start + (end-start)/2;
        inv_cnt += mergeSort(A, start, mid);
        inv_cnt += mergeSort(A, mid+1, end);
        inv_cnt += merge(A, start, mid+1, end); //right subarray start index
        //return inv_cnt;
    }
    return inv_cnt;
}


long long solve(int A[], int n)
{
	// Write your code here.
    long long ans =  mergeSort(A,0,n-1);
    return ans;
}

int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}