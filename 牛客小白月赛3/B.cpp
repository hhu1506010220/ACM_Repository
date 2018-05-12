#include<bits/stdc++.h>
#define ll long long
const ll mod = 2000120420010122;
using namespace std;

char s[200005];
int main(){
	char t[6];
	for(int i=0;i<=3;i++){
		if(i==0)t[i]='c';
		else if(i==1)t[i]='w';
		else if(i==2)t[i]='b';
		else t[i]='c';	
	}
	while(cin>>s){
		int len = strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]>='A'&&s[i]<='Z'){
				s[i] = s[i]-'A'+'a';
			}
		}
		ll dp[5][200005];
        if(len<4){
			puts("0");
			continue;	
		}
//		cout<<t+1<<endl;
//		cout<<len<<" "<<s+1<<endl;
        dp[0][0]=1;
        for(int i=1;i<=4;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=len;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=len;j++){
                dp[i][j]=dp[i][j-1];
                if(t[i-1]==s[j-1])
                    dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
        cout<<dp[4][len]<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}
