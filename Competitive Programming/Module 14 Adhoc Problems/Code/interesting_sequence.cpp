#include<bits/stdc++.h>
using namespace std;
int main() {
    
	// Write your code here
    int n,k,i,num,min_cost=INT_MAX;
    cin>>n>>k>>i;
    vector<int> seq;
    for(int i=0;i<n;i++){
        cin>>num;
        seq.push_back(num);
    }
    vector<int>::iterator it1,it2;
    it1 = min_element(seq.begin(), seq.end());
    it2 = max_element(seq.begin(), seq.end());
    if(*it1 == *it2){
        min_cost = 0;
    }
    else{
        int min = *it1;
        int max = *it2;
        int curr = min;
        //cout << "curr " << curr << "\n";
        while(curr <= max){
            int inc_cost =0, dec_cost=0;
            for(int i=0;i<n;i++){
                if(seq[i] <= curr){
                    inc_cost += (curr - seq[i]);
                }
                else{
                    dec_cost += (seq[i] - curr);
                    //cout << "dec_cost " << dec_cost << "\n";
                }
            }
            if(dec_cost > inc_cost){
                curr++;
                continue;
            }
            int total_cost = (dec_cost * k) + ((inc_cost - dec_cost) * i);
            if(total_cost < min_cost){
                min_cost = total_cost;
            }
            curr++;
        }
    }
    cout << min_cost << "\n";
    return 0;
}