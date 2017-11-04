#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n , k ,t;
	while(cin>>n>>k>>t){
		if(t>=n+k)t=t-(n+k)*(t/(n+k));
		if(t<=k)
			cout<<t<<endl;
		else if (t>=n)cout<<k-t+n<<endl;
		else
			cout<<k<<endl;
		
	}
	return 0;
}
