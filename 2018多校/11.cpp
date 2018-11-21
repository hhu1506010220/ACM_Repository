#include<bits/stdc++.h>
using namespace std;

bool judge_num(char s){//数字返回1
	if(s>='0'&&s<='9')
		return 1;
	else 
		return 0;
}

bool judge_sig(char s){//+*返回1
	if(s=='+'||s=='*')
		return 1;
	else 
		return 0;
}

int main() {
	string s;
	int t;
	scanf("%d",&t);
	while(t--) {
		int flag=1;
		cin>>s;
		int len=s.length();
		if(judge_sig(s[0])) {
			flag = 0;
		}
		else if(s[0]=='0'&&len>1) {
			if(judge_num(s[1])) {
				flag = 0;
			}
			else if(s[1]=='?')
				s[1]='+';
		}
		for(int i=0;i<len&&s[i]; i++) {
			if(!flag)break;
			//如果是末尾或者下一位是符号 置为数字 
			if(s[i]=='?'&&(i==len-1||judge_sig(s[i+1])))
				s[i]=='1';
			//如果是符号 
			if(judge_sig(s[i])) {
				if(i==len-1) {
					flag=0;
					break;
				}
				if(judge_sig(s[i+1])) {
					flag=0;
					break;
				}
				if(s[i+1]=='0'&&i<len-1) {
					if(judge_num(s[i+2])) {
						flag=0;
						break;
					}
					if(s[i+2]=='?')
						s[i+2]='+';
				}
			}
		}
		if(flag) {
			for(int i=0;i<len&&s[i]; i++)
				if(s[i]=='?')s[i]='1';
			cout<<s<<endl;
		}
		else{
			puts("IMPOSSIBLE");	
		}	
	}
	return 0;
}

