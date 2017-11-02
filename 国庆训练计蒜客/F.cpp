#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    int W,H,w,h;
    while(~scanf("%d%d%d%d",&W,&H,&w,&h)){
        //if(W>H) swap(W, H);
        //if(w>h) swap(w, h);
        long long ans1 = 0;
        long long ans2 = 0;
        int a = W, b = H;
        bool flag1 = true;
        bool flag2 = true;
        //cout<<a<<" "<<w<<" "<<b<<" "<<h<<endl;
        if(a<w){
            flag1 = false;
        }
        if(b<h){
            flag1 = false;
        }
        long long now = 0;
        while(a>w){
            if(a%2){
                a = a/2 + 1;
            }else{
                a = a/2;
            }
            ++now;
        }
        ans1 += now;
        now = 0;
        while(b>h){
            if(b%2){
                b = b/2 + 1;
            }else{
                b = b/2;
            }
            ++now;
        }
        ans1 += now;
        
        a = W, b = H;
        now = 0;
        if(a<h){
            flag2 = false;
        }
        if(b<w){
            flag2 = false;
        }
        
        while(a>h){
            if(a%2){
                a = a/2 + 1;
            }else{
                a = a/2;
            }
            ++now;
        }
        ans2 += now;
        now = 0;
        while(b>w){
            if(b%2){
                b = b/2 + 1;
            }else{
                b = b/2;
            }
            ++now;
        }
        ans2 += now;
        
        //cout<<flag1<<" "<<flag2<<endl;
        
        if(flag1&&flag2){
            printf("%lld\n",min(ans1,ans2));
        }else if(flag1&&!flag2){
            printf("%lld\n",ans1);
        }else if(!flag1&&flag2){
            printf("%lld\n",ans2);
        }else{
            printf("-1\n");
        }
    }
    
    return 0;
}
