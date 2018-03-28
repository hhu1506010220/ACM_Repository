#include<bits/stdc++.h>
using namespace std;

int a[11];

int main(){
	int cnt = 1;
	for(int i=1;i<=10;i++){
		cnt*=i;
		a[i] = cnt;
	}
	int n;
	cin>>n;
	long long res =0;
	for(int i=1;i<=n;i++)res+=a[i];
	cout<<res<<endl;
	return 0;
}
