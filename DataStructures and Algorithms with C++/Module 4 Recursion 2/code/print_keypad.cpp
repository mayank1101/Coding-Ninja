#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string getPossibleChar(string input)
{
    if(input == "2"){
        return "abc";
    }
    if(input == "3"){
        return "def";
    }
    if(input == "4"){
        return "ghi";
    }
    if(input == "5"){
        return "jkl";
    }
    if(input == "6"){
        return "mno";
    }
    if(input == "7"){
        return "pqrs";
    }
    if(input == "8"){
        return "tuv";
    }
    if(input == "9"){
        return "wxyz";
    }
}

void printKeypadNew(string input, string output)
{
    if(input.empty()){
        cout << output << "\n";
        return;
    }
    string possibleChar = getPossibleChar(input.substr(input.length()-1,1));
    for(int i=0;i<possibleChar.length();i++)
    {
        printKeypadNew(input.substr(0,input.length()-1),possibleChar[i]+output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string input = to_string(num);
    string output = "";
    printKeypadNew(input,output); 
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
