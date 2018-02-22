#include <bits/stdc++.h>
 
using namespace std;
 
void cal(char s[], long long num[]) {
    long long i, j, k, n, t, m = atoll(s);//atoi(s).把字符串转换成整型数。ASCII to long longeger 的缩写。
//    cout<<m<<endl;
	n = (long long) strlen(s);
    for (i = k = 1; i < n; i++)
        k *= 10, num[0] -= k;
    for (i = 0; i < n; i++, k /= 10) {
        for (j = 0; j < s[i] - '0'; j++)
            num[j] += k;
        for (t = 0; t < 10; t++)
            num[t] += k / 10 * (n - i - 1) * j;
        if (i + 1 < n)
            num[j] += atoll(s + i + 1);
        num[j]++;
    }
}
 
int main() {
    long long n, m;
    long long a[11], b[11];
    char str[1000000];
    long long t;
    scanf("%lld",&t);
    while(t--){
    	scanf("%lld%lld", &n, &m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
 
        if (n > m) {
            printf("0\n");
            continue;
        }

        sprintf(str, "%lld", n - 1); //将格式化的数据写入某个字符串
 
        cal(str, a);
 
        sprintf(str, "%lld", m);
 
        cal(str, b);

		long long res = 0; 
        for (long long i = 0; i < 10; ++i) {
        	if(i==0||i==4||i==6||i==9)res+=(b[i] - a[i]);
			else if(i==8)res+=(2*(b[i] - a[i]));
			else res+=0;
        }
        printf("%lld\n",res);
    }
 
    return 0;
}

