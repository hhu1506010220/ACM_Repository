#include<bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
}p[105];
int vis[1005]={0};
pair <int,int> pr,prr;
map< pair<int,int> ,int>m;

bool cmp(point a,point b){
	if(a.x==b.x)
		return a.y<=b.y;
	else
		return a.x<b.x;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;	
	}
	sort(p,p+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<p[i].x<<" "<<p[i].y<<endl;	
//	}
	int cnt1 = n-1 ,cnt2 = n-1;
	
	//ºá×ÅxÕÒ 
	for(int i=0;i<n;i++){
		vis[p[i].x]++;
	}
	for(int i=1;i<=1000;i++){
		if(vis[i]>=2){
			cnt1 -= (vis[i]-1);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		vis[p[i].y]++;
	}
	for(int i=1;i<=1000;i++){
		if(vis[i]>=2){
			cnt1 -= (vis[i]-1);
		}
	}
	cout<<max(0,cnt1)<<endl;
}
