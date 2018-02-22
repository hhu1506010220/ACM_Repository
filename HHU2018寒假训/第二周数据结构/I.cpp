#include<bits/stdc++.h>
using namespace std;

map<string,int>m;

int main(){
	int n;
	string s,res;
	int cnt ,maxn ;
	while(cin>>n&&n){
		m.clear();
		maxn = -1;
		cnt = 0;
		for(int i=0;i<n;i++){
			cin>>s;
			m[s]++;
		}
		map<string,int>::iterator iter;
		for(iter = m.begin();iter!=m.end();iter++){
			if(maxn<iter->second){
				res = iter->first;
				maxn = iter->second;
			}
		}
		cout<<res<<endl;
	}
	return 0;	
}
