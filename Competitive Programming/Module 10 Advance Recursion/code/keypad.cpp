#include <bits/stdc++.h>
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


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int smallNum = num/10;
    int smallOutputSize = keypad(smallNum, output);
    int key = num%10;
    string str = mp[key];
    int copies = str.size();
    //create copies
    for(int i=1;i<=copies;i++)
    {
        for(int k=0;k<smallOutputSize;k++)
        {
            output[k+(i)*smallOutputSize] = output[k];
        }
    }
    //smallOutputSize = smallOutputSize * copies;
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<smallOutputSize;j++)
        {
            output[j+(i * smallOutputSize)] = output[j + (i * smallOutputSize)] + str[i];
        }
    }
    return smallOutputSize*copies;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}