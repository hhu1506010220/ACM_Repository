#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<algorithm>  
  
long long dp[3010][3010];  
int a[3010][3010];  
  
int min(int a,int b)  
{  
    return a<b?a:b;  
}  
  
int main()  
{  
    //freopen("in.txt","r",stdin);  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {     
        for(int i=1;i<=n;i++)  
           for(int j=1;j<=m;j++)  
           {  
              scanf("%d",&a[i][j]);  
           }  
        for(int i=2;i<=n;i++)dp[i][0]=1<<30;  
        for(int i=2;i<=m;i++)dp[0][i]=1<<30;  
        dp[0][0]=0;  
        dp[0][1]=0;  
        dp[1][0]=0;  
          
        for(int i=1;i<=n;i++)  
           for(int j=1;j<=m;j++)  
           {  
              dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];  
           }  
        printf("%lld\n",dp[n][m]);    
    }  
}  
