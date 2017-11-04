#include<bits/stdc++.h>
using namespace std;

int  a[105];

int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(a[1]%2==0||a[n]%2==0){
			cout<<"No"<<endl;
			continue;	
		}
		int cnt=0;
		int temp=1;
		for(int i=1;i<=n;i++){
			int cc =0 ;
			if(a[i]%2==1){
				cc = i-temp;
				temp=i;
			}
			if(cc%2==1)cnt++;
		}
		if(cnt%2==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
