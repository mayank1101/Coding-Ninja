#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,groups=0;
    long x,y;
    cin>>n>>x>>y;
    string s="";
    cin>>s;
    if(s[0] == '0'){
        groups++;
    }
    for(int i=1;i<s.length();i++)
    {
        if(s[i] == '0' && s[i-1] == '1'){
            groups++;
        }
    }
    //cout << groups << "\n";
    long ans;
    if(groups == 0){
        ans = 0;
    }
    else{
        ans = (groups-1)* min(x,y) + y;
    }
    cout << ans << "\n";
	return 0;
}
