# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+10;
int n,m;
ll add[maxn<<2],sum[maxn<<2];
ll num[70];

void pushdown(ll rt) {
	if(add[rt]) {
		add[rt<<1]|=add[rt];
		add[rt<<1|1]|=add[rt];
		sum[rt<<1]|=add[rt];
		sum[rt<<1|1]|=add[rt];
		add[rt]=0;
	}
}

void update(ll rt,ll l,ll r,ll L,ll R,ll val) {
	if(L<=l&&r<=R) {
		sum[rt]|=val;
		add[rt]|=val;
		return ;
	}
	pushdown(rt);
	ll mid=(l+r)>>1;
	if(L<=mid) {
		update(rt<<1,l,mid,L,R,val);
	}
	if(R>mid) {
		update(rt<<1|1,mid+1,r,L,R,val);
	}
	sum[rt]=sum[rt<<1]|sum[rt<<1|1];
}

ll query(ll rt,ll l,ll r,ll L,ll R) {
	if(L<=l&&r<=R) {
		return sum[rt];
	}
	pushdown(rt);
	ll mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid) {
		ans|=query(rt<<1,l,mid,L,R);
	}
	if(R>mid) {
		ans|=query(rt<<1|1,mid+1,r,L,R);
	}
	return ans;
}

ll solve(ll x) {
	ll sum=0;
	while(x) {
		if(x&1) {
			sum++;
		}
		x=x>>1;
	}
	return sum;
}

int main(void) {
	ll l,r,c;
	ll tmp;
	ll ans;
	num[0]=1;
	for(ll i=1; i<=60; i++)
		num[i]=num[i-1]*2;
	while(scanf("%lld %lld",&n,&m)!=EOF) {
		memset(add,0,sizeof(add));
		memset(sum,0,sizeof(sum));
		while(m--) {
			scanf("%lld",&tmp);
			if(tmp==1) {
				scanf("%lld %lld %lld",&l,&r,&c);
				update(1,1,n,l,r,num[c]);
			} else {
				scanf("%lld %lld",&l,&r);
				ans=query(1,1,n,l,r);
				printf("%lld\n",solve(ans));
			}
		}
	}
	return 0;
}
