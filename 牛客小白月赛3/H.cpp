#include<bits/stdc++.h>
#define int long long
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int m ;
		int ans1,ans2;
		if(n>=2018){
			m = n-2018;
			int tiangan = m%10;
			tiangan = (tiangan+5)%10;
			if(!tiangan)
				ans1 = 10;
			else
				ans1 = tiangan;
			int dizhi = m%12;
			dizhi = (dizhi+11)%12;
			if(!dizhi)
				ans2 = 12;
			else
				ans2 = dizhi;
		}
		else{
			m = 2018-n;
			int tiangan = m%10;
			if(tiangan<=4)
				ans1 = 5 - tiangan;
			else
				ans1 = 10+5-tiangan;
			int dizhi = m%12;
			if(dizhi<=10)
				ans2 = 11 - dizhi;
			else
				ans2 = 12+11-dizhi;			
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;	
}
