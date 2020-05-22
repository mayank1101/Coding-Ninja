//Return all possible subsequences of string
#include<bits/stdc++.h>
using namespace std;

int subseq(string s, string output[])
{
	if(s.empty()){
		output[0] = "";
		return 1;
	}
	string smallString = s.substr(1);
	int smallOutputSize = subseq(smallString,output); //return length of output array for smallString
	for(int i=0;i<smallOutputSize;i++)
	{
		output[i+smallOutputSize] = s[0] + output[i];
	}
	return (2*smallOutputSize);
}

int main()
{
	string s;
	cin>>s;
	string* output = new string[100001];
	int size = subseq(s, output);
	for(int i=0;i<size;i++)
	{
		cout << output[i] << "\n";
	}
}