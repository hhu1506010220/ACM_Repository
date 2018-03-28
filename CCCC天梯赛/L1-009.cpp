#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
int n;
ll a[110],b[110];

ll gcd(ll a,ll b) {
	return a%b?gcd(b,a%b):b;
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);	
}


int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%lld/%lld",&a[i],&b[i]);
	ll fenzi=a[0],fenmu=b[0],z,p;
	for(int i=1; i<n; i++) {
		p=lcm(fenmu,b[i]);
		fenzi=fenzi*(p/fenmu)+a[i]*(p/b[i]);
		fenmu=p;
		z=gcd(fenzi,fenmu);
		fenzi=fenzi/z;
		fenmu=fenmu/z;
	}
	ll w=fenzi/fenmu;
	fenzi=fenzi%fenmu;
	if(!fenzi)
		printf("%lld\n",w);
	else if(!w)
		printf("%lld/%lld\n",fenzi,fenmu);
	else printf("%lld %lld/%lld\n",w,fenzi,fenmu);
	return 0;
}
