#include<bits/stdc++.h>
using namespace std;

map<int,int>m;

int main(){
	int n;
	scanf("%d",&n);
	int tem;
	int cnt = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&tem);
		m[tem]++;	
		if(m[-tem]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
