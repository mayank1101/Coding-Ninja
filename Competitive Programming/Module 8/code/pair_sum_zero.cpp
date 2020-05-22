//Pair Sum 0
#include<iostream>
using namespace std;

void PairSum(int *input, int n) {	 
	for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((input[j] + input[i]) == 0){
                    int bigger = (input[i] > input[j])? input[i]: input[j];
                    int smaller = (input[i] < input[j])? input[i]: input[j];
                    cout << smaller << " " << bigger << "\n";
                }
            }
        }
 }



int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}

