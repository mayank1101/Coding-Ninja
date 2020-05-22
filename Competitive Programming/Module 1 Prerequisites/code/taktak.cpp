#include<bits/stdc++.h>
using namespace std;

bool canDistEqually(int nof)
{
    if((nof%11) == 1){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int nof;
    cin>>nof;
    int nofm=0;
    while(!canDistEqually(nof)){
        nofm++;
        nof = 2*nof;
    }
    cout << nofm << " " << nof << "\n";
    return 0;
}
