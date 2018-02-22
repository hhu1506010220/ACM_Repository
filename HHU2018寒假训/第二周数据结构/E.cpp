#include<bits/stdc++.h>
using namespace std;

struct nod{	
	int WorkTime,Qnum,Period;
	bool operator < (nod const &b) const{
		if(WorkTime>b.WorkTime)
			return 1;
		else if(WorkTime==b.WorkTime&&Qnum>b.Qnum)
			return 1;
		else return 0;
	}
}node[10005];

int main() {
	int w,k;
	char s[20];
	priority_queue<nod>pq;
	nod temp;
	while(scanf("%s",&s)&&s[0]!='#'){
		scanf("%d%d",&temp.Qnum,&temp.Period);
		temp.WorkTime = temp.Period;
		pq.push(temp);
	}
	scanf("%d",&k);
	while(k--){
//		if(!pq.empty()){
		nod ans = pq.top();
		pq.pop();
		printf("%d\n",ans.Qnum);
		ans.WorkTime += ans.Period;
		pq.push(ans);
	}
	return 0;
}
