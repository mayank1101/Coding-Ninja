#include <iostream>
using namespace std;

int clearAllBits(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ans = n & ((1<<i) - 1);
    return ans;
}

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< clearAllBits(n, i) <<endl;
		
	return 0;
}