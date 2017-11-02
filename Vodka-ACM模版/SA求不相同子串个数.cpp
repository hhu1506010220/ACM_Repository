/**********************************/
/*     SA����ȵ��Ӵ��ĸ���     */
/* ȫ��ǰ׺����-ǰ׺��ͬ����height*/
/* ȫ��ǰ׺��������д��(1+n)*n/2  */
/**********************************/
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
const int MAXN=1010;  
int sa[MAXN];//sa[i]��ʾ���ڵ�i�����±��Ƕ���,ȡֵ��Χ[1~n]  
int rank[MAXN];//rank[i]��ʾ��iΪ�±�ĺ�׺���ڵڼ�,ȡֵ��Χ[0~n-1]  
int height[MAXN];//height[i]��ʾ����i-1�������ڵ�i���������ǰ׺,ȡֵ��Χ[2~n]  
int t1[MAXN],t2[MAXN],c[MAXN];//��sa������Ҫ���м����,����Ҫ��ֵ��ʼ��  
int s[MAXN];  
//��������ַ�������s������,��s[0]��s[n-1],����Ϊn,�����ֵС��m.  
//��s[n]Ϊ0 �������s[i]������0;���������Ժ�������sa������  
void build_sa(int s[],int n,int m) //�õ�SA����  
{  
    int i,j,p,*x=t1,*y=t2;  
    for(i=0;i<m;i++)c[i]=0;  
    for(i=0;i<n;i++)c[x[i]=s[i]]++;  
    for(i=1;i<m;i++)c[i]+=c[i-1];  
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;  
    for(j=1;j<=n;j<<=1){  
        p=0;  
        for(i=n-j;i<n;i++)y[p++]=i;  
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;  
        for(i=0;i<m;i++)c[i]=0;  
        for(i=0;i<n;i++)c[x[y[i]]]++;  
        for(i=1;i<m;i++)c[i]+=c[i-1];  
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];  
        swap(x,y);  
        p=1;x[sa[0]]=0;  
        for(i=1;i<n;i++)  
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;  
        if(p>=n)break;  
        m=p;  
    }  
}  
void getHeight(int s[],int n){ //�õ�height����  
    int i,j,k=0;  
    for(i=0;i<=n;i++)rank[sa[i]]=i;  
    for(i=0;i<n;i++){  
        if(k)k--;  
        j=sa[rank[i]-1];  
        while(s[i+k]==s[j+k])k++;  
        height[rank[i]]=k;  
    }  
}  
int main()  
{  
    int n,t;  
    char ss[MAXN];  
    scanf("%d",&t);  
    while(t--){  
        scanf("%s",ss);  
        n=strlen(ss);  
        int Max=-1;  
        for(int i=0;i<n;i++){  
            s[i]=ss[i];  
            if(s[i]>Max)Max=s[i];  
        }  
        s[n]=0;  
        build_sa(s,n+1,Max+1);  
        getHeight(s,n);  
        int ans=(1+n)*n/2;  
        for(int i=2;i<=n;i++){  
            ans-=height[i];  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
