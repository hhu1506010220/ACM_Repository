#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	puts("YES");
	char mp[105][105];
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=4;i++)
		for(int j=1;j<=n;j++)
			mp[i][j] = '.';
	if(k%2==1){
		int m = k/(n-2);
		int w = k/2;
		if(m==0){
			int mid = (n+1)/2;
			for(int i=0;i<=w;i++){
				mp[2][i+mid] = '#';
				mp[2][mid-i] = '#';
			}
		}
		else{
			for(int i=2;i<=n-1;i++)
				mp[2][i] = '#';
			k-=(n-2);
			w = k/2;	
			int mid = (n+1)/2;
			for(int i=1;i<=w;i++){
				mp[3][i+mid] = '#';
				mp[3][mid-i] = '#'; 
			}
		}
	}
	else if(k%2==0){
		int m = k/2;
		for(int i=0;i<m;i++){
			mp[2][2+i] = '#';
			mp[3][2+i] = '#'; 		
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++)
			cout<<mp[i][j];	
		cout<<endl;
	}
	return 0;
}
