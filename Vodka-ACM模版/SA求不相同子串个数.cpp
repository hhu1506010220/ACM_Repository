/**********************************/
/*     SA求不相等的子串的个数     */
/* 全部前缀个数-前缀相同部分height*/
/* 全部前缀个数可以写成(1+n)*n/2  */
/**********************************/
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
const int MAXN=1010;  
int sa[MAXN];//sa[i]表示排在第i名的下标是多少,取值范围[1~n]  
int rank[MAXN];//rank[i]表示以i为下标的后缀排在第几,取值范围[0~n-1]  
int height[MAXN];//height[i]表示排在i-1名与排在第i名的最长公共前缀,取值范围[2~n]  
int t1[MAXN],t2[MAXN],c[MAXN];//求sa数组需要的中间变量,不需要赋值初始化  
int s[MAXN];  
//待排序的字符串放在s数组中,从s[0]到s[n-1],长度为n,且最大值小于m.  
//除s[n]为0 外的所有s[i]都大于0;函数结束以后结果放在sa数组中  
void build_sa(int s[],int n,int m) //得到SA数组  
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
void getHeight(int s[],int n){ //得到height数组  
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
