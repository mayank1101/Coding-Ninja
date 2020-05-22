#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if(size == 0){
        return -1;
    }
    int smallerOutput = lastIndex(input+1, size-1, x);
    if(smallerOutput != -1){
        return smallerOutput+1;
    }
    else{
        if(input[0] == x){
            return 0;
        }
        else{
            return smallerOutput;
        }
    }

}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << lastIndex(input, n, x) << endl;

}
