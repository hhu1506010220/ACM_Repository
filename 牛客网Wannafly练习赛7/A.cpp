#include<bits/stdc++.h>
using namespace std;

int a[7],b[7];

int main(){
    int t ,cnt1,cnt2;
    scanf("%d",&t);
    while(t--){
        cnt1 = cnt2 = 0;
        for(int i=0;i<6;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<6;i++)
            scanf("%d",&b[i]);
        sort(a,a+6);
        sort(b,b+6);
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++){
                if(a[i]>b[j])
                    cnt1++;
                else if(a[i]==b[j])
                    cnt2++;
            }
       int cnt3 = 36-cnt1-cnt2;
       if(cnt1==cnt3)
           puts("Tie");
        else if(cnt1>cnt3)
           puts("Alice");
        else if(cnt1<cnt3)
            puts("Bob");
    }
    return 0;
}
