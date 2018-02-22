#include<cstdio>
 
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        if(n%2) printf("%d\n",n-1);
        else puts("No Solution!");
    }
    return 0;
}
