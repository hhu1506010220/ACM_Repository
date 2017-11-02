#include <bits/stdc++.h>
using namespace std;

const int MO=1000000007;
int C[1005][1005];

void init()
{
    for (int i=0;i<=1000;i++) {
        C[i][0]=1;
        for (int j=1;j<=i;j++) {
            C[i][j]=((long long)C[i-1][j-1]+C[i-1][j])%MO;
        }
    }
}

int main()
{
    init();
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        printf("%d\n",C[max(n,m)][min(n,m)]);
    }
    return 0;
}



