#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAX=10004;
int fat[MAX];//���ÿ���ڵ�ĸ��ڵ�
int num[MAX];//��¼�ڵ��ת�ƴ���
int cnt[MAX];//ĳ���Ȩֵ
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
        num[xx]++;//��ʼת����һ��
        cnt[yy]+=cnt[xx];//Ȩֵת����
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
