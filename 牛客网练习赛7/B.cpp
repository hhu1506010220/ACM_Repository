#include<bits/stdc++.h>
#define inf 0x3f3f3f3f 
using namespace std;

int a[305][305];
int tot[90005];
int dp[305];   //前i天买m个糖果的最小价钱 
multiset<int>s;

int main(){
	int n,m;
	s.clear();
	long long sum = 0;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
		sort(a[i],a[i]+m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j)
				a[i][j] = a[i][j] + 2*j+1;
			else
				a[i][j] = a[i][j] + 1;
		}
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	int cnt=0; 
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			tot[cnt++] = a[i][j]; 
//		}
//	}
//	sort(tot,tot+cnt);
//	for(int i =0;i<cnt;i++)cout<<tot[i]<<" ";
	multiset<int>::iterator it;  	
	int now = 0;
	for(int i=0;i<n;i++){	
		for(int j=0;j<m;j++){
			s.insert(a[i][j]);
		}
		it=s.begin(); 
		sum+=(*it);
		s.erase(it);
	}
	printf("%lld\n",sum);
	return 0;
}
