#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	int t,n;
	map<string,int>m;
	while(cin>>t){
		while(t--){
			m.empty();
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>s;
				m[s]++;
			}
			int maxn=0;
			map<string,int>::iterator iter ;
			for(iter = m.begin();iter!=m.end();iter++){
				if(iter->second>maxn)maxn = iter->second;
//				cout<<iter->first<<" "<<iter->second<<endl;	
			}
			for(iter = m.begin();iter!=m.end();iter++){
				if(iter->second==maxn){
					cout<<iter->first<<endl;
					break;
				}
			}			
		}
	}
	return 0;
}
