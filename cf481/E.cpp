#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,w;
	int cur;
	cin>>n>>w;
	int sum=0;
	int maxn=0;
	int minn=0;
	for(int i=0; i<n; i++) {
		cin>>cur;
		sum+=cur;
		maxn=max(sum,maxn);// 最多可再上人数
		minn=min(minn,sum);// 最多可再下人数
	}
	if(maxn>w||minn<-w)
		cout<<"0"<<endl;
	else {
		if(maxn<0) //如果maxn小于0 表示一直都得下人，所以初始人数是 |minn|~w和|maxn|~w的交集 
			cout<<minn+w+1<<endl;
		else if(minn<0) {
			//如果maxn>0minn<0，minn表示原始人数是|min|~w，maxn表示原始人数是0~|w-maxn|。二者求交集 
			if(w-maxn-abs(minn)>=0)
				cout<<w-maxn-abs(minn)+1<<endl;
			else
				cout<<"0"<<endl;
		} else {
			cout<<w-maxn+1<<endl;
		}
	}
	return 0;
}
