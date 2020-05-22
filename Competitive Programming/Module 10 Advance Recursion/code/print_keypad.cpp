#include <iostream>
#include <string>
#include<map>
using namespace std;

map<int,string> mp = {
    {0, ""},
    {1, ""},
    {2, "abc"},
    {3, "def"},
    {4,"ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};


void print_keypad(int num, string output)
{
    if(num == 0 || num == 1){
        cout << output << "\n";
        return;
    }
    int smallNum = num/10;
    int key = num%10;
    string s = mp[key];
    if(key == 2 || key == 3 || key == 4 || key == 5 || key == 6 || key == 8)
    {
        print_keypad(num/10, s[0] + output);
        print_keypad(num/10, s[1] + output);
        print_keypad(num/10, s[2] + output);
    }
    else{
        print_keypad(num/10, s[0] + output);
        print_keypad(num/10, s[1] + output);
        print_keypad(num/10, s[2] + output);
        print_keypad(num/10, s[3] + output);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    print_keypad(num, output);
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
