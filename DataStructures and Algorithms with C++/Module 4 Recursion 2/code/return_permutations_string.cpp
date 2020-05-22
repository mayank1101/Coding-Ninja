#include <iostream>
#include <string>

using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input == ""){
        output[0] = "";
        return 1;
    }
    int smallOutput = returnPermutations(input.substr(1), output);
    for(int i=0;i<smallOutput;i++){
        string tmp = output[i];
        for(int j=0;j<=tmp.size();j++){
            tmp.insert(j,1,input[0]);
            output[j*smallOutput+i] = tmp;
            tmp.erase(j,1);
        }
    }
    return smallOutput * output[0].size();
}


using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
