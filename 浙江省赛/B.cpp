#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	int n,x;
	map<int,int> m; 
	map <int,int>::iterator m1;
	while(t--){
		m.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			x -= a[i];
			m1 = m.find(x);
			if(m1==m.end()){
				m.insert(pair<int,int>(x,1));
			} 
			else{
				m1->second++;
			}
    	

		}
		int maxn = 0;
		for ( m1= m.begin( );m1 != m.end( ); m1++ ){
			//cout<<m1->first<<" "<<m1->second<<endl;
			if(m1->second>maxn){
				maxn = m1->second;
			}
		}
		printf("%d\n",maxn); 
	} 
	return 0;
} 
