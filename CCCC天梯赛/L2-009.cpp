#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct hb{
	ll id;
	ll money;
	ll fa;
	ll num;
}a[10005];

bool cmp(hb aa, hb bb){
	if(aa.money == bb.money){
		if(aa.num == bb.num)
			return aa.id<bb.id;
		return aa.num > bb.num;
	}
	return aa.money > bb.money;
}

int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		a[i].id = i;
		a[i].money = a[i].num = a[i].fa = 0;	
	}
	for(ll i=1;i<=n;i++){
		ll k,tem,t;
		cin>>k;
		long long ans = 0;
		for(ll j=1;j<=k;j++){
			cin>>tem>>t;
			a[tem].money+=t;
			a[tem].num++;
			ans += t;
		}
		a[i].fa = ans;
	}
	for(ll i=1;i<=n;i++)
		a[i].money -= a[i].fa;
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
		printf("%lld %.2f\n",a[i].id,((double)a[i].money*1.0)/100.0);
 	return 0;
}
