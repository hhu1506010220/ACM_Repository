#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int cntd=0,cntm=0;
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='D')
				cntd++;
			else
				cntm++;	
		}
		int cnt =0;
		long long now = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='D'){
				cnt++;
			}
			else{
				now += (long long)cnt;
			}
		}
		long long minn = 0;
		long long maxn = (long long)cntd*cntm;
		if(k>maxn){
			cout<<"-1"<<endl;
			continue;	
		}else{
			cout<<abs(now-k)<<endl;
		}
	}
	return 0;
}
