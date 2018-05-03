#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n ,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	sort(a,a+n);
	int t;
	long long ans = 0;
	for(int i=n-1;i>=0;i--){
		t = lower_bound(a,a+n,a[i]-d)-a;
//		cout<<a[t]<<" "<<a[i]<<" "<<i-t-1<<endl;
		long long tem = (long long)(i-t-1)*(i-t)/2;
		ans += tem;
	}
	cout<<ans<<endl;
	return 0;
}
