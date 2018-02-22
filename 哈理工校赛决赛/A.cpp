#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
const long long maxn = 1010;
long long a[maxn][2];
long long n;
long long dp[maxn];
 
int main()
{
    while(scanf("%lld",&n)!=EOF){
        for(long long i = 1; i <= n;i ++){
            scanf("%lld%lld",&a[i][0],&a[i][1]);
        }
         
        dp[0] = 1;
        for(int i = 1;i <= n;i ++){
            dp[i] = (((dp[i-1]*a[i][0]) % mod) + ((dp[i-1]*a[i][1] % mod))) % mod;
        }
         
        printf("%lld\n",dp[n]);
    }
    return 0;
}
