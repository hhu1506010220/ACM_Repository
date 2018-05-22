#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[105];
	int n;
	cin>>n;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n/2;i++){
		cin>>a[i];	
	}
	sort(a,a+n/2);
	int cnt = 1;
	for(int i=0;i<n/2;i++){
		cnt1 += abs(a[i]-cnt);
		cnt+=2;
	}
	cnt = 2;
	for(int i=0;i<n/2;i++){
		cnt2 += abs(a[i]-cnt);
		cnt += 2;
	}
	cout<<min(cnt1,cnt2)<<endl;
	return 0;
}
