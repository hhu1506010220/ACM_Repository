#include <bits/stdc++.h>
using namespace std;
#define ms(a,b) memset(a,b,sizeof(a))
const int maxn = 10005;
int n,m,ip,a,b,scnt,ind;
int head[maxn],DFN[maxn],LOW[maxn],instack[maxn],belong[maxn],in[maxn],out[maxn];
stack<int> t;
struct Node{
    int v,next;
}edge[100005];
void init(){
    ip = 0;
    scnt = 0;
    ind = 0;
    ms(head,-1);
    ms(DFN,0);
    ms(LOW,0);
    ms(instack,0);
    while(!t.empty()){
        t.pop();
    }
}
void addedge(int a,int b){
    edge[ip].v=b;
    edge[ip].next=head[a];
    head[a] = ip++;
}
void tarjan(int u){
    DFN[u] = LOW[u] = ++ind;
    //int top = 0;
    
    int te;
    t.push(u);
    instack[u] = 1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v = edge[i].v;
        if(!DFN[v]){
            tarjan(v);
            if(LOW[u]>LOW[v]) LOW[u] = LOW[v];
        }else if(instack[v]&&DFN[v]<LOW[u]){
            LOW[u] = DFN[v];
        }
    }
    if(DFN[u]==LOW[u]){
        scnt++;
        while(1){
            te = t.top();
            t.pop();
            instack[te] =  0;
            belong[te] = scnt;
            if(te==u) break;
        }
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        if(!DFN[i]){
            tarjan(i);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            addedge(a, b);
        }
        solve();
        if(scnt==1){
            printf("0\n");
        }else{
            for(int i=1;i<=scnt;i++){
                in[i] = out[i] = 1;
            }
            int v;
            for(int i=1;i<=n;i++){
                for(int j=head[i];j!=-1;j=edge[j].next){
                    v = edge[j].v;
                    if(belong[i]!=belong[v]){
                        in[belong[v]] = 0;
                        out[belong[i]] = 0;
                    }
                }
                
            }
            a = b = 0;
            for(int i=1;i<=scnt;i++){
                if(in[i]) a++;
                if(out[i]) b++;
            }
            printf("%d\n",max(a,b));
        }
    }
    return 0;
}
