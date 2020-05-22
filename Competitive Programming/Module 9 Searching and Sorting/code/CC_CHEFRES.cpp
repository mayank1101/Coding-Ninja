#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		long long start,end;
		cin>>n>>m;
		vector<pair<long, long>> interval;
		for(int i=0;i<n;i++){
			cin>>start>>end;
			interval.push_back(make_pair(start,end));
		}
		sort(interval.begin(), interval.end());
		long arrival_time=0;
		while(m--){
			cin>>arrival_time;
			int index = lower_bound(interval.begin(), interval.end(), make_pair(arrival_time,long(0))) - interval.begin();
			if(index == 0){
				cout << interval[index].first - arrival_time << "\n"; //person arrive before start time of first interval
			}
			else{
				long ans = -1;
				if(arrival_time <  interval[index-1].second){ //person arrived when restraunt was open
					ans = 0;
				}
				else if(index < interval.size()){
					ans = interval[index].first - arrival_time; //person arrived before restraunt was open
				}
				else{
					ans = -1; //person arrived beyond end time of last interval
				}
				cout << ans << "\n";
			}
		}
	}
}