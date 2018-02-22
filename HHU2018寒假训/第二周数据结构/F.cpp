#include<bits/stdc++.h>
using namespace std;

map <int,vector<int> >mp;

int main(){
	int n,m,k,v;
	int temp,cnt;
	map<int,vector<int>>::iterator iter;
	while(~scanf("%d%d",&n,&m)){ 
		mp.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&temp);	
			mp[temp].push_back(i+1);
		}
		while(m--){
			scanf("%d%d",&k,&v);
			iter = mp.find(v);
            if(iter==mp.end()||k>mp[v].size()){
                printf("0\n");
            }
            else{
				printf("%d\n",mp[v].at(k-1));
            }
		}
	}
	return 0;
}
