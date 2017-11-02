#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int a[105],b[105],x,y,z;
    while(scanf("%d",&t)&&t!=0){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<t;i++){
            scanf("%d%d%d",&x,&y,&z);
            a[x] += z;
            b[y] += z;
            //cout<<x<<" "<<y<<" "<<z<<endl;
        }
        int maxx,temp;
        maxx = temp = 0;
        for(int i=1;i<=100;i++){
            temp += a[i];
            temp -= b[i];
            if(temp>maxx){
                maxx = temp;
            }
        }
        printf("%d\n",maxx);
    }
    printf("*\n");
    return 0;
}
