#include<bits/stdc++.h>
using namespace std;

struct sonn {
	int day,month,year,num;
}temp,son[105];

bool judge(sonn a,sonn b){//返回a是否比b大 
	if(a.year<b.year)return 1;
	else if(a.year==b.year) {
		if(a.month<b.month) {
			return 1;
		} else if(a.month==b.month) {
			if(a.day<=b.day) {
				return 1;
			}
		}
	}
	return 0;
}


int main() {
	temp.day=0,temp.month=0,temp.year=0,temp.num=-1;
	int f_day,f_month,f_year;
	scanf("%d%d%d",&f_day,&f_month,&f_year);
	int n;
	int cnt=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d",&son[i].day,&son[i].month,&son[i].year);
		son[i].num=i;
		if(son[i].year+18<f_year){
			if(judge(temp,son[i])){
				temp=son[i];
			}
		}
		else if(son[i].year+18==f_year) {
			if(son[i].month<f_month) {
				if(judge(temp,son[i])){
					temp=son[i];
				}
			} else if(son[i].month==f_month) {
				if(son[i].day<=f_day) {
					if(judge(temp,son[i])){
						temp=son[i];
					}
				}
			}
		}
	}
	if(temp.num==-1)printf("%d\n",temp.num);
	else printf("%d\n",temp.num+1);
	return 0;
}
