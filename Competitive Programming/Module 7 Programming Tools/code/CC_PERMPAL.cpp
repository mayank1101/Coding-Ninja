#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
	return (char)(i+97);
}

void printPermutation(string s)
{
	map<char, vector<int>> mp;
	for(int i=0;i<s.length();i++){
		mp[s[i]].push_back(i);
	}
	int cnt_odd=0;
	for(int i=0;i<26;i++){
		if(mp[getChar(i)].size() & 1){
			cnt_odd++;
		}
	}
	if(cnt_odd > 1){
		cout << "-1";
		return;
	}
	int ans[s.length()];
	int start=0, end=s.length()-1;
	for(int i=0;i<26;i++){
	    char curr_char = getChar(i);
		for(int j=0;j<mp[curr_char].size();j+=2){
		    
			if((mp[curr_char].size() - j) == 1){ //placing odd length char at the center
				ans[s.length()/2] = mp[curr_char][j];
				continue;
			}
			ans[start] = mp[curr_char][j];
			ans[end] = mp[curr_char][j+1];
			start++;
			end--;
		}
	}
	for(int i=0;i<s.length();i++){
		cout << (ans[i] + 1) << " ";
	}
	return;
}


int main()
{
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
    	string s="";
    	getline(cin,s);
    	printPermutation(s);
    	cout << "\n";
    }
	return 0;
}