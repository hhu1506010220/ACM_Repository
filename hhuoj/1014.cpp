#include<bits/stdc++.h>
#define MAX 8000005
#define inf 0x7fffffff
using namespace std;

int a[MAX],gap[MAX][2];//0代表最大 1代表最小 

int main()
{
    //freopen("out.txt","w",stdout);
    int n;
	scanf("%d",&n); 
    int maxn = -inf,minn = inf ;
    int i,temp,ans=0;
    for(i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	minn = min(minn,a[i]);
    	maxn = max(maxn,a[i]);
    }
    double aver_dis = (maxn-minn)*1.0/(n-1)*1.0;
    ans =(int)(aver_dis+0.5); 
//    cout<<aver_dis<<endl;
    for (i=1;i<=n;i++)  
    	for(int j=0;j<2;j++) 
   			gap[i][j]=(j%2==0)?-inf:inf;  
	for(int i=1;i<=n;i++){
		temp = (a[i]-minn)/aver_dis;
		if(a[i]-minn>temp*aver_dis)temp++; 
		gap[temp][0] = max(gap[temp][0],a[i]);
		gap[temp][1] = min(gap[temp][1],a[i]);
	}
	temp = minn;
    for (i=1;i<=n;i++){  
        if (gap[i][1]!=inf){
        	ans = max(ans,gap[i][1]-temp);  
        	temp = gap[i][0];  
    	}
    }  
    printf("%d\n",ans);
    return 0;
}

