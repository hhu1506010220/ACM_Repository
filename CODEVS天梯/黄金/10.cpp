#include<bits/stdc++.h>
using namespace std;

struct line {
	int l,r;
	int len;
	int v;
} a[1005];

int dp[1000005];//���� i��β���߶μ� �� ����ֵ 

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
			if(a[j].r<=a[i].l)//���ǰ��Ĳ�������߶γ�ͻ������ǰ���v���� 
				dp[a[i].r] = max (dp[a[i].r],dp[a[j].r]+a[i].v),cnt++;; 
		}
		//���ǰ��Ķ���ͻ��,ֻ��ȡǰ�� ���� ֻȡ��һ���߶� 
		if(cnt==0)
			dp[a[i].r] = max(a[i].v,dp[a[i].r]);
		maxn = max(maxn,dp[a[i].r]);
	}
	cout<<maxn<<endl;
	return 0;
}
