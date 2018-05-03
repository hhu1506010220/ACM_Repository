#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	string s;
	cin>>s;
	string sub_s,tem;
	ll ans = s.length();
	ll len = s.length();
	for(ll i=0;i<len;i++){
		for(ll j=1;i+j<len;j++){//³¤¶È 
		    sub_s = s.substr(i,j);
			ll num = 0;
			for(ll k=0;k+j<=len;k++){
				tem = s.substr(k,j);
				if(tem==sub_s){
					num++;
					k += j-1;
				}
			}
			ans = min(ans,len-num*j+num+j);
		}
	}
	cout<<ans<<endl;
	return 0;
}
