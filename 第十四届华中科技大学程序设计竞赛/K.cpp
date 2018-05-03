#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll a[100000+5];
ll n,k;

ll f(ll x) {
	ll i=1,j,sum=0,num=0;
	while(i<n) {
		sum=0;
		for(j=0; i+j<n; j++) {
			sum+=a[i+j];
//			cout<<i+j<<" "<<a[i+j]<<" "<<sum<<" "<<x<<endl;
			if(sum>x) {
				num++;
//				cout<<i<<" "<<j<<endl;
				break;
			}
		}
		i=i+j;
	}
	return num+1;
}

int main() {
    scanf("%lld%lld",&n,&k);
	ll sum = 0;
	ll left = 0;
	memset(a,0,sizeof(a));
	for(ll i=1; i<n; i++) {
		scanf("%lld",&a[i]);
		if(a[i]>left) left = a[i];
		sum+=a[i];
	}
	a[0] = 0;
	a[n] = 0;
	ll right=sum;
	while(left<right) {
		ll mid=(left+right)/2;
//			cout<<mid<<endl;
		if(f(mid)>k) {
			left=mid+1;
		} else right=mid;
//			cout<<left<<":"<<right<<endl;
	}
	printf("%lld\n",left);
	return 0;
}
