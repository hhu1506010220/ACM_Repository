#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	int num,step;
} nod,ans;
int vis[1000005];

ll a,b;
ll f(ll x) {
	ll sum=0;
	while(x) {
		sum++;
		x=x&(x-1);
	}
	return sum;
}
void bfs() {
	queue<node> que;
	node tem,p;
	node tt;
	tem.num = a,tem.step=0;
	que.push(tem);
	while (!que.empty()) {
		bool flag = 1;
		p = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			if(i==0)tt.num = p.num+1;
			else if(i==1)tt.num = p.num-1;
			else if(i==2)tt.num = p.num+f(p.num);
			else tt.num = p.num - f(p.num);
			tt.step = p.step +1;
			if (tt.num == b) {
				ans = tt;
				flag = 0;
				break;
			} else if(tt.num>=0&&!vis[tt.num]) {
				que.push(tt);
				vis[tt.num] = 1;
			}
		}
		if(flag==0)
			break;
	}
}
int main() {
	cin>>a>>b;
	bfs();
	cout<<ans.step<<endl;
	return 0;
}
