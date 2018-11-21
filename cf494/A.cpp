#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[105];
	int w;
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>w;
		a[w]++;	
	}
	int maxn = 0;
	for(int i=0;i<=100;i++){
		maxn = max(maxn,a[i]);
	}
	cout<<maxn<<endl;
	return 0;
}
