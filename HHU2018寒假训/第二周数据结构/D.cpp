#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , ans;
	queue<int>q;
	stack<int>s;
	priority_queue<int>pq;
	bool flag[3]={1};
	int a, b ,cnt;
	while(~scanf("%d",&n)){
		while(!q.empty())q.pop();
		while(!s.empty())s.pop();
		while(!pq.empty())pq.pop();
		for(int i=0;i<3;i++)flag[i]=1;
		cnt = 0;
		while(n--){
			scanf("%d%d",&a,&b);
			if(a==1){
				q.push(b);
				s.push(b);
				pq.push(b);	
			}
			else{
				//queue 
				if(flag[0]&&!q.empty()){
					ans = q.front();
					q.pop();	
					if(ans!=b)flag[0]=0;
				}
				else if(flag[0]&&q.empty()){
					flag[0]=0;
				}
				
				//stack 
				if(flag[1]&&!s.empty()){
					ans = s.top();
					s.pop();
					if(ans!=b)flag[1]=0;	
				}
				else if(flag[1]&&s.empty()){
					flag[1]=0;
				}
				//pq
				if(flag[2]&&!pq.empty()){
					ans = pq.top();
					pq.pop();
					if(ans!=b)flag[2]=0;
				}
				else if(flag[2]&&pq.empty()){
					flag[2]=0;
				}
			}
		}	
		for(int i=0;i<3;i++){
			if(flag[i]){
//				cout<<i<<"!!!"<<endl;
				cnt++;	
			}
		}
		if(cnt==0){
			puts("impossible");
		}
		else if(cnt==1){
			for(int i=0;i<3;i++){
				if(flag[0]){
					puts("queue");
					break;
				}
				if(flag[1]){
					puts("stack");
					break;
				}
				if(flag[2]){
					puts("priority queue");
					break;
				}
			}
		}
		else if(cnt>1){
			puts("not sure");
		}
	}
	return 0;	
}
