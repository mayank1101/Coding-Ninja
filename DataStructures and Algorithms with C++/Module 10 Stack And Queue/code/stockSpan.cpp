#include <iostream>
using namespace std;


#include<stack>

int* stockSpan(int *price, int size) {
    // Write your code here
    int *span = new int[size];
    stack<int> s;
    s.push(0); //push 0th day
    span[0] = 1;
    for(int i=1;i<size;i++)
    {
        while(s.empty() == false && price[s.top()] < price[i]){
            s.pop();
        }
        span[i] = (s.empty()) ? (i+1) : (i - s.top());
        s.push(i); //push ith day
    }
    return span;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
