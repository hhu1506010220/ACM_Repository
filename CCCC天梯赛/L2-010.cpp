#include<bits/stdc++.h>
using namespace std;

int pre[105];
set< int >s[105];

int find(int x){
	int t = x;
	while(t!=pre[t]){
		t = pre[t];	
	}
	int y = x,w;
	while(pre[y]!=t){
		w = pre[y];	
		pre[y] = t;
		y = w;
	}
	return t;
}

void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy)
		pre[fy] = fx;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int b1,b2,re;
	for(int i=0;i<=n;i++)
		pre[i] = i;
	for(int i=0;i<m;i++){
		cin>>b1>>b2>>re;
		if(re==1)
			merge(b1,b2);
		else{
			s[b1].insert(b2);
			s[b2].insert(b1);
		}
	}
	for(int i=0;i<k;i++){
		cin>>b1>>b2;
		int fri = 0, amy = 0;
		if(s[b1].count(b2)||s[b2].count(b1))
			amy = 1;
		if(find(b1)==find(b2))
			fri = 1;
		if(fri&&!amy)
			cout<<"No problem"<<endl;
		else if(!fri&&!amy)
			cout<<"OK"<<endl;
		else if(fri&&amy)
			cout<<"OK but..."<<endl;
		else
			cout<<"No way"<<endl;
	}
	return 0;
}
