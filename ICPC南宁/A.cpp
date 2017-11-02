#include<bits/stdc++.h>
using namespace std;

double a[5][5];

int col[20],tot;

void read(){
    tot=0;
	int aa;
    char c;
    int flag= 0;
    while(1){
        scanf("%d%c",&aa,&c);
        
        col[++tot] = aa;
        
        if(c=='\n'){
            break;
        }
    }
}

int main(){
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			scanf("%lf",&a[i][j]);
	read();
//	for(int i=1;i<=tot;i++)cout<<col[i];
	double res = 1.0;
	for(int i=2;i<=tot;i++){
		res*=a[col[i-1]][col[i]];
	}
//	cout<<res<<endl;
	printf("%.8lf\n",res);
	read();
	res = 1.0;
	for(int i=2;i<=tot;i++){
		res*=a[col[i-1]][col[i]];
	}
	printf("%.8lf\n",res);
	int n;
	scanf("%d",&n);
	printf("%.8lf\n",1/(1-a[n][n]));
	scanf("%d",&n);
	printf("%.8lf\n",1/(1-a[n][n]));
	return 0;
}
