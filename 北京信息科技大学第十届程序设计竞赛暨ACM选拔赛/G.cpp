#include<bits/stdc++.h>
using namespace std;
  
char s[1005][10];
int main(){
    int T,n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        bool f=0;
        for(int i=0;i<n;i++){
            if(s[i][0]==s[i][1]&&s[i][0]=='O'){
                s[i][0]=s[i][1]='+';
                f=1;
                break;
            }
            if(s[i][3]==s[i][4]&&s[i][3]=='O'){
                s[i][3]=s[i][4]='+';
                f=1;
                break;
            }
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            for(int i=0;i<n;i++){
                printf("%s\n",s[i]);
            }
        }
    }
    return 0; 
}
