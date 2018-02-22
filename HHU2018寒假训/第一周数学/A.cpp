#include<cstdio>
#define ll long long 

ll gcd(ll a,ll b){
	return a%b?gcd(b,a%b):b;
}

int main(){
	int n,m;
	ll ans=1,temp;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		ans = 1;
		while(m--){
			scanf("%lld",&temp);
			ans = ans*temp/gcd(ans,temp);		
		}
		printf("%lld\n",ans);
	}
	
	return 0;	
}
