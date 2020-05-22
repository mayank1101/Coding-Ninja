#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        int n;
        bool flag = true;
        cin>>n;
        string str="";
        cin>>str;
        map<char, int> mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        for(int i=0;i<str.length();i++)
        {
            if(mp[str[i]] == 1){
                cout << str[i] << "\n";
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "-1\n";
        }
    }
	return 0;
}