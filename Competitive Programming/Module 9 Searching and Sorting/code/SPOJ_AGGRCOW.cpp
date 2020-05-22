#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


bool check(int ncows, vector<ll>& pos, int n, ll dist)
{
    ll last_pos = pos[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if((pos[i] - last_pos) >= dist){
            last_pos = pos[i];
                cnt++;
        }
        if(cnt == ncows){
            return true;
        }
    }
    return false;
}

int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,input;
        cin>>n>>c;
        vector<ll> pos;
        for(int i=0;i<n;i++){
            cin>>input;
            pos.push_back(input);
        }
        sort(pos.begin(), pos.end());
        ll start = 0;
        ll end = pos[n-1] - pos[0];
        ll ans=-1;
        while(start <= end){
            ll mid = start + (end-start)/2;
            if(check(c,pos,n,mid))
            {
                ans=mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        cout << ans << "\n";
    }
}