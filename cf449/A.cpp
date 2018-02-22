#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	char s[105];
	cin>>s+1;
	while(m--){
		int l,r;
		char c1,c2;
		cin>>l>>r>>c1>>c2; 
		for(int i=l;i<=r;i++){
			if(s[i]==c1){
				s[i]=c2;	
			}
		}
	}
	cout<<s+1<<endl;
	return 0;
}
