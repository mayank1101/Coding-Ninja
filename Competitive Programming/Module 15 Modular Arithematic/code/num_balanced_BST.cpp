#include <iostream>
#include <cmath>
using namespace std;

#define N 1000000007

int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    if(h == 0 || h == 1){
        return 1;
    }
    long long x = balancedBTs(h-1) % N;
    long long y = balancedBTs(h-2) % N;
    long long res1 = (long long)((x % N) * (x % N)) % N;
    long long res2 = (long long)(((2*x) % N) * (y % N )) % N;
    long long ans = (long long)((res1 % N) + (res2 % N)) % N;
    return ans;
}


int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
