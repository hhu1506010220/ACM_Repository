#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAX=10004;
int fat[MAX];//存放每个节点的根节点
int num[MAX];//记录节点的转移次数
int cnt[MAX];//某点的权值
int find(int x)
{
    while(fat[x]!=x){
		x = fat[x];
		num[x]++;
    }
    return fat[x];
}
void connect(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx!=yy){
        fat[xx]=yy;
        num[xx]++;//开始转移了一次
        cnt[yy]+=cnt[xx];//权值转移了
    }
}

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		memset(num,0,sizeof(num));
		for(int i=0;i<=n;i++){
			fat[i]=i;
		}
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			fat[b]=a;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int temp=fat[i];
			find(i);
			fat[i]=temp; 
//			if(num[i]==k)cnt++;
		}
		for(int i=1;i<=n;i++)
			if(num[i]==k)cnt++;
		printf("%d\n",cnt);
	}
	return 0;	
} 
