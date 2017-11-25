#include<bits/stdc++.h>
using namespace std;

bool vis[200005]={0};
int a[200005];

int main(){
	int n;
	int tem;
	scanf("%d",&n);
	int cnt= 0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(!vis[a[i]])cnt++;
		vis[a[i]]=1;	
	}
	int cntt=0;
	memset(vis,0,sizeof(vis));
	for(int i=n-1;i>=0;i--){
		if(!vis[a[i]]){
			cntt++;	
			vis[a[i]]=1;
		}
//		cout<<a[i]<<" "<<i<<" "<<cntt<<endl;
		if(cntt==cnt){
			cout<<a[i]<<endl;
			break;
		}
	}
	return 0;
}
