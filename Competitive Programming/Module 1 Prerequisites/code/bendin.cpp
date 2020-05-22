#include<bits/stdc++.h>
using namespace std;

struct rec{
    int x1,y1;
    int x2,y2;
};

typedef struct rec REC;

int main()
{
    freopen("benin.txt", "r", stdin);
    freopen("bendout.txt", "w", stdout);

    REC r1,r2;
    cin>>r1.x1>>r1.y1>>r1.x2>>r1.y2;
    cin>>r2.x1>>r2.y1>>r2.x2>>r2.y2;
    int A1 = (r1.x2 - r1.x1) * (r1.y2 - r1.y1);
    int A2 = (r2.x2 - r2.x1) * (r2.y2 - r2.y1);
    int AI = 0;
    int BLx = max(r1.x1, r2.x1);
    int BLy = max(r1.y1, r2.y1);
    int TRx = min(r1.x2, r2.x2);
    int TRy = min(r1.y2, r2.y2);
    if((BLx < TRx) && (BLy < TRy)){
        AI = (TRx - BLx) * (TRy - BLy);
        cout << A1+A2+AI << "\n";
    }
    else{
        cout << A1+A2+AI << "\n";
    }
    return 0;
}
