#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long ll;
struct point{
    int x,y;
};
int area(point a,point b,point c){
    return abs((a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y));
}
bool judge(point p,point a,point b,point c){
    if(area(p,a,b)+area(p,b,c)+area(p,a,c)==area(a,b,c))return true;
    return false;
}
int main(){
    point p,a,b,c;
    while(scanf("%d%d%d%d%d%d%d%d",&p.x,&p.y,&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF){
        if(judge(p,a,b,c))printf("Yes\n");
        else printf("No\n");
    }
}
