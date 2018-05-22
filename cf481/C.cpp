#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200005],b[200005],sum[200005];  ;

int main(){
	int n , m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]+=sum[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		ll t = lower_bound(sum+1,sum+1+n,b[i])-sum;
		t--;
		ll num = b[i]-sum[t]; 
		cout<<t+1<<" "<<num<<endl;
	}
	return 0;	
}
