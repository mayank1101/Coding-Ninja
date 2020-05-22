#include <bits/stdc++.h>
using namespace std;

int main() {
    int r;
    cin>>r;
    int cs1=0, cs2=0;
    int max_lead = -1;
    int max_lead_player = -1;
    while(r--)
    {
        int p1,p2;
        cin>>p1>>p2;
        cs1 += p1;
        cs2 += p2;
        int curr_lead=0;
        int curr_lead_player = 1;
        if(cs1 >= cs2){
            curr_lead = cs1-cs2;
        }
        else{
            curr_lead = cs2-cs1;
            curr_lead_player = 2;
        }
        if(curr_lead > max_lead){
            max_lead = curr_lead;
            max_lead_player = curr_lead_player;
        }
    }
    cout << max_lead_player << " " << max_lead << "\n";
	return 0;
}
