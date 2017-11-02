/**********************************/
/* 求两个串的最长公共前缀及其长度 */
/**********************************/
#include <bits/stdc++.h>  
using namespace std;  
typedef unsigned long long int ULL;  
const int SIZE = 100003;  
const int SEED = 13331;  
const int maxn = 600100;  
char a[maxn],b[maxn],s[maxn];  
ULL H[maxn];  
ULL XL[maxn];  
int len;  
void build(char *s){  
    len=strlen(s);  
    H[len]=0;  
    XL[0]=1;  
    for (int i=len-1;i>=0;i--){  
        H[i]=H[i+1]*SEED+s[i];  
        XL[len-i]=XL[len-i-1]*SEED;  
    }  
}  
ULL hashh(int i,int L){  
    return H[i]-H[i+L]*XL[L];  
}  
int lcp(int i,int j){  
    int l=0,r=min(len-i,len-j);  
    int res=0;  
    while (l<=r){  
        int mid=(l+r)/2;  
        if (hashh(i,mid)==hashh(j,mid)){  
            res=mid;  
            l=mid+1;  
        }  
        else{  
            r=mid-1;  
        }  
    }  
    return res;  
}  
int main()  
{  
    while(~scanf("%s%s",a,b))  
    {  
        memset(s,0,sizeof(s));  
        int n=strlen(a);  
        int m=strlen(b);  
        for(int i=0;i<n;i++)  
            s[i]=a[i];  
        s[n]='$';  
        for(int j=0;j<m;j++)  
            s[j+1+n]=b[j];  
        len=strlen(s);  
        build(s);  
        //printf("%s\n",s);  
        int flag=1;  
        for(int i=n+1;i<len;i++)  
        {  
            //printf("%d ",lcp(0,i));  
            if(lcp(0,i)==len-i)  
            {  
                for(int j=i;j<len;j++)  
                    printf("%c",s[j]);  
                printf(" %d\n",len-i);  
                flag=0;  
                break;  
            }  
        }  
        if(flag)  
            printf("0\n");  
    }  
    return 0;  
}  
