#include<bits/stdc++.h>
using namespace std;

struct nod{
	int l,r;
}node[100005],temp,tempp;

int main(){
	int n,m;
	int op,x,y,_st,cntt=1,flag;
	while(~scanf("%d%d",&n,&m)){
		memset(node,0,sizeof(node));
		flag = 0;//0ÎªÕýÐò 1Îªµ¹Ðò 
		for(int i=1;i<=n;i++){
			node[i].l=i-1;
			node[i].r=(i+1)%(n+1);	
		}
		node[0].l = n;
		node[0].r = 1;
		for(int i=0;i<m;i++){
			scanf("%d",&op);
			if(op==4){
				flag = !flag;
				continue;
				
			}
			else{	
				scanf("%d%d",&x,&y);
				if(op<3&&flag==1)
					op = 3-op;
				if(op==1){
					if(x==node[y].l)
                    	continue;
					node[node[x].l].r = node[x].r;
					node[node[x].r].l = node[x].l;
					node[node[y].l].r = x;
					node[x].l = node[y].l;
					node[x].r = y;
					node[y].l = x;
				}
				else if(op==2){
					if(x==node[y].r)
						continue;
					node[node[x].l].r = node[x].r;
					node[node[x].r].l = node[x].l;
					node[node[y].r].l = x;
					node[x].r = node[y].r;
					node[x].l = y;
					node[y].r = x;
				}
				else if(op==3){
					if(x==y)
						continue;
					else if(node[x].r==y||node[y].r==x){
						if(node[y].r==x){
							swap(x,y);
						}
						node[node[x].l].r=y;
	                    node[node[y].r].l=x;
	                    node[x].r=node[y].r;
	                    node[y].l=node[x].l;
	                    node[x].l=y;
	                    node[y].r=x;
					}
					else{
	                    node[node[x].l].r=y;
	                    node[node[y].r].l=x;
	                    node[node[x].r].l=y;
	                    node[node[y].l].r=x;
	                    swap(node[x].l,node[y].l);
                  	    swap(node[x].r,node[y].r);
	                }
				}
			}
//			for(int i=1;i<=n;i++)cout<<i<<" L:"<<node[i].l<<" R:"<<node[i].r<<endl;
		}
		long long sum = 0;
		_st = 0;
		if(flag){
			for(int i=0;i<=n;i++){
//				temp = node[_st];
				if(i%2==1){
					sum += _st;
				}
				_st = node[_st].l;	
			}
		}
		else{
			for(int i=0;i<=n;i++){
//				temp = node[_st];
				if(i%2==1){
					sum += _st;
				}
				_st = node[_st].r;	
			}	
		}
		printf("Case %d: %lld\n",cntt++,sum);
	}
	return 0;
}
