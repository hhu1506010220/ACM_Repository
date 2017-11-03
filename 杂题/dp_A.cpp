#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 16
#define M 1<<N
#define MOD 100000000
int mp[M];//记录每一行中，不能种植的就将状态记为1
int state[M];//记录1<<m中不与别的数相邻的所有状态
int dp[N][M];
bool judge(int x){
    return x&(x<<1);
}
bool judge2(int i,int j){
    return mp[i]&state[j];
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2){

        memset(mp,0,sizeof(mp));
        memset(state,0,sizeof(state));
        memset(dp,0,sizeof(dp));
            
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x;
                scanf("%d",&x);
                if(x==0){
                    mp[i]+=(1<<(j-1));
                }
            }
        }

        int k=0;
        for(int i=0;i<(1<<m);i++){
            if(judge(i)==0){
                state[k++]=i;
            }
        }

        for(int i=0;i<k;i++){
            if(judge2(1,i)==0){
                dp[1][i]=1;
            }
        }

        for(int i=2;i<=n;i++){
            for(int j=0;j<k;j++){
                if(judge2(i,j)) continue;
                for(int l=0;l<k;l++){
                    if(judge2(i-1,l)) continue;
                    if((state[j]&state[l])==0){
                        dp[i][j]+=dp[i-1][l];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=ans+dp[n][i];
            ans%=MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
