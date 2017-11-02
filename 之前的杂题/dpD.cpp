#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int dp[10005][105];
int a[10005];
int mod(int n, int k){
    n=n%k;
    while(n<0) n=n+k;
    return n;
}
int main(){
    scanf("%d%d",&n,&k);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[1][mod(a[1],k)]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<k;j++){
            if(dp[i-1][j]){
                dp[i][mod(j+a[i],k)]=1;
                dp[i][mod(j-a[i],k)]=1;
            }
        }
    }
    if(dp[n][0]) puts("Divisible");
    else puts("not divisible");
    return 0;
}
