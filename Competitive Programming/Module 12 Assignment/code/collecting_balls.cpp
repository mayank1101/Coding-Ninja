#include<bits/stdc++.h>
using namespace std;

typedef undefined long long ull;

bool check(ull n, ull k)
{
    ull nball=0; //number of balls picked by sharma;
    ull curr = n;
    while(n > 0){
        nball += min(n,k);
        n -= k;
        n -= (n/10);
    }
    //cout << nball << "\n";
    if(2*nball >= curr){
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n;
    cin>>n;
    ull start=1, end=n; //min and max values of k
    ull ans = n;
    while(start <= end)
    {
        if(start == ans){
            break;
        }
        ull mid = (start + end)>>1;
        if(check(n,mid)){
            ans = mid;
            //cout << mid << "\n";
            end = mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout << ans << "\n";
	return 0;
}
