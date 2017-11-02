#include<bits/stdc++.h>
using namespace std;
template <class T>
inline void scan_d(T &ret) 
{
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
const int maxn = 1e6+5;
int a[maxn],b[maxn];
int main(){
	int t,n,m,p;
	scanf("%d",&t);

	int cnn=1;
	int kase =0;
	while(t--){
		scanf("%d%d%d",&n,&m,&p);
		for(int i=1;i<=n;i++){
			scan_d(a[i]);
		}
		for(int i=1;i<=m;i++){
			scan_d(b[i]);
		}
		int flag ,ans = 0;
		for(int i=1;i<=n-(m-1)*p;i++){
			flag = 1;
			for(int j=1;j<=m;j++){
				if(a[i+(j-1)*p]==b[j])
					continue;
				else{
					flag = 0;
					break;
				}
			}
			if(flag)
				ans++;
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	return 0;	
}
