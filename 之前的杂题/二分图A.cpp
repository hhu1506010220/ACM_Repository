#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
//#include<ctype.h>
using namespace std;
typedef long long ll;
//typedef pair<int, int> P;

/*
	Dinic�㷨�����Ӷ�O(V^2E)
	����Ѱ����̵�����·��������������
	ʵ�������ٶȿ죬��������ģ�� 
*/

const int inf = 2147483647;
const double eps = 1e-8;
const int maxn = 505;
const ll mod = 1e9+7;

struct edge{
	int to, cap, rev;
}; 

vector<edge> G[maxn];
int level[maxn];		//������������ 
int iter[maxn];			//iter���Ա����û���õı߽��ж�μ�� 

void addedge(int from, int to, int cap){
	G[from].push_back((edge){to, cap, (int)G[to].size()});
	G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

//����ֲ�ͼ 
void bfs(int s){
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[s] = 0;
	q.push(s);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i=0; i<G[v].size(); i++){
			edge &e = G[v][i];
			if(e.cap>0 && level[e.to]<0){	//����������0�һ�Ϊ�������� 
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
} 

//dfsѰ������· 
int dfs(int v, int t, int f){
	if(v == t) return f;							//�Ѿ������յ�t 
	for(int &i = iter[v]; i<G[v].size(); i++){		//i��iter[v]����ʼ��飬&���޸�iʱ��iterҲ���޸� 
		edge &e = G[v][i];
		if(e.cap > 0 && level[v]<level[e.to]){		//�����㣬������v����һ�� 
			int d = dfs(e.to, t, min(f, e.cap));
			if(d>0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d; 
			}
		}
	}
	return 0;
}

int max_flow(int s, int t){
	int flow = 0;
	for( ;; ){
		bfs(s);							//�����ֲ�ͼ 
		if(level[t]<0) return flow;		//���յ�ķֲ�ͼ�Ѿ��첻�����ˣ������������� 
		memset(iter, 0, sizeof(iter));	
		int f;
		while((f = dfs(s, t, inf))>0){
			flow += f;
		}
	}
}

int main(){
	int n, m;
	while(~scanf("%d%d", &m, &n)){
		//ע���±�ת�ɴ�0��ʼ 
		memset(level,0,sizeof(level));
		memset(iter,0,sizeof(iter));
		for(int i=0;i<=n;i++)G[i].clear();
		for(int i=0; i<m; i++){
			int u, v, cap;
			scanf("%d%d%d", &u, &v, &cap);
			addedge(--u, --v, cap); 
		} 
		int ans = max_flow(0, n-1);
		printf("%d\n", ans);	
	}
	return 0;
} 

