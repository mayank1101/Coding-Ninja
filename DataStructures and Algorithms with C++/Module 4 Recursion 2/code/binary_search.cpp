#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int BS(int input[], int start, int end, int element)
{
    if(start <= end)
    {
        int mid = start + (end-start)/2;
        if(input[mid] == element){
            return mid;
        }
        if(input[mid] < element){
            return BS(input,mid+1,end,element);
        }
        else{
            return BS(input,start,mid-1,element);
        }
    }
    return -1;
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    BS(input,0,size-1,element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
