#include<bits/stdc++.h>
using namespace std;
int n;
int a[31],b[31],tr[100005],ans[31*4];
//a ÖÐÐò     b Ç°Ðò 
void build(int root, int z_l,int z_r, int q_l,int q_r){
	if((z_l>z_r)||(q_l>q_r)){
		return ;	
	}
	int t = b[q_l];
	tr[root] = t;
	int i;
	for(i=z_l;i<n;i++)
		if(a[i]==t)
			break;
	int len = i-z_l+1;
	build(root<<1,z_l,i-1,q_l+1,q_l+len-1);
	build((root<<1)+1,i+1,z_r,q_l+len,q_r); 
}

void bfs(int root){
	int cnt = 0;
	queue< int >q;
	q.push(root);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		ans[cnt++] = tr[t];
		if(tr[t*2+1])
			q.push(t*2+1);
		if(tr[t*2])
			q.push(t*2);	
	}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1)
			cout<<ans[i]<<" ";
		else
			cout<<ans[i]<<endl;	
	}
	return;
}

int main(){
	memset(tr,0,sizeof(tr));
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	build(1,0,n-1,0,n-1);
	int cnt = 0;
//	for(int i=0;i<100000;i++)
//		if(cnt==n)
//			break;
//		else{
//			if(tr[i])
//				cout<<tr[i]<<" ";	
//		}
	bfs(1);
	return 0;	
}
