#include<bits/stdc++.h>
using namespace std;

char mp[105][105];
int n,m;
int cnt[105][105];
int dir[8][2]={-1,0,1,0,0,-1,0,1,-1,-1,-1,1,1,-1,1,1};

void check(int x,int y){
	for(int i=0;i<8;i++){
		int xx = x+dir[i][0];
		int yy = y+dir[i][1];
		if(xx<0||xx>n||yy<0||yy>m){
			continue;
		}
		cnt[xx][yy]++;
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mp[i][j];	
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j]=='*'){
				check(i,j);
			}
		}
	}
	bool flag = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j]>='0'&&mp[i][j]<='8'){
				if(mp[i][j]-'0'!=cnt[i][j]){
					flag = 0;
					break;	
				}
			}
			else if(mp[i][j]=='.'){
				if(cnt[i][j]!=0){
					flag =0;
					break;
				}
			}
			else if(mp[i][j]=='*'){
				continue;	
			}
			else{
				flag = 0;
				break;
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	if(flag)puts("YES");
	else puts("NO");
	return 0;	
}
