#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

char s[100005];
int NEXT[100005];

int main(){
	int len;
	int _begin,_end,cur;
	while(~scanf("%s",s+1)){
		memset(NEXT,0,sizeof(NEXT));
		len = strlen(s+1);
		cur = _begin = _end = 0;
		for(int i=1;i<=len;i++){
			if(s[i]=='['){
				cur = _begin;
			}
			else if(s[i]==']'){
				cur = _end;
			}
			else{
				NEXT[i] = NEXT[cur];
				NEXT[cur] = i;
				if(cur == _end){
					_end = i;	
				}
				cur = i;
			}
		}
		for(int i = NEXT[0];i!=0;i=NEXT[i]){
			printf("%c",s[i]);
		}
		puts("");
	}
	return 0;
}
