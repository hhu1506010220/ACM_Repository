#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 505;
#define ll long long
struct Node{
    int d;
    int x1,x2;
    int id;
}edge[maxn];
ll cost[maxm];
int main(){
    int n,m,a,b,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&edge[i].d);
        edge[i].x1 = edge[i].x2 = 0;
        while(scanf("%d",&a)){
            if(a==-1)
                break;
            scanf("%d",&b);
            if(b<edge[i].d) continue;
            if(b>edge[i].x1){
                edge[i].x2 = edge[i].x1;
                edge[i].x1 = b;
                edge[i].id = a;
            }else if(b==edge[i].x1){
                edge[i].x2 = b;
                if(edge[i].id>a)
                    edge[i].id=a;
            }else if(edge[i].x2<b){
                edge[i].x2 = b;
            }
        }
    }
    //double t;
    memset(cost,0,sizeof(cost));
    for(int i=1;i<=n;i++){
        //cout<<edge[i].id<<" "<<edge[i].d<<" "<<edge[i].x1<<" "<<edge[i].x2<<endl;
        if(edge[i].d>edge[i].x1){
            continue;
        }
        if(edge[i].x2<edge[i].d){
            cost[edge[i].id] += min((int)(edge[i].d*1.1),edge[i].x1);
        }else{
            cost[edge[i].id] += min((int)(edge[i].x2*1.1),edge[i].x1);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        printf("%lld\n",cost[a]);
    }
    return 0;
}
