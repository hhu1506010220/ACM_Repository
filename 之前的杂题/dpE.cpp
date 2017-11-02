#include <stdio.h>
#include <string.h>
int Cap(char c){
    return c>='A'&&c<='Z';
}
int main(){
    int n,len,c;
    int i,j;
    char s[105];
    int caplock;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        c=len=strlen(s);
        caplock=0;
        for(i=0;i<len;i++){
            int t=Cap(s[i]);
            for(j=i+1;j<len;j++){
                if(t!=Cap(s[j]))break;
            }
            if(t==1&&caplock==0&&j-i<2)//只有一个大写字母，Cap键没有按下
                c++;//按shift键
            else if(t==1&&caplock==0&&j-i>=2)//有多于1个大写字母，Cap键没有按下
                c++,caplock=1;//按下Cap键
            else if(t==0&&caplock==1&&j-i<2&&j==len)//结尾有一个小写字母，Cap已经按下
                c++,caplock=0;//按下Cap键
            else if(t==0&&caplock==1&&j-i<2)//Cap已经按下，出现一个小写字母
                c++;//按shift键
            else if(t==0&&caplock==1&&j-i>=2)//Cap已经按下，出现多个小写字母
                c++,caplock=0;//按下Cap键
            i=j-1;
        }
        if(caplock)c++;
        printf("%d\n",c);
    }
}
