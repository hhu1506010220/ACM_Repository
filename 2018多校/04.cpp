#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

struct node{
	ll a,b;	
}q[105];

bool cmp(node a,node b){
	return a.a+a.b<b.a+b.b;
}

ll ans[105];
int main(){
	ll t;
	scanf("%lld",&t);
	ll n,m;
	while(t--){
		memset(ans,0,sizeof(ans));
		scanf("%lld%lld",&n,&m);
		for(ll i=0;i<n;i++){
			scanf("%lld%lld",&q[i].a,&q[i].b);	
		}
		sort(q,q+n,cmp);
		ll tem = 1;
		for(int i=0;i<n;i++){
			tem *= (q[i].a+q[i].b);
			if(tem<=0)ans[i] = 1000000009;
			else ans[i] = tem;	
		}
//		for(int i=0;i<n;i++)cout<<ans[i]<<" ";cout<<endl;
		cout<<(upper_bound(ans,ans+n,m)-ans)<<endl;
	}
	return 0;	
}
