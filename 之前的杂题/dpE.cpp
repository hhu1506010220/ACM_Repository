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
            if(t==1&&caplock==0&&j-i<2)//ֻ��һ����д��ĸ��Cap��û�а���
                c++;//��shift��
            else if(t==1&&caplock==0&&j-i>=2)//�ж���1����д��ĸ��Cap��û�а���
                c++,caplock=1;//����Cap��
            else if(t==0&&caplock==1&&j-i<2&&j==len)//��β��һ��Сд��ĸ��Cap�Ѿ�����
                c++,caplock=0;//����Cap��
            else if(t==0&&caplock==1&&j-i<2)//Cap�Ѿ����£�����һ��Сд��ĸ
                c++;//��shift��
            else if(t==0&&caplock==1&&j-i>=2)//Cap�Ѿ����£����ֶ��Сд��ĸ
                c++,caplock=0;//����Cap��
            i=j-1;
        }
        if(caplock)c++;
        printf("%d\n",c);
    }
}
