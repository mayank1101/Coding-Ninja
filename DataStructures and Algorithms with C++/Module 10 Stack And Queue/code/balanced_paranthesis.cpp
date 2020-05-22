#include <iostream>
using namespace std;


#include<stack>

bool checkBalanced(char *exp) {
	// Write your code here
    stack<char> s;
    char c;
    int n = sizeof(exp)/sizeof(exp[0]);
    while(*exp != '\0')
    {
        if(*exp == '(' || *exp == '[' || *exp == '{')
        {
            s.push(*exp);
            ++exp;
            continue;
        }
        switch(*exp)
        {
            case ')':
                if(s.empty())
                {
                    return false;
                }
                c = s.top();
                s.pop();
                if(c == '{' || c =='['){
                    return false;
                }
                break;
                
            case ']':
                if(s.empty())
                {
                    return false;
                }
                c = s.top();
                s.pop();
                if(c == '(' || c == '{'){
                    return false;
                }
                break;
                
            case '}':
                if(s.empty())
                {
                    return false;
                }
                c = s.top();
                s.pop();
                if(c == '(' || c == '['){
                    return false;
                }
                break;
        }
        ++exp;
    }
    return s.empty();
}


int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
