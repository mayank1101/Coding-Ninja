#include <iostream>
using namespace std;

#include<string>


void printSSKHelper(int input[], int n, int k, string ans=""){
    if(n == 0){
        if(k == 0){
            cout << ans << "\n";
            return;
        }
        return;
    }
    printSSKHelper(input+1,n-1,k-input[0],ans+to_string(input[0])+" ");
    printSSKHelper(input+1,n-1,k,ans);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    printSSKHelper(input, size, k);
}



int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
