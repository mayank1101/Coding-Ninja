#include<iostream>
using namespace std;

int allIndexesHelper(int input[], int size, int currIndex, int x, int output[], int k)
{
    if(size == 0){
        return k;
    }
    if(input[currIndex] == x){
        output[k++] = currIndex;
    }
    return allIndexesHelper(input,size,currIndex+1,x,output,k);
}


int allIndexes(int input[], int size, int x, int output[]) {
    int k=0; //keep track of size of output array
    return allIndexesHelper(input,size,0,x,output,0);
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}
