#include <iostream>

using namespace std;


void merge(int input[], int start, int mid, int end)
{
    int n1,n2,i,j,k; 
    n1 = mid-start+1;
    n2 = end-mid;
    int left[n1], right[n2];
    for(int i=0;i<n1;i++){
        left[i] = input[start+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = input[mid+1+j];
    }
    i = j = 0;
    k = start;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            input[k++] = left[i++];
        }
        else{
            input[k++] = right[j++];
        }
    }
    
    while(i < n1){
        input[k++] = left[i++];
    }
    
    while(j < n2){
        input[k++] = right[j++];
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    int start,end;
    start = 0, end = size-1;
    if(start >= end){ //empty array or array with one element
        return;
    }
    else{
        int mid = start + (end-start)/2;
        mergeSort(input,mid-start+1);
        mergeSort(input+mid+1,end-mid);
        merge(input,start,mid,end);
    }
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
