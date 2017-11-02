#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include <queue>  
#define maxn 30005
using namespace std;  
int map[3100][3100];//前驱数量 
int indegree[3100];
int que[300];//保存拓扑序列 
void topo(int n)
{
    int i,j,m,t=0;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(indegree[i]==0){//找出前驱数量为零的的点即每次找到第一名 
                m=i;break;
            }
        }
        que[t++]=m;indegree[m]=-1;//将第一名的前驱数量设为-1 
        for(i=1;i<=n;++i){//第二步将前驱中含有第一名的点前驱数量减1 
            if(map[m][i])indegree[i]--;
        }
    }
    printf("%d",que[0]);//输出拓扑序列 
    for(i=1;i<n;++i){
        printf(" %d",que[i]);
    }
    printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,m,i,j,a,b;
	    scanf("%d%d",&n,&m);
        memset(indegree,0,sizeof(indegree));//初始化 
        memset(map,0,sizeof(map));
        for(i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            if(map[a][b]==0){ //避免重复的数据输入 
                map[a][b]=1;indegree[b]++;//第一步记录关系和点的前驱数量 
            }
        }
        topo(n);//调用拓扑排序 
	}
    return 0;
}
