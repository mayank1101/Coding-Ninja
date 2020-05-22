#include <iostream>
using namespace std;
#include<bits/stdc++.h>



int countBracketReversals(char input[]){
	// Write your code here
    int cnt=0,i=0;
    
    while(input[i++] != '\0'){
        cnt++;
    }
    
    if(cnt % 2 != 0){
        return -1;
    }

    stack<char> s;
    for(int i=0;input[i] != '\0';i++)
    {
        if(input[i] == '}' && s.empty() == false)
        {
            if(s.top() == '{'){
                s.pop();
            }
            else{
                s.push(input[i]);
            }
        }
        else{
            s.push(input[i]);
        }
    }
    char c1,c2;
    int min_cnt=0;
    while(s.empty() == false){
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if(c1 == c2){ //if both are open brackets reverse one bracket
            min_cnt += 1;
        }
        else{ //one is closed bracket and other is open bracket, we need to reverse both
            min_cnt += 2;
        }
    }
    return min_cnt;
}



int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}