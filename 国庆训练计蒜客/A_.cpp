#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int w,h,ax,ay,bx,by;
    while(~scanf("%d%d%d%d%d%d",&w,&h,&ax,&ay,&bx,&by)){
        int sx, sy, ex, ey;
        if(ax==bx){
            sx = 0, sy = ay;
            ex = w, ey = by;
        }else if(ay==by){
            sx = ax, sy = 0;
            ex = bx, ey = h;
        }else{
            sx = ax, sy = 0;
            ex = bx, ey = h;
        }
        printf("%d %d %d %d\n",sx, sy, ex, ey);
        
    }
    return 0;
}
