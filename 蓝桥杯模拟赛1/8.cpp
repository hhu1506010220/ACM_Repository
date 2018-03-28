#include<bits/stdc++.h>
using namespace std;
const long long N = 2015;
long long mp[N][N];
int main() {
	long long n, i, j, m, a, b, w;
	cin>>n;
	memset(mp,0,sizeof(mp));
	while(n--) {
		cin>>a>>b>>w;
		mp[a+1][b+1] += w;
	}
	for(i = 1; i<2010; i++){
		for(j = 1; j<2010; j++){
			mp[i][j] += mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1];
		}
	}
	cin>>m;
	while(m--) {
		long long x1,y1, x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1++, y1++, x2++, y2++;
		cout<<(mp[x2][y2] - mp[x1-1][y2] - mp[x2][y1-1] + mp[x1-1][y1-1])<<endl;
	}
	return 0;
}
