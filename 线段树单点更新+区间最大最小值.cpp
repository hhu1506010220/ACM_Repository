/**********************************/
/* 线段树单点更新+区间最大最小值  */
/**********************************/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = (1 << 17) + 10;
const ll maxn = (1 << 17) + 10;
ll n;
ll C[4 * maxn];
ll D[4 * maxn];
void update(ll o, ll p, ll L, ll R, ll v){
    if(L == R){
        C[o] = v;
        D[o] = v;
    }
    else{
        ll M = L + (R - L) / 2;
        if(p <= M) update(o << 1, p, L, M, v);
        else update(o << 1 | 1, p, M + 1, R, v);
        C[o] = min(C[o << 1] , C[o << 1 | 1] );
        D[o] = max(D[o << 1], D[o << 1 | 1]);
    }
}
ll queryMax(ll o, ll L ,ll R, ll l, ll r){
    if(l <= L && r >= R){
        return D[o];
    }
    else{
        ll M = L + (R - L) / 2;
        ll maximum = - inf;
        if(l <= M){ maximum = max(queryMax(o << 1, L, M, l, r), maximum);}
        if(r > M) { maximum = max(queryMax(o << 1 | 1, M + 1, R , l, r), maximum);}
        return maximum;
    }
}
ll queryMin(ll o, ll L, ll R, ll l, ll r){
    if(l <= L && r >= R){
        return C[o];
    }
    else{
        ll M = L + (R - L) / 2;
        ll minimum = inf;
        if(l <= M){ minimum = min(queryMin(o << 1, L, M, l, r), minimum);}
        if(r > M) minimum = min(queryMin(o << 1 | 1, M + 1, R , l, r), minimum);
        return minimum;
    }
}

int main(){
    int t;
    ll kk,v,m,op,a,b,minn=0,maxx=0;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&kk);
        n = pow(2,kk);
        for(int i=1;i<=n;i++){
            scanf("%lld",&v);
            update(1,i,1,n,v);
        }
        scanf("%lld",&m);
        while(m--){
            scanf("%lld",&op);
            if(op==1){
                scanf("%lld%lld",&a,&b);
                maxx = queryMax(1, 1 , n , a+1, b+1);
                minn = queryMin(1, 1 , n , a+1, b+1);
                printf("%lld\n",min(minn*minn,min(minn*maxx,maxx*maxx)));
            }
            else{
                scanf("%lld%lld",&a,&b);
                update(1,a+1,1,n,b);
            }
        }
    }
    return 0;
}

