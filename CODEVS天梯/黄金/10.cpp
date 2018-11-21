#include<bits/stdc++.h>
using namespace std;

struct line {
	int l,r;
	int len;
	int v;
} a[1005];

int dp[1000005];//代表到 i结尾的线段集 的 最大价值 

bool cmp(line a, line b) {
	if(a.r==b.r) return a.l>b.l;
	return a.r<b.r;
}

int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i].l>>a[i].r>>a[i].v;
		a[i].len = a[i].r - a[i].l;
	}
	int maxn = 0;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		int cnt = 0; 
		for(int j=0;j<i;j++){
			if(a[j].r<=a[i].l)//如果前面的不和这个线段冲突，借助前面的v更新 
				dp[a[i].r] = max (dp[a[i].r],dp[a[j].r]+a[i].v),cnt++;; 
		}
		//如果前面的都冲突了,只能取前面 或者 只取这一个线段 
		if(cnt==0)
			dp[a[i].r] = max(a[i].v,dp[a[i].r]);
		maxn = max(maxn,dp[a[i].r]);
	}
	cout<<maxn<<endl;
	return 0;
}
