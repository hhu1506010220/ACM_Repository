#include<bits/stdc++.h>
using namespace std;

int a[200005];
int pre[200005];
int len[200005];

int main(){
//	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	map<int,int>mp;
	memset(a,0,sizeof(a));
	memset(pre,0,sizeof(pre));
	memset(len,0,sizeof(len));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]] = i;
		if(mp.find(a[i]-1)==mp.end()){
			len[i] = 1;	
			pre[i] = -1;
		}
		else if(mp[a[i]-1]<i){
			len[i] = len[mp[a[i]-1]]+1;	
			pre[i] = mp[a[i]-1];
		}
		else{
			len[i] = 1;
			pre[i] = -1;	
		}
	}
//	for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<" "<<len[i]<<" "<<pre[i]<<endl;
	int maxn = -1;
	int pos = -1;
	for(int i=1;i<=n;i++){
		if(maxn<len[i]){
			maxn = len[i];
			pos = i;	
		}
	}
	cout<<maxn<<endl;
	vector<int>v;
	while(pos!=-1){
		v.push_back(pos); 
		pos = pre[pos];
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(i!=v.size()-1)cout<<v[i]<<" ";	
		else cout<<v[i]<<endl;
	}
	return 0;
}
