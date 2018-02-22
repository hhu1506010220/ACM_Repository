#include<bits/stdc++.h>
using namespace std;

struct gunn{
	int p;
	int k;
	int kind[1005];	
}gun[1005];

struct peijian{
	int q;
	double b;
}item[1005];


int main(){
	int n,m;
	int tem;
	double temp;
	while(~scanf("%d%d",&n,&m)){
		memset(gun,0,sizeof(gun));
		memset(item,0,sizeof(item));
		
		for(int i=0;i<n;i++){
			scanf("%d%d",&gun[i].p,&gun[i].k);
			for(int j=0;j<gun[i].k;j++)
				scanf("%d",&gun[i].kind[j]);	
		}
		for(int i=0;i<m;i++){
			scanf("%d%lf",&tem,&temp);
			if(item[tem].b<temp){
				item[tem].b=temp;
			}
		}
	
		double ans = 0;
		double res = 0;
		double beishu = 1.0;
		
		for(int i=0;i<n;i++){
			res = gun[i].p*1.0;
			beishu = 1.0;
			for(int j=0;j<gun[i].k;j++){
				beishu += item[gun[i].kind[j]].b;
			}
			res *= beishu;
			ans = max(ans , res);	
		}
		
		
		printf("%.4lf\n",ans);
	}
	return 0;	
}
