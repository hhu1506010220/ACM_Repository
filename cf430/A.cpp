#include<bits/stdc++.h>
using namespace std;

int main(){
	long long  l,r,x,y,k;
	while(cin>>l>>r>>x>>y>>k){
		bool flag=0;
		for(long long i=x;i<=y;i++){
			if(i*k<=r&&i*k>=l)	
			{
				flag=1;
				break;	
			}
			if(i*k>=r)break;
		}
		if(flag) cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
	return 0;	
}
