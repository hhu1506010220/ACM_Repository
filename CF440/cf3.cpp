#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int q;
	for(int i=0;i<n;i++){
		scanf("%d",&q);	
		if(q<4||q==5||q==7||q==11){
			printf("-1\n");
			continue;	
		}
		int ji,yu;
		ji = q/4;
		yu = q%4;
		if(yu==1&&ji>=2){
			printf("%d\n",ji-1);	
		}
		else if(yu==3&&ji>=3){
			printf("%d\n",ji-1);
		}
		else printf("%d\n",ji);
	}
	return 0;
}
