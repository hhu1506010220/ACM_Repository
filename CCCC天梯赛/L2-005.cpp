#include<bits/stdc++.h>
using namespace std;

set<int>s[51];	

int main(){
	int n,m,k,tem;
	int u,v;
	int nc,nt;
	set<int>::iterator it;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&tem);
			s[i].insert(tem);
		}	
	}
	scanf("%d",&k);
	while(k--){
		nc = nt =0;
		scanf("%d%d",&u,&v);
	    for(it=s[u].begin();it!=s[u].end();it++){
	    	if(s[v].count(*it))
				nc++;	
	    }
	    nt = s[u].size()+s[v].size()-nc;
	    double ans = (double)nc*100.0/(double)(nt);
	    printf("%.2f%\n",ans);
	}
	return 0;
}
