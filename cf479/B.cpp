#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		map<string,int>m;
		string a,t;
		cin>>a;
		for(int i=0;i<n-1;i++){
			char tt[3];
			tt[0]=a[i];
			tt[1]=a[i+1];
			t = tt;
			m[t]++;
	//		cout<<t<<endl;
		}
	//	cout<<m.size()<<endl;
		string ans_s;
		int maxn = 0;
		map<string, int>::iterator iter;
	    for(iter = m.begin(); iter != m.end(); iter++)  {
	    	if(iter->second>maxn){
	    		ans_s = iter->first;
	    		maxn = iter->second;
	    	}
	    }
		cout<<ans_s<<endl;
	}
	return 0;	
}
