#include<bits/stdc++.h>
using namespace std;

int a[51][51];
int b[51];
int c[51];

int main() {
	int n,m;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=0; i<m; i++) {
		string s;
		cin>>s;
		memset(c,0,sizeof(c));
		for(int j=0; j<s.length(); j++) {
			c[j] = s[j]-'a';
		}
		for(int j=0; j<s.length(); j++) {
			for(int k=0; k<s.length(); k++) {
				if(c[j]<c[k]) {
					a[j][k]++;
				}
			}
		}
//		for(int i=0; i<n; i++) {
//			for(int j=0; j<n; j++) {
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	int maxn_peo=-1;
	for(int i=0; i<n; i++) {
		int t = 0;
		for(int j=0; j<n; j++) {
			if(a[i][j]>a[j][i])
				t++;
		}
		if(t==n-1) {
			maxn_peo = i;
			break;
		}
	}
	cout<<maxn_peo<<endl;
	return 0;
}
