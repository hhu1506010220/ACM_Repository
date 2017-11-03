#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include <queue>  
#define maxn 30005
using namespace std;  
int map[3100][3100];//ǰ������ 
int indegree[3100];
int que[300];//������������ 
void topo(int n)
{
    int i,j,m,t=0;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            if(indegree[i]==0){//�ҳ�ǰ������Ϊ��ĵĵ㼴ÿ���ҵ���һ�� 
                m=i;break;
            }
        }
        que[t++]=m;indegree[m]=-1;//����һ����ǰ��������Ϊ-1 
        for(i=1;i<=n;++i){//�ڶ�����ǰ���к��е�һ���ĵ�ǰ��������1 
            if(map[m][i])indegree[i]--;
        }
    }
    printf("%d",que[0]);//����������� 
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
        memset(indegree,0,sizeof(indegree));//��ʼ�� 
        memset(map,0,sizeof(map));
        for(i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            if(map[a][b]==0){ //�����ظ����������� 
                map[a][b]=1;indegree[b]++;//��һ����¼��ϵ�͵��ǰ������ 
            }
        }
        topo(n);//������������ 
	}
    return 0;
}
