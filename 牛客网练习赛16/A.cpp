#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[100005];
	cin>>s;
	int len = strlen(s);
	char ans[100005];
	int cnt = 0;
	char tem = s[len-1];
//	cout<<tem<<endl;
	ans[0] = tem;
	cnt++;
	for(int i=len-2;i>=0;i--){
		if(s[i]>=tem){
//			cout<<tem<<endl; 
			ans[cnt++] = s[i];
			tem = s[i];	
		}
	}
	for(int i=cnt-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
