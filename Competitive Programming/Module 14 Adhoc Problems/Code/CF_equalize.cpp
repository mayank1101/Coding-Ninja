//Codeforces Equalize
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>b;
	int cost=0;
	for(int i=0;i<a.length();)
	{
	    if(a[i] != b[i]){
	        if((i+1 != a.length()) && (a[i] != a[i+1]) && (a[i+1] != b[i+1])){
	            swap(a[i],a[i+1]);
	            cost++;
	            i += 2;
	        }
	        else{
	            if(a[i] == 0){
	                a[i] = 1;
	            }
	            else{
	                a[i] = 0;
	            }
	            cost++;
	            i += 1;
	        }
	    }
	    else{
	        i++;
	    }
	}
	cout << cost << "\n";
	return 0;
}
