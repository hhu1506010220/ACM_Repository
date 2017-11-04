#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,r;	
}sau[100005];


int main(){
	int r,d,n;
	while(cin>>r>>d){
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>sau[i].x>>sau[i].y>>sau[i].r;		
		}	
		for(int i=0;i<n;i++){
			if(sqrt(sau[i].x*sau[i].x+sau[i].y*sau[i].y)-sau[i].r>=(r-d)&&sqrt(sau[i].x*sau[i].x+sau[i].y*sau[i].y)+sau[i].r<=r)	
				sum++;
		}
		cout<<sum<<endl;
	}	
	return 0;	
}
