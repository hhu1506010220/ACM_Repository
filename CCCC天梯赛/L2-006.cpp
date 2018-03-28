#include<bits/stdc++.h>
using namespace std;

int hx[31],zx[31],tr[1000*4];
int n;
vector<int>v;

void houxu(int,int);
void build(int root,int h_l,int h_r,int z_l,int z_r){
	if(h_l>h_r||z_l>z_r)return;
	int i;
	tr[root] = hx[h_r];
	int tar  = hx[h_r];
	for(i=z_l;i<z_r;i++)
		if(zx[i]==tar)
			break;
	int len = i-z_l;
	build(root<<1,h_l,h_l+len-1,z_l,i-1);
//	²»ÊÇbuild(root<<1,h_l,i-1,z_l,i-1);
	build((root<<1)+1,h_l+len,h_r-1,i+1,z_r);
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&hx[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&zx[i]);
	build(1,0,n-1,0,n-1);
	int cnt = 0;   
    for(int i=0; i<=100000; i++) {  
        if(tr[i]){  
            cnt++;  
            if(cnt!=n)
				printf("%d ",tr[i]);  
            else
				printf("%d\n",tr[i]);  
        }  
        if(cnt==n)break;  
    }   

	return 0;	
}
