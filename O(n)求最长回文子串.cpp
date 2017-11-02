/**********************************/
/* Manacher O(n)��������Ӵ�����*/
/**********************************/
#include <bits/stdc++.h>  
using namespace std;  
  
const int N = 1000005;  
char str[N];    //ԭ�ַ���  
char s[N << 1];       //��'#'��Ϊ������֮����ַ���  
int p[N << 1];        //p[i]��ʾ�Ե�i���ַ�Ϊ���ĵĻ����Ӵ��ĳ��ȼ�1  
int len;  
int ans;    //������Ӵ��ĳ���  
  
void Manacher()  
{  
    int i;  
    int mx; //mx��ʾ��ǰ�����Ӵ���չ�����Ҷ�  
    int id; //id��ʾmx�����ĸ������Ӵ���չ������  
    len = (strlen(str) + 1) << 1;  
    for (i = 0; i < len; ++i)    //��������ַ���  
    {  
        s[i] = '#';  
        p[i] = 0;  
    }  
    for (i = 0; str[i] != 0; ++i) s[(i + 1) << 1] = str[i];  
    s[(i + 1) << 1] = 0;  
    mx = 0;  
    ans = 0;  
    for (i = 1; s[i] != 0; ++i) //���p����  
    {  
        if (mx > i) p[i] = min(mx - i, p[(id << 1) - i]);  
        else p[i] = 1;  
        while (s[i - p[i]] == s[i + p[i]]) ++p[i];  
        if (i + p[i] > mx)  
        {  
            mx = i + p[i];  
            id = i;  
        }  
        if (p[i] - 1 > ans) ans = p[i] - 1;  //����������Ӵ��ĳ���  
    }  
}  
  
int main()  
{  
    int Case = 0;  
    while (scanf("%s", str) != EOF)  
    {  
        if (strcmp(str, "END") == 0) break;  
        Manacher();  
        printf("Case %d: %d\n", ++Case, ans);  
    }  
    return 0;  
}  
