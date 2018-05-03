#include<bits/stdc++.h>
using namespace std;

int a[101][101];

int main(){
	memset(a,0,sizeof(a));
	long long sum = 0;
	int cnt = 1;
	for(int i=1;i<=101;i++){
		for(int j=1;j<=101;j++){
			a[i][j] = cnt++;
		}
	}
	for(int i=1;i<=51;i++){
		for(int j=1;j<i;j++){
			sum+=a[i][51-j];
			sum+=a[i][51+j];
		}
		sum+=a[i][51];
	}
	for(int i=52;i<=101;i++){ 
		for(int j=1;j<102-i;j++){
			sum+=a[i][51-j];
			sum+=a[i][51+j];
		}
		sum+=a[i][51];
	}	
	
	cout<<sum<<endl;
	return 0;
}
