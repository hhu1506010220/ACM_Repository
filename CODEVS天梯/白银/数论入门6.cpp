#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;	
	return 0;
}
