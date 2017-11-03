#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50005
#define INF 0x3f3f3f3f
#define LL long long
LL dp[N][2];
struct node
{
    LL x,c;
}s[N];
int cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%lld %lld",&s[i].x,&s[i].c);
        sort(s+1,s+n+1,cmp);
        memset(dp,0,sizeof(dp));
        dp[1][1] = s[1].c;
        dp[1][0] = INF;
        for(int i=2;i<=n;i++)
        {
            dp[i][1] = min(dp[i-1][1],dp[i-1][0])+s[i].c;
            LL sum=0;
            dp[i][0] = INF;
            for(int j=i-1;j>=1;j--)
            {
                sum+=(i-j)*(s[j+1].x-s[j].x);
                dp[i][0] = min(dp[i][0],dp[j][1]+sum);
            }
        }
        printf("%lld\n",min(dp[n][1],dp[n][0]));
    }
    return 0;
}
