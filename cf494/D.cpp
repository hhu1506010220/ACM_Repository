#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200005];
ll num[35],beifen[35];

int main(){
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		for(ll j=0;j<=29;j++){
			if((1<<j)==a[i]){
				num[j]++;
				beifen[j]++;	
				break;
			}
		}
	}
//	for(int i=0;i<29;i++)cout<<num[i]<<" ";cout<<endl;
	ll t;
	ll cnt = 0;
	while(q--){
		cin>>t;
		cnt = 0;
		for(ll i=29;i>=0;i--){
			if(t==0)break;
			if(t>=(1<<i)&&num[i]>0){
				ll nn = t/(1<<i);
				nn = min(nn,num[i]);
//				cout<<"123123213   "<<nn<<endl;
				num[i]-=nn;
				t-= nn*(1<<i);
				cnt +=nn;
			}
		}
		if(t==0){
			cout<<cnt<<endl;	
		}
		else{
			cout<<-1<<endl;	
		}
		for(int i=0;i<=29;i++)num[i]=beifen[i];
	}
	return 0;
}
