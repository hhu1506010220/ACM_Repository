#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
	ll r= a%b;
	if(r==0)return b;
	else return gcd(b,a%b); 	
}

int main(){
	ll a,b,c,d;
	while(cin>>a>>b>>c>>d){
		if(a>c){
			swap(a,c);
			swap(b,d);
		}
		if((c>b)||(b<a)||(c>d)){
			puts("0/1");
			continue;
		}
		ll len1 = b-a+1;
		ll len2 = d-c+1;
		ll l = max(a,c);
		ll r = min(b,d);
		ll fenmu = len1*len2;
		ll fenzi = r-l+1;
		ll GCD = gcd(fenzi,fenmu);
		cout<<fenzi/GCD<<"/"<<fenmu/GCD<<endl; 
	}
	return 0;	
}
