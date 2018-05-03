#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        double sum = 0;
        sum = 1.0*n*n;
        sum -= 1;
        sum /= 3;
        printf("%.12lf\n",sum);
    }
    return 0;
}
