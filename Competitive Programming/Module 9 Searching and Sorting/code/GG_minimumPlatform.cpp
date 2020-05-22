#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,input;
        cin>>n;
        multimap<int,char> time;
        for(int i=0;i<n;i++){
            cin>>input;
            time.insert({input, 'a'});
        }
        for(int i=0;i<n;i++){
            cin>>input;
            time.insert({input, 'd'});
        }
        int num_plt=0, ans=0;
        multimap<int,char>::iterator it;
        for(it=time.begin();it!=time.end();it++){
            if(it->second == 'a'){
                num_plt++;
            }
            else{
                num_plt--;
            }
            if(num_plt > ans){
                ans = num_plt;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}