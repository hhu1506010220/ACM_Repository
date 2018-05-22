#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[1005],n;
	int j=0,cas[1005],t=0;
	cin>>n;
	int vis[1005]= {0};
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=n-1; i>=0; i--) {
		if(!vis[a[i]]) {
			cas[j++]=a[i];
		}
		vis[a[i]]=1;
	}
	cout<<j<<endl;
	for(int i=j-1; i>=0; i--) {
		cout<<cas[i]<<" ";
	}
	cout<<endl;
	return 0;
}
