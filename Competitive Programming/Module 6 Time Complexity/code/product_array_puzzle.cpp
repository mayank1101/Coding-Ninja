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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int prod[n] = {0};
        int lp=1, rp=1;
        for(int i=0;i<n;i++)
        {
            prod[i] = lp;
            lp = lp*arr[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            prod[i] = prod[i]*rp;
            rp = rp*arr[i];
        }
        for(int i=0;i<n;i++)
        {
            cout << prod[i] << " ";
        }
        cout << "\n";
    }
	return 0;
}
