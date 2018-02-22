#include<bits/stdc++.h>
using namespace std;

int a[1005];
stack<int>s;

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		while(~scanf("%d",&a[0])&&a[0]){
			int _top=0;
			for(int i=1;i<n;i++)
				scanf("%d",&a[i]);
			for(int i=1;i<=n;i++){
				s.push(i);
				while(!s.empty()&&s.top()==a[_top]){
                    s.pop();
                    _top++;
                }
			}
			if(_top==n)
				puts("Yes");
			else
				puts("No"); 
			memset(a,0,sizeof(a));
		}
		puts("");
	}
	return 0;
}
