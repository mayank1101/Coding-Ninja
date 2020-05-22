#include <iostream>
#include <string.h>
#include<map>

using namespace std;

map<string, char> mp;

void printCodes(string input, string output="")
{
    if(input == ""){
        cout << output << "\n";
        return;
    }
    printCodes(input.substr(1), output + mp[string(1, input[0])] );
    if((input.size() > 1) && stoi(input.substr(0,2)) <= 26){
        printCodes(input.substr(2), output + mp[input.substr(0,2)] );
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    char c='a';
    for(int i=1;i<=26;i++,c++){
        mp[to_string(i)] = c;
    }
    printCodes(input);
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
