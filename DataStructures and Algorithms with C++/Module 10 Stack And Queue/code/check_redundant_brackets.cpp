#include <iostream>
using namespace std;

#include<stack>

bool checkRedundantBrackets(char *input) {
	// Write your code here
    stack<char> s;
    while(*input != '\0')
    {
        if(*input == ')')
        {
            char c = s.top();
            s.pop();
            int cnt=0;
            while(c != '('){
                cnt++;
                c = s.top();
                s.pop();
            }
            if(cnt < 1){
                return 1;
            }
        }
        else{
            s.push(*input);
        }
        input++;
    }
    return 0;
}


int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
