#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 500005;
int per[maxn*4];
struct Node
{
    int istart, iend;
    int sum;
}node[maxn*4];

void build(int x, int y, int num)
{
    node[num].istart = x;
    node[num].iend = y;
    node[num].sum = 0;
    if (x == y)
    {
        node[num].sum = per[x];
        return;
    }
    int mid = (node[num].istart + node[num].iend) / 2;
    build(x, mid, num * 2);
    build(mid + 1, y, num * 2 + 1);
    node[num].sum += node[num * 2].sum + node[num * 2 + 1].sum;
}

void update(int x, int y, int num, int xx)
{
    if (node[num].istart == node[num].iend && node[num].istart == x)
    {
        if (xx == 1)
            node[num].sum += y;
        else
            node[num].sum -= y;
        return;
    }
    int mid = (node[num].istart + node[num].iend) / 2;
    if (x <= mid)
        update(x, y, num * 2, xx);
    else
        update(x, y, num * 2 + 1, xx);
    node[num].sum = node[num * 2].sum + node[num * 2 + 1].sum;
}

int query(int x, int y, int num)
{
    if (x <= node[num].istart && y >= node[num].iend)
    {
        return node[num].sum;
    }
    if (x > node[num].iend || y < node[num].istart)
        return 0;
    return query(x, y, num * 2) + query(x, y, num * 2 + 1);
}
int main()
{
    int n, os = 1;
    scanf("%d", &n);
    while (n--)
    {
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &per[i]);
        build(1, m, 1);
        printf("Case %d:\n", os++);
        memset(per, 0, sizeof(per));
	    char s[10];
	    int a, b;
	    while (cin >> s)
	    {
	        if (s[0]=='E')
	            break;
	        scanf("%d %d", &a, &b);
	        if (s[0]=='Q')
	        {
	            printf("%d\n", query(a, b, 1));
	        }
	        if (s[0]=='A')
	        {
	            update(a, b, 1, 1);
	        }
	        if (s[0]=='S')
	        {
	            update(a, b, 1, 0);
	        }
	    }
    }
    return 0;
}
