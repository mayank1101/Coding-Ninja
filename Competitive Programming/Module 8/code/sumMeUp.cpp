#include<bits/stdc++.h>
using namespace std;

long sumOfDigits(long n){
    long sum;
    for(sum=0;n>0;sum += n%10, n/=10);
    return sum;
}

int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        long int num;
        cin>>num;
        cout << sumOfDigits(num) << "\n";
    }
}