#include<bits/stdc++.h> 
using namespace std ; 

char s[105];

int main(){
	int n;
	cin>>s;
	n = strlen(s);
	int cnt =0,cnt1=0;
	for(int i=n-1; i>=0;i--){
		if(s[i]=='0')cnt++;
		if(cnt>=6&&s[i]=='1')cnt1++;
	}
	if(cnt1)puts("yes");
	else puts("no");
	
	
	return 0;
}	
