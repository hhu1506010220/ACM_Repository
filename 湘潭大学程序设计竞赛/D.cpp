#include <bits/stdc++.h>
using namespace std;
long long f[45];
long long sum[45];
int main(){
    int t,n;
    f[0] = 1;
    sum[0] = 1;
    f[1] = 2;
    sum[1] = 3;
    for(int i=2;i<45;i++){
        f[i] = f[i-1]+f[i-2];
        sum[i] = sum[i-1] + f[i];
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==1){
            printf("%d\n",1);continue;
        }
        long long tem = 0;
        int tt = 44;
        for(int i=tt;i>0;i--){
            if(sum[i]>=n&&sum[i-1]<n){
                tt = i;
            }
        }
        while(n>0){
            if(sum[tt]>=n&&sum[tt-1]<n){
                n -= f[tt];
                tt--;
                tem = tem*2 + 1;
            }else{
                tt--;
                tem = tem*2;
            }
        }
        while(tt>=0){
            tem *= 2;
            tt--;
        }
        printf("%lld\n",tem);
    }
    return 0;
}
