#include<bits/stdc++.h>
using namespace std;

struct Pro{
	double num;
	double sale;	
	double rate;
}pro[1005];

bool cmp(Pro a,Pro b){
	return a.rate>b.rate;
}

int main(){
	int n,dd;
	double d;
	double res = 0;
	scanf("%d%d",&n,&dd);
	d = (double)dd;
	for(int i=0;i<n;i++)
		scanf("%lf",&pro[i].num);
	for(int i=0;i<n;i++)
		scanf("%lf",&pro[i].sale);
	for(int i=0;i<n;i++)
		pro[i].rate=(double)(pro[i].sale)/(pro[i].num*1.0);		
	sort(pro,pro+n,cmp);
//	for(int i=0;i<n;i++)	cout<<pro[i].rate<<endl;
	for(int i=0;i<n;i++){
		if(d-pro[i].num>=0){
			res += pro[i].sale;	
			d -= pro[i].num;	
		}
		else{
			res += pro[i].rate * d; 
			break;
		}
	}
	printf("%.2f\n",res);
	return 0;
}
