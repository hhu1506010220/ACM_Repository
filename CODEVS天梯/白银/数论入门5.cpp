#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	ll a,b;
	ll x,y;
	cin>>x>>y;
	ll t = 0;
	ll _gcd = 0; 
	ll _lcm = 0;
	int cnt = 0;
	for(ll i = 1;i<100000;i++){
		b = x*y/i;
		a = i;
		if(a*b==x*y){
			_gcd = gcd (a,b);
			_lcm = a*b/_gcd;
			if(_gcd==x&&_lcm==y)
			cnt++; 
		}
	}
	cout<<cnt<<endl;
	return 0;
}
