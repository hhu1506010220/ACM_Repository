#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 20005;
char s[maxn];
int n;

int main()  {
    cin>>n;
    scanf("%s",s);
    bool flag = 1;
    int tot = 0;
    for(int i=0;i<n;i++)  {
        if(s[i]=='1'&&(s[i+1]=='1'||s[i-1]=='1'))  {
            flag = false;
            break;
        }
        if(s[i]=='0'&&(i==0||s[i-1]=='0')&&(i==n-1||s[i+1]=='0')) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        cout<<"No"<<endl;
    }
    else
        cout<<"Yes"<<endl;
    return 0;
}
