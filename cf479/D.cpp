#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

struct nod{
	ll value;
	ll time;
}a[105];

bool cmp(nod a,nod b){
	if(a.time==b.time){
		return a.value<b.value;
	}
	return a.time>b.time;
}

int main(){
	int n;
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>a[i].value;
			a[i].time = 0;
			ll tem = a[i].value;
			while(tem%3==0){
				a[i].time ++;
				tem/=3;
			}
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(i!=n-1)cout<<a[i].value<<" ";
			else cout<<a[i].value<<endl; 
		}
	}
	return 0;
}
