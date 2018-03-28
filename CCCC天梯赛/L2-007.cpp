#include<bits/stdc++.h>
using namespace std;

struct m {
	double aver_num,aver_area;
	int id,num,area,peo;
	int fu,mu;
	m(){
		aver_num = aver_area = 0;
		id = num = area = peo = fu = mu = 0;	
	}
} p[10005],ans[10005];

bool cmp(m a,m b) {
	if(a.aver_area == b.aver_area) {
		return a.id < b.id;
	}
	return a.aver_area > b.aver_area;
}

int pre[10005];

int find(int x) {
	int r = x;
	while(r!=pre[r]) r = pre[r];
	int i = x,j;
	while(pre[i]!=r) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void merge(int x,int y) {
	int fx = find(x);
	int fy = find(y);
	if(fx>fy)
		pre[fx] = fy;
	else
		pre[fy] = fx;
}


int main() {
	int n;
	int cnt =0;
	int bianhao,fu,mu,k,tem,house,totalarea;
	scanf("%d",&n);
	for(int i=0; i<10005; i++)pre[i]=i;
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d%d",&p[i].id,&p[i].fu,&p[i].mu,&k);
		if(p[i].fu!=-1)
			merge(p[i].id,p[i].fu);
		if(p[i].mu!=-1)
			merge(p[i].id,p[i].mu);
		for(int j=0; j<k; j++) {
			scanf("%d",&tem);
			merge(p[i].id,tem);
		}
		scanf("%d%d",&p[i].num,&p[i].area);
	}
	for(int i=1; i<=n; i++) {
		int nn = find(p[i].id);
		ans[nn].id = nn;
		ans[nn].area += p[i].area;
		ans[nn].num += p[i].num;
		ans[nn].fu = -1;
	}
	for(int i=0; i<10005; i++) {  
        ans[find(i)].peo++;
        if(ans[i].fu == -1){  
            cnt++;  
        }  
    } 
	for(int i=0; i<10005; i++) {
		if(ans[i].fu == -1) {
			ans[i].aver_area = (double)ans[i].area/ans[i].peo;
		}
	}
	sort(ans,ans+10005,cmp);
	printf("%d\n",cnt);
	for(int i=0; i<cnt; i++){  
        printf("%.4d %d %.3lf %.3lf\n",ans[i].id,ans[i].peo,(double)ans[i].num/ans[i].peo,ans[i].aver_area);  
    }  


	return 0;
}
