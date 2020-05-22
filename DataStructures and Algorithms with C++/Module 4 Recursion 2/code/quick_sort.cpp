#include<iostream>

using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int input[], int start, int end)
{
    int pivot = input[start];
    int i,j;
    i=start, j=start+1;
    for(;j<=end;j++){
        if(input[j] <= pivot){
            i++;
            swap(&input[i], &input[j]);
        }
    }
    swap(&input[i], &input[0]);
    return i;
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    int start,end;
    start = 0, end = size-1;
    if(start >= end){
        return;
    }
    else{
        int pi = partition(input, start, end);
        quickSort(input,pi-start);
        quickSort(input+pi+1, end-pi);
    }
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


