#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<string,int>m;
	char s[1005];
	for(int i=0;i<n;i++){
		memset(s,0,sizeof(s));
		cin>>s;
		int len = strlen(s); 
		sort(s,s+len);
		set<char>ss;
		for(int j=0;j<len;j++){
			ss.insert(s[j]);
		}
		string t ="";
		set<char>::iterator iter;
		for(iter=ss.begin();iter!=ss.end();iter++){
			t+= *iter;	
		}
//		cout<<t<<endl;
		m[t]++;
	}
	cout<<m.size()<<endl;
	return 0;
}
