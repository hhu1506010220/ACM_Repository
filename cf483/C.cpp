#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll qGCD(ll a,ll b) {
//	if(a == 0) return b;
//	if(b == 0) return a;
//	if(!(a & 1) && !(b & 1)) // a % 2 == 0 && b % 2 == 0;
//		return qGCD(a >> 1, b >> 1) << 1;
//	else if(!(b & 1))
//		return qGCD(a, b >> 1);
//	else if(!(a & 1))
//		return qGCD(a >> 1, b);
//	else
//		return qGCD(abs(a - b), min(a, b));
	return a%b==0ll?b:qGCD(b,a%b);
}
ll gcd(ll a,ll b) {
	return a%b==0ll?b:qGCD(b,a%b);
}
int main() {
	int n;
	n=read();
	ll p,q,b;
	ll time,t;
//	set<ll>s;
	while(n--) {
//		s.clear();
		p=read();
		q=read();
		b=read();
		time = p/q;
		p = p- time*q;
		ll __gcd = gcd(p,q);
		p = p/__gcd;
		q = q/__gcd;
//		for(ll i=2; i<=q/2; i++) {
//			while(q >= i) {
//				if(q % i == 0) { //能被整除
//					s.insert(i);
//					q /= i;//模仿短除法
//				} else
//					break;
//			}
//		}
//		if(q!=1)s.insert(q);
//		bool flag = 1;
//		set<ll>::iterator iter;
//		for(iter=s.begin();iter!=s.end();iter++){
////			cout<<*iter<<endl;
//			if(b%(*iter)!=0){
//				flag = 0;
//				break;
//			}
//		}
		for(int i=0; i<60; i++) {
//			if(q>100005)
				t = qGCD(q,b);
//			else
//				t=gcd(q,b);
			if(t==1) {
				break;
			} else {
				while(q%t==0)
				q/=t;
			}
			if(q==1) {
				break;
			}
		}
		if(q!=1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}
