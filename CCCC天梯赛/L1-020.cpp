#include<bits/stdc++.h>
using namespace std;

int a[100005];
int vis[100005];
int ans[100005];

int main(){
	int n;
	cin>>n;
	while(n--){
		int k,tem;
		cin>>k;
		if(k>1){
			while(k--){
				cin>>tem;
				a[tem] = 1;	
			}
		}
		else if(k==1){
			cin>>tem;	
		}
	}
	int m;
	cin>>m;
	int tem;
	int cnt =0;
	while(m--){
		cin>>tem;
		if(!a[tem]&&!vis[tem]){
			vis[tem] = 1;
			ans[cnt++] = tem;
		}
	}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1) 
			printf("%05d ",ans[i]);
		else
			printf("%05d\n",ans[i]);
	}
	if(cnt==0)cout<<"No one is handsome"<<endl;
	return 0;	
}
