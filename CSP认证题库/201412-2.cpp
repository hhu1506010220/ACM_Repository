#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int ans[250001];

int main(){
	memset(a,0,sizeof(a));
	int n;
	int cnt = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	ans[cnt++]=a[0][0];
	int buchang = 1;
	int dir[4][2]={0,1,1,-1,1,0,-1,1};
	int x = 0,y = 0;
	while(1){
		x += dir[0][0];
		y += dir[0][1];
		if(a[x][y])
			ans[cnt++]=a[x][y];
		bool flag = 1;
		for(int i=0;i<buchang;i++){
			x += dir[1][0];
			y += dir[1][1];	
			if(a[x][y])
				ans[cnt++]=a[x][y];
		}
		buchang++;
		x += dir[2][0];
		y += dir[2][1];
		if(a[x][y])
			ans[cnt++]=a[x][y];
		flag = 1;
		for(int i=0;i<buchang;i++){
			x += dir[3][0];
			y += dir[3][1];	
			if(a[x][y])	
				ans[cnt++]=a[x][y];
		}			
		buchang++;
		if(cnt==n*n)
			break;
	}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1)
			cout<<ans[i]<<" ";
		else
			cout<<ans[i]<<endl;	
	}
	
	return 0;	
}
