#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2,s;
	cin>>s1>>s2;
	while(cin>>s);
	int cnt = 0;
	int pos = 0;
	if(s1[0]=='-')s1="?";
	else if(s1[0]=='0')s1="?";
	else if(s1[s1.length()-1]=='.'||s1[0]=='.')s1="?";
	else{
		for(int i=0;i<s1.length();i++){
			if(!(s1[i]>='0'&&s1[i]<='9')){
				cnt++;
				pos = i;
			}
		}
		if(cnt>1)s1="?";
		else if(cnt==1){
			if(s1[pos]=='.'){
			}
			else
				s1="?";
		}
	}
	int f1=0,f2=0;
	if(s1=="?")f1 = 1;
	double a = 0;
	if(!f1&&cnt==0){
		for(int i=0;i<s1.length();i++){
			a = a*10 + (s1[i]-'0');
		}
	}
	else if(!f1&&cnt==1&&s1[pos]=='.'){
		for(int i=0;i<pos;i++){
			a = a*10 + (s1[i]-'0');
		}
		double tem =0;
		for(int i=s1.length()-1;i>pos;i--)
			tem = tem *0.1+(s1[i]-'0')*0.1;
		a+=tem;
	}
	
	cnt = 0;pos = 0;
	if(s2[0]=='-')s2="?";
	else if(s2[0]=='0')s2="?";
	else if(s2[s2.length()-1]=='.'||s2[0]=='.')s2="?";
	else{
		for(int i=0;i<s2.length();i++){
			if(!(s2[i]>='0'&&s2[i]<='9')){
				cnt++;
				pos = i;
			}
		}
		if(cnt>1)s2="?";
		else if(cnt==1){
			if(s2[pos]=='.'){
			}
			else
				s2="?";
		}
	}
	if(s2=="?")f2 = 1;
	double b = 0;
	if(!f2&&cnt==0){
		for(int i=0;i<s2.length();i++){
			b = b*10 + (s2[i]-'0');
		}
	}
	else if(!f2&&cnt==1&&s2[pos]=='.'){
		for(int i=0;i<pos;i++){
			b = b*10 + (s2[i]-'0');
		}
		double tem =0;
		for(int i=s2.length()-1;i>pos;i--)
			tem = tem *0.1+(s2[i]-'0')*0.1;
		b+=tem;
	}
	
	
	if(f1&&f2)
		cout<<"? + ? = ?"<<endl;
	else if(f1&&!f2){
		cout<<"? + "<<b<<" = ?"<<endl;	
	}
	else if(!f1&&f2){
		cout<<a<<" + ? = ?"<<endl;
	}
	else{
		cout<<a<<" + "<<b<<" = "<<a+b<<endl;	
	}
	return 0;
}
