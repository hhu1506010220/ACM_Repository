#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[105];
	int sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];	
	}
	int ave = sum/n ;
	for(int i=0;i<n;i++){
		a[i] -= ave;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(a[i]==0)continue;
		a[i+1] += a[i];	
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
