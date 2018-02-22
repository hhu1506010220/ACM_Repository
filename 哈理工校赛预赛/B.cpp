#include<bits/stdc++.h>
using namespace std;

char s[100005]; 

int main(){
	int t;
	long long sum;
	scanf("%d",&t);
	while(t--){
		sum = 0;
		memset(s,0,sizeof(s));
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			sum+=(s[i]-'A'+1); 
		}
		printf("%lld\n",sum);
	}	
	return 0;	
}
