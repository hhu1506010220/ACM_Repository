#include<bits/stdc++.h>
const int maxn = 1005;
int c[maxn],d[maxn];
int main(){
    int t,n,m,ans,flag;
    scanf("%d",&t);
    while(t--){
        flag = 1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        for(int i=2;i<=n;i++){
            scanf("%d",&d[i]);
        }
        ans = c[1];
        for(int i=2;i<=n;i++){
            ans = ans - d[i]*m;
            if(ans<0){
                flag = 0;break;
            }
            ans += c[i];
        }
        if(flag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
