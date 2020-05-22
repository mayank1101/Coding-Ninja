#include <iostream>
using namespace std;

// arr - input array
// size - size of array
// x - sum of triplets

int max(int a, int b){
    return ((a > b)? a : b);
}

void FindTriplet(int arr[], int size, int x) {
    int ans[3] = {0};
    for(int i=0;i<size-2;i++)
    {
        for(int j=i+1;j<size-1;j++)
        {
            for(int k=j+1;k<size;k++){
                if((arr[i]+arr[j]+arr[k]) == x){
                    // cout << arr[i] << " " << arr[j] << " " << arr[k] <<"\n";
                    int largest = max(arr[i], max(arr[j],arr[k]));
                    int min = -max(-arr[i], max(-arr[j], -arr[k]));
                    int middle = (arr[i]+arr[j]+arr[k]) - (largest + min);
                    cout << min << " " << middle << " " << largest << "\n";
                }
            }
        }
    }
}



int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}

