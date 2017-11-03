#include <bits/stdc++.h>
using namespace std;
const int N=3e4+5;
typedef long long ll;
const int mod=1e9+7;
int n,m,ind[N],u,v,ans[N];
priority_queue<int>qu;
vector<int>ve[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            ve[i].clear();
            ind[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            ve[v].push_back(u);
            ind[u]++;
        }
        int cnt=n;
        for(int i=1;i<=n;i++)
        {
            if(!ind[i])qu.push(i);
        }
        while(!qu.empty())
            {
                int fr=qu.top();
                ans[cnt--]=fr;
                qu.pop();
                int len=ve[fr].size();
                for(int i=0;i<len;i++)
                {
                    int y=ve[fr][i];
                    ind[y]--;
                    if(!ind[y])qu.push(y);
                }
            }
        for(int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}
