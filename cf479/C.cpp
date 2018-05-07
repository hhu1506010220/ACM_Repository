#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	int a[200005];
	while(cin>>n>>k){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		if(k==0){
			if(a[1]>1){
				cout<<"1"<<endl;
			}
			else{
				cout<<"-1"<<endl;	
			}
		}
		else if(a[k]==a[k+1]){
			cout<<"-1"<<endl;
		}
		else{
			cout<<a[k]<<endl;
		}
	}
	return 0;
}
