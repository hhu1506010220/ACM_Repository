#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int maxn = 2002;
typedef long long ll;
ll a[maxn];
ll c[maxn];
ll ans[maxn];
ll qpow(ll a,ll n) {
	ll res = 1;
	while(n) {
		if(n&1)
			res = res*a%mod;
		a = a*a%mod;
		n>>=1;
	}
	return res;
}

int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 0; i<n; i++)
		cin>>a[i];
	c[0] = 1;
	for(int i=1; i<n; i++) {
		c[i] = c[i-1]*(k+i-1)%mod*qpow(i,mod-2)%mod;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			ans[i] = (ans[i]+a[j]*c[i-j])%mod;
		}

	}
	cout<<ans[0];
	for(int i=1; i<n; i++) {
		cout<<" "<<ans[i];
	}
	cout<<endl;
	return 0;
}
