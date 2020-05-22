#include <iostream>
using namespace std;


void printSubsetsHelper(int input[], int size, int start,int output[], int outSize)
{
    if(start == size){
        for(int i=0;i<outSize;i++){
            cout << output[i] << " ";
        }
        cout << "\n";
        return;
    }
    printSubsetsHelper(input,size,start+1,output,outSize);
    int i;
    int *newOutput =  new int[outSize+1];
    for(i=0;i<outSize;i++){
        newOutput[i] = output[i];
    }
    newOutput[i] = input[start];
    printSubsetsHelper(input,size,start+1,newOutput,outSize+1);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int *output = new int[1000];
    printSubsetsHelper(input,size,0,output,0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
