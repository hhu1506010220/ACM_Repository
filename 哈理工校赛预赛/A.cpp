#include<bits/stdc++.h>
using namespace std;
map<int ,int>m;
int main(){
    int t,n,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m.clear();
        int tm;
        for(int i=1;i<=n;i++){
            scanf("%d",&tm);
            m[tm]++;
        }
        map<int,int> :: iterator it;
        sum=0;
        for(it=m.begin();it!=m.end();it++){
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
} 
