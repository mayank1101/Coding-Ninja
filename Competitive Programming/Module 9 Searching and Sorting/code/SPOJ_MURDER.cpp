//Murder
#include<bits/stdc++.h>
using namespace std;


long long merge(int A[], int start, int mid, int end)
{
    long long sum=0;
    int i=start,j=mid,k=0;
    int T[end-start+1];
    while(i<=mid-1 && j<=end){
        if(A[i] < A[j]){
            sum += (A[i] * (end-j+1));
            T[k++] = A[i++];
        }
        else{
            T[k++] = A[j++];
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
    return sum;
}

long long mergeSort(int A[], int start, int end)
{
    long long sum=0;
    if(start < end){
        int mid = start + (end-start)/2;
        sum += mergeSort(A,start,mid);
        sum += mergeSort(A,mid+1,end);
        sum += merge(A,start,mid+1,end);
    }
    return sum;
}

int main() {

	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        long long sum = mergeSort(A,0,n-1);
        cout << sum << "\n";
    }
    return 0;
}