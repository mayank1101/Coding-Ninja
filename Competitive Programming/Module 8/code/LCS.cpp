//Longest Consecutive Subsequence
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    vector<int> ans;
    if(n == 1)
    {
        ans.push_back(arr[0]);
        return ans;
    }
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1) == s.end())
        {
            int curr_element = arr[i]; //starting element
            vector<int> tmp;
            tmp.push_back(i);
            while(s.find(curr_element) != s.end())
            {
                tmp.push_back(curr_element);
                curr_element++;
            }
            if((curr_element - arr[i]) > max_len){
                max_len = curr_element - arr[i];
                ans.clear();
                ans = tmp;
            }
            else if(((curr_element - arr[i]) == max_len) && (ans[0] > tmp[0])){
                //max_len = max(max_len, curr_element - arr[i]);
                ans.clear();
                ans = tmp;
            }
            tmp.clear();
        }
    }
    ans.erase(ans.begin());
    return ans;
}