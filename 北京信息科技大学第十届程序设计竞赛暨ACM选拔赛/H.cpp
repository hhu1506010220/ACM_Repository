#include<bits/stdc++.h>
using namespace std;

int a[105],b[105];

int main(){
	int n;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)cin>>a[i];
		int len = 0;
		for(int i = 1; i <= n; ++i) {
			int* p = upper_bound(b + 1, b + len + 1, a[i]);
			*p = a[i];
			len = max(len, a[i] = p - b);
		}
		cout<<len<<endl;
	}
	return 0;
}
