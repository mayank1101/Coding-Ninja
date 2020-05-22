#include<bits/stdc++.h>
using namespace std;

void removeX(char s[])
{
	if(s[0] == '\0'){
		return;
	}
	if(s[0] != 'x'){
		removeX(s+1);
	}
	else{
		int i;
		for(i=1;s[i] != '\0';i++)
		{
			s[i-1] = s[i];
		}
		s[i-1] = s[i];
		removeX(s);
	}
}

int main()
{
	char s[] = "axbxxcd";
	removeX(s);
	cout << s << "\n";
	return 0;
}