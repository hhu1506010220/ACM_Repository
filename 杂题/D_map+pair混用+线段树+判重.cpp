#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define lc n << 1
#define rc n << 1 | 1
typedef long long ll;

typedef pair<ll,ll>PII;
map<PII,ll>mp;
  
struct node {
    ll l, r;
    ll sum;
}t[maxn << 2];

inline void push_up(ll n) { t[n].sum = t[lc].sum + t[rc].sum; }

void build(ll n, ll l, ll r){
    t[n].l = l;t[n].r = r;
    if (l == r){
        cin >> t[n].sum;
        return;
    }
    ll mid = (l + r) >> 1;
    build(lc, l, mid);      //构建左子树
    build(rc, mid + 1, r);  //构建右子树
    push_up(n);             //更新当前节点
}

ll sum_query(ll n, ll ql, ll qr){
    if (ql <= t[n].l&&qr >= t[n].r)   
        return t[n].sum;
    ll mid = (t[n].l + t[n].r) >> 1;
    if (qr <= mid)return sum_query(lc, ql, qr); 
    if (ql > mid)return sum_query(rc, ql, qr);  
    return sum_query(lc, ql, qr) + sum_query(rc, ql, qr);//一左一右
}

int main()  
{  
    ll n,m,value,tem,res=0;  
    PII temp;
	mp.clear();
    scanf("%lld",&n); 
    build(1,1,n);
	scanf("%lld",&m);
    while(m--){  
        scanf("%lld%lld",&temp.first,&temp.second);
        if(mp[temp]){
        	continue;
        }
        mp[temp]=1;
        tem = sum_query(1,temp.first,temp.second);
        if(tem>0){
        	res+=tem;
        }
    }
	printf("%lld\n",res);
    return 0;  
}  

