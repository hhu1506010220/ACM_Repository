#include<bits/stdc++.h>
#define MAXN 1000005
#define pii pair<int,int>
#define ll long long
using namespace std;
int n;
int cnt=1;
int a[MAXN];
pii t[MAXN];
ll dat[MAXN];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if('-'==ch)f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*f;
}
struct BigInt{
    int a[105];
    int len;
    BigInt(){
        memset(a,0,sizeof(a));
        len=1;
    }
    void Add(ll b){
        int t[105]={0};
        int L=0;
        while(b){
            t[++L]=b%10;
            b/=10;
        }
        len=max(len,L);
        for(int i=1;i<=len;i++){
            a[i]+=t[i];
        }
        for(int i=1;i<=len;i++){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        if(a[len+1]){
            len++;
        }
    }
    void Print(){
        for(int i=len;i>=1;i--){
            printf("%d",a[i]);
        }
        printf("\n");
    }
};
void add(int k,int x){
    while(k>=1){
        dat[k]+=x;
        k-=(k&-k);
    }
}
ll query(int k){
    ll ret=0;
    while(k<=cnt){
        ret+=dat[k];
        k+=(k&-k);
    }
    return ret;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        t[i]=make_pair(a[i],i);
    }    
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++){
        if(t[i-1].first!=t[i].first){
            cnt++;
        }
        a[t[i].second]=cnt;
    }
    BigInt ans;
    for(int i=1;i<=n;i++){
        ans.Add(query(a[i]+1)*1LL*(n-i+1));
        add(a[i],i);
    }
    ans.Print();
    return 0;
}
