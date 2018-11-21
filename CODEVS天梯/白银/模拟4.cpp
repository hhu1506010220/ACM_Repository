#include<bits/stdc++.h>
using namespace std;

int main() {
	int i,j,n,a[100][100],k,m,t,p,sum=0;
	scanf("%d",&n);
	i=j=n/2;
	m=n/2;
	a[i][i]=1;
	t=2;
	for(k=2; k/2<=m; k=k+2) {
		j=j+1;
		for(p=1; p<=k; p++) { //向上 
			a[i][j]=t;
			t++;
			i--;
		}
		i++;
		j--;
		for(p=1; p<=k; p++) { //向左 
			a[i][j]=t;
			t++;
			j--;
		}
		j++;
		i++;
		for(p=1; p<=k; p++) { //向下 
			a[i][j]=t;
			t++;
			i++;
		}
		i--;
		j++;
		for(p=1; p<=k; p++) { //向右 
			a[i][j]=t;
			t++;
			j++;
		}
		j--;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(j!=n-1) 
				printf("%d ",a[i][j]);
			else
				printf("%d\n",a[i][j]);
			if(i==j||i+j==n-1)  sum=sum+a[i][j];
		}
	}
	printf("%d\n",sum);
	return 0;
}
