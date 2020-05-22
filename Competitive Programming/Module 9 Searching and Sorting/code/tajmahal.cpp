//CodeZen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,people,k;
    cin>>n;
    vector<long> A;
    for(long i=0;i<n;i++)
    {
        cin>>people;
        people -= i;
        if((people) < 0){
            people = 0;
        }
        k = floor(people/n);
        if((people%n) != 0){
            k = k + 1;
        }
        A.push_back((i+k*n));
    }
    int pos = min_element(A.begin(), A.end()) - A.begin();
    cout << pos+1 << "\n";
	return 0;
}
