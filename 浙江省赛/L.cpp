#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn];
struct L{
	char c[20];
	int v;
}l[105];
bool cmp(L l1,L l2){
	if(l1.v!=l2.v){
		return l1.v>l2.v;
	}else{
		if(strcmp(l1.c,l2.c)==1){
			return false;
		}
		return true;
	}
}
int main(){
	//cout<<strcmp("hello","world")<<endl;
	int t;
	scanf("%d",&t);
	int n,k;
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%s%d",l[i].c,&l[i].v);
		}
		sort(l,l+n,cmp);
		long long sum = 0;
		long long tem = k; 
		for(int i=0;i<k;i++){
			sum = sum + (tem*l[i].v);
			tem --; 
		}
		printf("%lld",sum);
		for(int i=0;i<k;i++){
			printf(" %s",l[i].c);
		}
		printf("\n");
		
	} 
	return 0;
} 
