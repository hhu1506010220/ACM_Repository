#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int time=1,max_time=1,ans=a[0];
	int tem = a[0];
	for(int i=1;i<n;i++){
		if(a[i] != tem){
			if(time>max_time){
				ans = tem;
				max_time = time;
			}
			tem = a[i];
			time = 1;
		}
		else time++;
	}	
	printf("%d\n",ans);
	return 0;
}
