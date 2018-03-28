#include<bits/stdc++.h>
using namespace std;

struct hh{
	int id ;
	int time; 
}a[1005];

bool cmp(hh a ,hh b){
	if(a.time==b.time)
		return a.id < b.id;
	return a.time>b.time;	
}

int main(){
	int n;
	cin>>n;
	int t;
	for(int i=0;i<1005;i++)a[i].id=i,a[i].time = 0;
	for(int i=0;i<n;i++){
		cin>>t;
		a[t].time++;
	}
	sort(a,a+1005,cmp);
	for(int i=0;i<n;i++){
		if(!a[i].time){
			break;		
		}
		cout<<a[i].id<<" "<<a[i].time<<endl;
	}
	return 0;	
}
