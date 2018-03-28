#include<bits/stdc++.h>
using namespace std;

int a[105][105];

int main(){
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	int x1,y1,x2,y2;
	while(n--){
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<x2;i++)
			for(int j=y1;j<y2;j++)
				a[i][j] = 1;
	}
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int cnt = 0;
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++){
			if(a[i][j]){
				cnt++;
			}
		}
	cout<<cnt<<endl;
	return 0;	
}
