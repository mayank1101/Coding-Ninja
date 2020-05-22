#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,emp_skill;
        cin>>n;
        vector<int> skills;
        for(int i=0;i<n;i++)
        {
            cin>>emp_skill;
            skills.push_back(emp_skill);
        }
        vector<int> T;
        T = skills;
        sort(T.begin(),T.end());
        for(int i=0;i<n-1;i++)
        {
            if(skills[i+1] == (skills[i]-1)){
                swap(skills[i+1],skills[i]);
            }
        }
        if(T == skills){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        cout << "\n";
    }
	return 0;
}
