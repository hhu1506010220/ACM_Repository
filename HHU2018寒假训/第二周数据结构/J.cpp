#include<bits/stdc++.h>
using namespace std;

char s[130];
stack<char>st;

int main(){
	int n;
	bool flag = 1;
	while(~scanf("%d",&n)){
		getchar();
		while(n--){
			while(!st.empty())st.pop();
			flag = 1;
			memset(s,0,sizeof(s));
			gets(s);
			int len = strlen(s);
			for(int i=0;i<len;i++){
				if(s[i]=='['||s[i]=='('){
					st.push(s[i]);
				}
				else if(s[i]==']'){
					if(st.empty()||st.top()!='['){
						flag = 0;
						break;	
					}
					else{
						st.pop();	
					}
				}
				else if(s[i]==')'){
					if(st.empty()||st.top()!='('){
						flag = 0;
						break;	
					}
					else{
						st.pop();	
					}
				}
//				cout<<"hhh"<<endl;
			}
			if(flag&&st.empty())puts("Yes");
			else puts("No");
		}
	}
	return 0;	
}
