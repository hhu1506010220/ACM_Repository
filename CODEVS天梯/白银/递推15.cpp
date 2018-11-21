#include <bits/stdc++.h>
using namespace std;

int a[100005]; 
int qianxu[100005];
int houxu[100005];
int zhongxu[100005];

int cnt_qianxu=0,cnt_houxu=0,cnt_zhongxu=0;

void visit_qianxu(int x){
	if(a[x]==0)return;
	qianxu[cnt_qianxu++] = a[x];
	visit_qianxu(x*2);
	visit_qianxu(x*2+1);
}

void visit_houxu(int x){
	if(a[x]==0)return;
	visit_houxu(x*2);
	visit_houxu(x*2+1);
	houxu[cnt_houxu++] = a[x];
}

void visit_zhongxu(int x){
	if(a[x]==0)return;
	visit_zhongxu(x*2);
	zhongxu[cnt_zhongxu++] = a[x];
	visit_zhongxu(x*2+1);
}

int main(){
	int n;
	cin>>n;
	int x,y;
	memset(a,0,sizeof(a));
	a[1] = 1;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=100005;j++){
			if(a[j]==i){
				a[j*2] = x;
				a[j*2+1] = y;
				break;
			}
		}
	}
	visit_qianxu(1);
	visit_houxu(1);
	visit_zhongxu(1);
	for(int i=0;i<cnt_qianxu;i++){
		if(i!=cnt_qianxu-1)
			cout<<qianxu[i]<<" ";
		else
			cout<<qianxu[i]<<endl;
	}
	for(int i=0;i<cnt_zhongxu;i++){
		if(i!=cnt_zhongxu-1)
			cout<<zhongxu[i]<<" ";
		else
			cout<<zhongxu[i]<<endl;
	}
	for(int i=0;i<cnt_houxu;i++){
		if(i!=cnt_houxu-1)
			cout<<houxu[i]<<" ";
		else
			cout<<houxu[i]<<endl;
	}
	return 0;
}
