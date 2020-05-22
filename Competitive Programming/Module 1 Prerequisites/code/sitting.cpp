#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("sitin.txt", "r", stdin);
    freopen("sitout.txt", "w", stdout);

    int r,c;
    cin>>r>>c;
    int nos = r*c;
    int tickets;
    cin>>tickets;
    if(nos >= tickets){
        cout << tickets << " " << 0 << "\n";
    }
    else{
        cout << nos << " " << (tickets - nos) << "\n";
    }
    return 0;
}
