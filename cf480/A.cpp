#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int cnt1 = 0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='-')cnt1++;
	int cnt2 = s.length()-cnt1;
	if(cnt2==0)puts("YES");
	else if(cnt1%cnt2==0)
		puts("YES");
	else 
		puts("NO");
	return 0;	
}
