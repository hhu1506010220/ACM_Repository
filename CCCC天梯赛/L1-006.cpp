#include<bits/stdc++.h>
using namespace std;

int main(){
	long long res = 1;
	int i;
	bool flag = 0;
	int n,m;
	cin>>n;
	int sq = ceil(sqrt(n));
	for(m=12;m>=1;m--){
//		cout<<"m="<<m<<endl;
		for(i = 2,res = 1;i<sq&&res<n;i++){
//			cout<<"i="<<i<<": ";
			res = 1;
			for(int t=0;t<m;t++){
				res *= (i+t);
				if(res>n)break;
			}
//			cout<<"res= "<<res<<endl;
			if(n%res==0){
				flag =1;
				break;
			}
		}
		if(flag)break;
	}
	if(flag){
		cout<<m<<endl;
		for(int j=0;j<m-1;j++){
			cout<<i+j<<"*";
		}
		cout<<i+m-1<<endl;
	}else{
		cout<<1<<endl;cout<<n<<endl;	
	}
	return 0;
}
