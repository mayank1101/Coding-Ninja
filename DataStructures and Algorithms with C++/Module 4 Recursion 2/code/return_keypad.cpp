#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

string getString(int num)
{
    switch(num){
        case 2:
            return "abc";
        case 3:
            return "def";
        case 4:
            return "ghi";
        case 5:
            return "jkl";
        case 6:
            return "mno";
        case 7:
            return "pqrs";
        case 8:
            return "tuv";
        case 9:
            return "wxyz";
        default:
            return "";
    }
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int lastDigit =  num % 10;
    int smallProblem = num/10;
    int smallOutSize = keypad(smallProblem, output);
    string possibleChar = getString(lastDigit);
    //increase the output array
    for(int i=0;i<possibleChar.length()-1;i++){ //how many copies of output array
        for(int j=0;j<smallOutSize;j++){ //iterate over output array
            output[j + (i+1)*smallOutSize] = output[j];
        }
    }
    int k=0; //iterate over the output array
    for(int i=0;i<possibleChar.length();i++){ //pick possible character one by one
        for(int j=0;j<smallOutSize;j++){ // iterate over output array
            output[k] = output[k]+ possibleChar[i];
            k++; //index to resultant output array
        }
    }
    return (smallOutSize * possibleChar.length());
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
