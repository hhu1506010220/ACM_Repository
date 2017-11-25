#include<bits/stdc++.h>
using namespace std;  
struct node{  
    int num;  
    int time;  
};  
bool operator<(node a,node b){  
    return a.time<b.time;  
}  
priority_queue<node> a,b;  
int main(){  
    int n;  
    int casee = 1;  
    while(~scanf("%d",&n)&&n){  
        while(a.size()){  
            a.pop();  
        }  
        while (b.size()) {  
            b.pop();  
        }  
          
        printf("Case #%d:\n",casee);  
        int i,p=0,tem;  
        char s[10],choicee;  
        node now;  
        for(i=1;i<=n;i++){  
            scanf("%s",s);  
            if(s[0]=='p'){  
                getchar();  
                scanf("%c",&choicee);  
                now.time = ++p;  
                if(s[1]=='u'){  
                    scanf("%d",&tem);  
                    now.num = tem;  
                        if(choicee=='A'){  
                            a.push(now);  
                        }else{  
                            b.push(now);  
                        }  
                }else{  
                        if(choicee=='A'){  
                            now = a.top();  
                            printf("%d\n",now.num);  
                            a.pop();  
                        }else{  
                            now = b.top();  
                            printf("%d\n",now.num);  
                            b.pop();  
                        }  
                      
                }  
            }else{  
                char w1,w2;  
                getchar();  
                scanf("%c %c",&w1,&w2);  
                bool flag = false;  
                if(a.size()>b.size()){  
                    swap(a, b);  
                    flag = true;  
                }  
                while(a.size()){  
                    now = a.top();  
                    a.pop();  
                    b.push(now);  
                }  
                  
                if(w1=='A'){  
                    swap(a, b);  
                }else{  
                      
                }  
            }  
        }  
        casee++;  
    }  
    return 0;  
}  
