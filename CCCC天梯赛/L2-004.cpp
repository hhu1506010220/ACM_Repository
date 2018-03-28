#include<bits/stdc++.h>
using namespace std;

int a[1100],tr[1100];
int cur;

void Check(int a[],int l,int r){
	if(l>r)
		return;
	if(l==r){
		tr[cur++] = a[l];
		return ; 
	}
	int mid,tem;
	tem = l+1;
	while(tem<=r&&a[tem]<a[l])
		tem++;
	mid = tem;
	while(tem<=r){
		if(a[tem]<a[l])
			return ;
		tem++;	
	}
	Check(a,l+1,mid-1);
	Check(a,mid,r);
	tr[cur++] = a[l];
}

void CheckMirror(int a[],int l,int r){
	if(l>r)
		return;
	if(l==r){
		tr[cur++] = a[l];
		return ; 
	}
	int mid,tem;
	tem = l+1;
	while(a[tem]>=a[l])
		tem++;
	mid = tem;
	while(tem<=r){
		if(a[tem]>=a[l])
			return ;
		tem++;	
	}
	CheckMirror(a,l+1,mid-1);
	CheckMirror(a,mid,r);
	tr[cur++] = a[l];
}

int main(){
	int n;
	cur = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(a[0]>=a[1])
		Check(a,0,n-1);
	else
		CheckMirror(a,0,n-1);
//	for(int i=0;i<cur;i++)cout<<tr[i]<<" ";cout<<endl;
	if(cur!=n)
		puts("NO");
	else{
		puts("YES");
		for(int i=0;i<cur-1;i++){
			printf("%d ",tr[i]);
		}
		printf("%d\n",tr[cur-1]);
	}
	return 0;	
}
