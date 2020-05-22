#include <iostream>
using namespace std;


/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
  {{2, 1, 4}, // Length of this subset is 2
  {2, 3, 2}}  // Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumHelper(int input[], int n, int start, int output[][50], int k)
{
    if(start == n){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }
    int output1[10000][50], output2[10000][50];
    //do not include start element
    int size1 = subsetSumHelper(input,n,start+1,output1,k);
    //include the start element
    int size2 = subsetSumHelper(input,n,start+1,output2,k-input[start]);
    
    //copy output1 subsets that sum k to output array
    int row = 0; //keep track of rows in output array
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<=output1[i][0];j++){
            output[row][j] = output1[i][j];
        }
        row++;
    }
    //copy output2 subsets that sum k including start element
    for(int i=0;i<size2;i++) //iterate over number of rows in ouput2 array
    {
        output[row][0] = output2[i][0] + 1;
        output[row][1] = input[start];
        for(int j=1;j<=output2[i][0];j++)
        {
            output[row][j+1] = output2[i][j];
        }
        row++;
    }
    return row;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    subsetSumHelper(input,n,0,output,k);
}



int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
