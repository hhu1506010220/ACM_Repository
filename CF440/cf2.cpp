#include<bits/stdc++.h>
using namespace std;

int minn=0x3f3f3f3f;
int minnn=minn;
int maxn=-minn; 
int temp[100005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&temp[i]);	
		minn=min(minn,temp[i]);
		maxn=max(maxn,temp[i]);
	}
	if(k==1)cout<<minn<<endl;
	else if(k==2){
		int timee = 0;
		for(int i=0;i<n;i++){
			if(temp[i]==minn)timee++;
		}
		if(timee==1){
			int pos=0;
			for(int i=0;i<n;i++){
				if(temp[i]==minn){
					pos=i;
					break;	
				}
			}
			int min1=temp[0];
			for(int i=0;i<pos;i++){
				min1=min(min1,temp[i]);	
			}
			int res1 = max(min1,temp[0]);
			int min2=temp[n-1];
			for(int i=pos+1;i<n;i++){
				min2=min(min2,temp[i]);	
			}
			int res2 = max(min2,temp[n-1]);
			cout<<max(res1,res2)<<endl;
		}
		else{
			int pos1=0,pos2=0;
			bool flag=1;
			for(int i=0;i<n;i++){
				if(temp[i]==minn&&flag){
					pos1=i;
					flag=0;
				}
				else if(temp[i]==minn&&!flag){
					pos2=i;	
				}
			}
			int min1=temp[0];
			for(int i=0;i<pos1;i++){
				min1=min(min1,temp[i]);	
			}
			int res1 = max(min1,temp[0]);
			int min2=temp[n-1];
			for(int i=pos2+1;i<n;i++){
				min2=min(min2,temp[i]);	
			}
			int res2 = max(min2,temp[n-1]);
			cout<<max(res1,res2)<<endl;			
			
		}
	}
	else cout<<maxn<<endl;
	return 0;
}
