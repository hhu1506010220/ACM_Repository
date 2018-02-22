#include<bits/stdc++.h>
using namespace std;
 
const long long maxn = 1e6 + 10;
char s[maxn];
long long tmpl, tmpr, k;
 
void cmpS(long long l, long long r)
{
    for(long long i = l,j = tmpl;i <= r && j <= tmpr;i++, j++){  
        if(s[i] > s[j]){
            tmpl = l;
            tmpr = r;
            break;
        }
        if(s[i] < s[j]){
            break;
        }
    }
     
    return ;
}
 
long long poww(long long  x,long long y)
{
    if(y == 0){
        return 1;
    }
    return 2 * poww(2, y-1);   
}
 
long long ansM(long long l, long long r)
{
    long long sum = 0;
    long long cnt = 0;
    for(long long i = r; i >= l; i--){
        if(s[i] == '1'){
            sum += poww(2, cnt);
        }
        cnt ++;
    }
    return sum;
}
 
int main()
{
    long long t,len;
    long long Case = 1;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&k);
        scanf("%s",s); 
        len = strlen(s);
         
        long long r = len - k;
        tmpl = 0, tmpr = k-1;
        for(long long i = 1;i <= r ;i++){
            cmpS(i,i+k-1);
        }
        long long ans = ansM(tmpl,tmpr);
        printf("Case #%lld: %lld\n", Case++, ans);
    }
    return 0;
}
