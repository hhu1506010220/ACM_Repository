#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b,a) for(int i=b;i>=a;i--)
using namespace std;
const int N=1e5+100;
ll arr[6][6]= {
	1,1,0,0,0,0,
	1,0,0,0,0,0,
	1,0,1,0,0,0,
	1,0,3,1,0,0,
	1,0,3,2,1,0,
	1,0,1,1,1,1
};
struct node {
	ll m,l;//m为矩阵的行数,l为矩阵的列数
	ll v[7][7];
};
node get_mul(node a,node b) {
	node c;
	c.m=a.m,c.l=b.l;
	for(int i=0; i<c.m; i++) {
		for(int j=0; j<c.l; j++) {
			c.v[i][j]=0;
			for(int k=0; k<a.l; k++) {
				c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%mod;
			}
		}
	}
	return c;
}
int getresult(ll n) {
	node a,b;
	a.l=6,a.m=1;
	a.v[0][0]=1,a.v[0][1]=0,a.v[0][2]=8;
	a.v[0][3]=4,a.v[0][4]=2,a.v[0][5]=1,
	b.l=6,b.m=6;
	rep(i,0,6)
		rep(j,0,6)
			b.v[i][j]=arr[i][j];
	while(n) {
		if(n&1)
			a=get_mul(a,b);
		b=get_mul(b,b);
		n>>=1;
	}
	return a.v[0][0];
}
int main() {
	ios::sync_with_stdio(false);
	ll n,t;
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<getresult(n-1)<<endl;
	}
	return 0;
}
