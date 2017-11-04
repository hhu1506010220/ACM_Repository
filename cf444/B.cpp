#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int f[4][11];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<6;++j)
        {
            int a;
            cin>>a;
            f[i][a]=1;
        }
    }
    int ans=0;
    bool ok=0;
    for(int i=1;i<1000;++i)
    {
        int nn=i;
        int dig=0;
        while(nn>0)dig++,nn/=10;
        nn=i;

        if(dig==1)
        {
            if(f[1][i]==1||f[2][i]==1||f[3][i]==1)
            {
                ans++;
                if(i==1)ok=1;
            }
            else break;
        }
        else if(dig==2)
        {
            int x2=nn%10;
            nn/=10;
            int x1=nn;
            if(f[1][x1]&&f[2][x2] || f[2][x1]&&f[1][x2] || f[1][x1]&&f[3][x2] || f[1][x2]&&f[3][x1] || f[2][x1]&&f[3][x2] || f[3][x1]&&f[2][x2])
            {
                ans++;
            }
            else break;
        }
        else
        {
            int x3=nn%10;
            nn/=10;
            int x2=nn%10;
            nn/=10;
            int x1=nn;
            if(f[1][x1]&&f[2][x2]&&f[3][x3] || f[1][x1]&&f[3][x2]&&f[2][x3] || f[2][x1]&&f[1][x2]&&f[3][x3] || f[2][x1]&&f[3][x2]&&f[1][x3] || f[3][x1]&&f[1][x2]&&f[2][x3] || f[3][x1]&&f[2][x2]&&f[1][x3])
            {
                ans++;
            }
            else break;
        }

    }
    if(ok)
    {
        cout<<ans<<endl;
    }
    else puts("0");
    return 0;
}
