#include<bits/stdc++.h>
using namespace std;

struct ad{
	int key;
	int next;
}addr[100005];
int s1[100005],s2[100005];
int vis[10005];

int main(){
	int fst,n,cur,a,b,c; 
	scanf("%d%d",&fst,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		addr[a].key = b;
		addr[a].next = c;
	}
	cur = fst;
	int cnt1=0,cnt2=0;
	ad node;
	node = addr[fst];
	while(cur!=-1){
		if(!vis[abs(addr[cur].key)]){
			vis[abs(addr[cur].key)] = 1;
//			if(cnt2!=0)
//				addr[s2[cnt2-1]].next = -1;
//			if(addr[s1[cnt1-1]].next==-1)
//				addr[s1[cnt1-1]].next = cur;
			s1[cnt1++] = cur;
		}
		else{
//			if(cnt1!=0)
//				addr[s1[cnt1-1]].next = -1;
//			if(addr[s2[cnt2-1]].next==-1)
//				addr[s2[cnt2-1]].next = cur;
			s2[cnt2++] = cur;
		}
		cur = addr[cur].next;
	}
	addr[s1[cnt1-1]].next=-1;
	addr[s2[cnt2-1]].next=-1;
	for(int i=0;i<cnt1;i++){
		if(i+1<cnt1)
			printf("%05d %d %05d\n",s1[i],addr[s1[i]].key,s1[i+1]);	
		else
			printf("%05d %d %d\n",s1[i],addr[s1[i]].key,-1);	
	}
	for(int i=0;i<cnt2;i++){
		if(i+1<cnt2)
			printf("%05d %d %05d\n",s2[i],addr[s2[i]].key,s2[i+1]);	
		else
			printf("%05d %d %d\n",s2[i],addr[s2[i]].key,-1);	
	}
	return 0;	
}
