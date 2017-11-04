#include<bits/stdc++.h>
using namespace std;

int a[15]={0};

int main(){
	char s[20];
	cin>>s+1;
	int cnt = 0;
	int pos = 0;
	for(int i=strlen(s)-1;i>0;i--){
		//cout<<"111"<<endl;
		if(s[i]=='0')cnt++;
		else{
			pos = i;
			break;	
		}
	}
	//cout<<pos<<endl;
	bool flag = 1;
	for(int i=1;i<=pos/2;i++){
		//cout<<s[i]<<" "<<s[pos-i]<<endl;
		if(s[i]!=s[pos-i+1]){
			flag = 0;
			break;	
		}
	}
	if(flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	return 0;
}
