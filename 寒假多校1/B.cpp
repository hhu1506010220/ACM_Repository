#include<bits/stdc++.h>
using namespace std;

struct pai{
	int s;
	int t;
	int x;
	int beishu = 1;	
}a[1005];

int main(){
	int n;
	int s,t,x; 
	while(~scanf("%d",&n)){ 
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].s,&a[i].t);
			if(a[i].t==1||a[i].t==2){
				scanf("%d",&a[i].x);	
			}
		}
		int st= 0,end=0;
		long long res = 0;
		int beishu = 1;
		for(int i=0;i<n;i++){	
			if(a[i].s>=a[end].s){
				end = i;	
				a[i].beishu = beishu;
				beishu++;
			}
			else{
				for(int j=end;j>=st;j--){
					if(a[j].t==1){
						res += a[j].x;
					}
					else if(a[j].t==2){
						res += a[j].x*a[j].beishu;	
					}
					else if(a[j].t==3){
						break;
					}
					else{
						j--;	
					}
				}
				st = i;
				end = i;
				beishu = 1;
				a[i].beishu=1;
				beishu++;
			}
//			cout<<i<<" "<<st<<" "<<end<<" "<<a[i].beishu<<" "<<res<<endl;
		}
		for(int j=end;j>=st;j--){
			if(a[j].t==1){
				res += a[j].x;
			}
			else if(a[j].t==2){
				res += a[j].x*a[j].beishu;	
			}
			else if(a[j].t==3){
				break;
			}
			else{
				j--;	
			}
		}
		printf("%lld\n",res);
	} 
	return 0;	
}
