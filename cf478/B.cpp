#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = -1;
ll a[15];
ll b[15];

void Pick(ll i){
	memset(b,0,sizeof(b));
	for(ll j=0;j<14;j++)b[j] = a[j];
	ll num = b[i];
	b[i] = 0;
	ll cnt;
	if(i!=13)
		cnt = i+1;
	else
		cnt = 0;
	ll time = num/14;
	for(ll j=0;j<14;j++)b[j]+=time;
	num %=14;
	while(num){
		b[cnt]++;
		num--;
		if(cnt==13){
			cnt = 0;	
		}
		else{
			cnt++;	
		}
	}
	ll t = 0;
	for(ll j=0;j<14;j++){
		if(b[j]%2==0){
			t+=b[j];
		}
	}
	ans = max(ans,t);
}

int main(){
	for(ll i=0;i<14;i++){
		cin>>a[i];
	}
	for(ll i=0;i<14;i++){
		Pick(i);	
	}
	cout<<ans<<endl;
	return 0;
}
