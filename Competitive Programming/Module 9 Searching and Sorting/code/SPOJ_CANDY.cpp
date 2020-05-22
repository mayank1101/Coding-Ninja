//MAIN8_C - Shake Shake Shaky
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long ul;


bool check(vector<ul>& A, ul ncandies, ul k)
{
    ul cnt=0;
    for(ul i=0;i<A.size();i++){
        ul nstudents = floor((double)A[i]/(double)ncandies);
        cnt += nstudents;
        if(cnt >= k){
            return true;
        }
    }
    return false;
}

int main() {

	// Write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ul n,k,ncandy;
        cin>>n>>k;
        vector<ul> box;
        for(ul i=0;i<n;i++){
            cin>>ncandy;
            box.push_back(ncandy);
        }
        //sort(box.begin(),box.end());
        ul start = 0; //min number of candies a student can have
        vector<ul>::iterator it;
        it = max_element(box.begin(), box.end());
        ul end = *(it); //max candies a student can have
        ul ans = 0;
        if(k == 1){
            ans = end;
        }
        else if(k > accumulate(box.begin(), box.end(), 0)){
            ans = 0;
        }
        else{
            while(start <= end){
                ul mid = start + (end-start)/2;
                if(check(box,mid,k)){
                    ans=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}