#include <bits/stdc++.h>
using namespace std;
const int maxn  = 55;
int a[maxn][maxn],b[maxn][maxn],c[maxn];
int main(){
    int t,n,m,t1,t2,x,y,z;
    scanf("%d",&t);
    while(t--){
        x = y = z = 0;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            scanf("%d%d",&t1,&t2);
            a[t1][t2] = 1;
            if(t1>x)
                x = t1;
            if(t2>y)
                y = t2;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&t1,&t2);
            b[t1][t2] = 1;
            if(t2>z)
                z = t2;
        }
        //cout<<x<<y<<z<<endl;
        for(int i=1;i<=x;i++){
            memset(c,0,sizeof(c));
            for(int j=1;j<=y;j++){
                if(a[i][j]){
                    //cout<<"t"<<i<<" "<<j<<endl;
                    for(int k=1;k<=z;k++){
                        if(b[j][k]){
                            //cout<<"t2"<<j<<" "<<k<<endl;
                            c[k] = 1;
                        }
                    }
                }
            }
            for(int j=1;j<=z;j++){
                if(c[j]){
                    printf("%d %d\n",i,j);
                }
            }
        }
        printf("\n");
        
    }
    return 0;
}
