#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

char s[10000+5];
char t[10000+5]; 
//int dp[1005][1005]; //¶þÎ¬
int dp[10005];  //Ò»Î¬ 

int main(){
 	while(~scanf("%s%s",&s,&t)){
 		memset(dp,0,sizeof(dp));
 		int len1=strlen(s);
 		int len2=strlen(t);
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				if(s[i]==t[j]){
					dp[j+1]=dp[j]+1;
				}
				else{
					dp[j+1]=max(dp[j],dp[j+1]);
				}
			}
		}
 		printf("%d\n",dp[len2]);
	}
	return 0;	
}
