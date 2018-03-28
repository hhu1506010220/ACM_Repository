#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[100];
	string ss[100];
	cin>>s;
	int len = strlen(s);
	if(s[0]=='-'){
		ss[0] = "fu";	
		for(int i=1;i<len;i++){
			if(s[i]=='0')ss[i]="ling";
			else if(s[i]=='1')ss[i]="yi";
			else if(s[i]=='2')ss[i]="er";
			else if(s[i]=='3')ss[i]="san";
			else if(s[i]=='4')ss[i]="si";
			else if(s[i]=='5')ss[i]="wu";
			else if(s[i]=='6')ss[i]="liu";
			else if(s[i]=='7')ss[i]="qi";
			else if(s[i]=='8')ss[i]="ba";
			else if(s[i]=='9')ss[i]="jiu";
		}
	}
	else{
		for(int i=0;i<len;i++){
			if(s[i]=='0')ss[i]="ling";
			else if(s[i]=='1')ss[i]="yi";
			else if(s[i]=='2')ss[i]="er";
			else if(s[i]=='3')ss[i]="san";
			else if(s[i]=='4')ss[i]="si";
			else if(s[i]=='5')ss[i]="wu";
			else if(s[i]=='6')ss[i]="liu";
			else if(s[i]=='7')ss[i]="qi";
			else if(s[i]=='8')ss[i]="ba";
			else if(s[i]=='9')ss[i]="jiu";
		}
	}
	for(int i=0;i<len;i++){
		cout<<ss[i];
		if(i!=len-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
