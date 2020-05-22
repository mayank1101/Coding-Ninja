//Anagram Palindrome (GFG)
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    vector<char> list;
    vector<char>::iterator it;
    for(int i=0;i<s.length();i++){
        it = find(list.begin(), list.end(), s[i]);
        if(it != list.end()){
            //int index_char = it - list.begin();
            list.erase(it);
        }
        else{
            list.push_back(s[i]);
        }
    }
    if((s.length()%2==0 && list.empty() || (s.length()%2==1 && list.size() == 1))){
        return true;
    }
    else{
        return false;
    }
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
        string s = "";
        getline(cin,s);
        if(isPalindrome(s)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
	return 0;
}