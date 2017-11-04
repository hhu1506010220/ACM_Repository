#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=1005;
ll n,a[N];
bool check(ll x,ll y){
    ll num=0,xx,yy;
    for(ll i=0;i<n;++i)if(i!=x&&i!=y){
        if((a[x]-a[y])*(x-i)!=(a[x]-a[i])*(x-y)){
            if(num==0){
                xx=i;
                yy=a[i];
                num++;
            }else if((a[x]-a[y])*(xx-i)!=(yy-a[i])*(x-y))return 0;
        }
    }
    return num!=0;
}
int main(void){
    scanf("%I64d",&n);
    for(ll i=0;i<n;++i)
        scanf("%I64d",&a[i]);
    if(n==3){
        if((a[0]-a[1])*(1-2)==(a[1]-a[2])*(0-1))printf("No\n");
        else printf("Yes\n");
    }else{
        srand(time(0));
        bool flag=0;
        int T=5000;
        while(T--){
            ll x=rand()%n,y=rand()%n;
            while(y==x)y=rand()%n;
            flag|=check(x,y);
            if(flag)break;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
}
