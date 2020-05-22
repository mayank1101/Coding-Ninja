#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y;
	cin>>n;
	int *height = new int[10000001];
	memset(height,0,sizeof(height));
	int max_x=0;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if((x/2) > y){	// for every x store max height
			height[x/2] = y;
		}
		if((x/2) > max_x){	//	we need to get extreme x coordinate.
			max_x = x/2;
		}
	}
	long long area = height[max_x];
	for(int i=max_x-1;i>0;i--){	//calulate area from max_x to 0 and double the area to get final area of colored region
		if(height[i] < height[i+1]){
			height[i] = height[i+1];
		}
		area += height[i];
	}
	area = 2*area;
	cout << area << "\n";
	return 0;
}