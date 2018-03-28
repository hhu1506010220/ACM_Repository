#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int b[1005][1005];
int main(){
	memset(a,0,sizeof(a));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];	
		}
	}
	for(int i=m-1;i>=0;i--){ 
		for(int j=0;j<n;j++){
			b[m-1-i][j] = a[j][i];		
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=n-1)
				cout<<b[i][j]<<" ";
			else
				cout<<b[i][j]<<endl;
		}
	}
	return 0;
}
