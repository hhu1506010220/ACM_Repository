#include<bits/stdc++.h>
using namespace std;

char a[2005][2005];
int cnt[2005];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='1')
				cnt[j]++;
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<a[i][j];
//		}
//		puts("");
//	}
//	for(int i=0;i<m;i++)cout<<cnt[i]<<" ";cout<<endl;
	bool flag = 1;
	for(int i=0;i<n;i++){
		bool flagg = 0;//都可以被取代 
		for(int j=0;j<m;j++){
			if(a[i][j]=='1'&&cnt[j]==1){
				flagg = 1;
			}
		}
		if(!flagg){
			flag = 0;
//			cout<<i<<endl;
			break;	
		}
	}
	if(flag)puts("NO");
	else puts("YES");
	return 0;
}
