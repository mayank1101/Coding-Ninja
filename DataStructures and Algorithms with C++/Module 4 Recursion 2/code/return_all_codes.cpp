#include <iostream>
#include <string.h>
#include<map>
using namespace std;

map<string, char> mp;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    char c = 'a';
    for(int i=1;i<=26;i++,c++)
    {
        mp[to_string(i)] = c;
    }
    
    if(input == ""){
        output[0] = "";
        return 1;
    }
    int smallOutput1 = getCodes(input.substr(1),output);
    int smallOutput2=0;
    if(input.size()>1 && stoi(input.substr(0,2)) <= 26){
        smallOutput2 = getCodes(input.substr(2), output+smallOutput1);
    }
    int oSize = smallOutput1 + smallOutput2;
    for(int i=0;i<smallOutput1;i++){
        output[i] = mp[input.substr(0,1)] + output[i];
    }
    
    for(int i=smallOutput1;i<oSize;i++)
    {
        output[i] = mp[input.substr(0,2)] + output[i];
    }
    return oSize;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
