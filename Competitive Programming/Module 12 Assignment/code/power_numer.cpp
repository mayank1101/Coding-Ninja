#include<iostream>
using namespace std;

typedef unsigned long long ull;

ull power(int x, int n)
{
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return x;
    }
    int smallpower = n/2;
    ull ans = power(x, smallpower);
    if(n % 2 == 0){
        ans = ans * ans;
        return (ans);
    }
    else{
        ans = ans*ans;
        return (x*ans);
    }
}

int main() {
	// Write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int x,n;
    cin>>x>>n;
    cout << power(x,n) << "\n";
}
