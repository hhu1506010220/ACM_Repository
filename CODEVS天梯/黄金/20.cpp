#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string s,q[7];
int p,kk,pp,bj[201][201],sum[201][201],f[201][201];
int comp(string a,string b) {
	return a.size()<b.size();
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>p>>kk;
		for(int i=1; i<=p; i++) {
			string ss;
			cin>>ss;
			s+=ss;
		}
		cin>>pp;
		for(int i=1; i<=pp; i++)
			cin>>q[i];
		sort(q+1,q+1+pp,comp);
		for(int i=0; i<s.size(); i++)
			for(int j=i; j>=0; j--)
				for(int k=1; k<=pp; k++) {
					sum[j+1][i+1]=sum[j+2][i+1];
					if(q[k].size()<=(i-j+1)) {
						int pd=1;
						int h1=0,h2=j;
						while(h1<q[k].size()&&q[k][h1]==s[h2])  h1++,h2++;
						if(h1==q[k].size()) {
							sum[j+1][i+1]++;
							break;
						}
					}
				}
		for(int k=1; k<=kk; k++)
			for(int i=1; i<=s.size(); i++)
				for(int j=k-1; j<i; j++)
					f[i][k]=max(f[i][k],f[j][k-1]+sum[j+1][i]);
		cout<<f[s.size()][kk]<<endl;
	}
	return 0;
}
