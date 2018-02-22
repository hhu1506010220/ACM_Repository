#include<bits/stdc++.h>
using namespace std;

int a[2600][1500];
struct pos{
	int x1,x2,y1,y2;	
}pos[12];

int main(){
	int n,m;	
	scanf("%d%d",&n,&m);
	int x1,x2,y1,y2;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&pos[i].x1,&pos[i].y1,&pos[i].x2,&pos[i].y2);
		for(int j=pos[i].x1;j<=pos[i].x2;j++){
			for(int k=pos[i].y1;k<=pos[i].y2;k++){
				a[j][k] = i ;	
			}
		}
	}
	int x, y,res;
	while(m--){
		scanf("%d%d",&x,&y);	
		if(a[x][y]){
			res = a[x][y];
			printf("%d\n",a[x][y]);	
			for(int j=pos[res].x1;j<=pos[res].x2;j++){
				for(int k=pos[res].y1;k<=pos[res].y2;k++){
					a[j][k] = res;	
				}
			}
		}
		else{
			puts("IGNORED");
		}
	}
	return 0;	
}
