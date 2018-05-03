#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long day1,hour1,min1,sec1,day2,hour2,min2,sec2;
		char c1,c2,c3,c4,c5;
		scanf("%lld%c%c%c%lld%c%lld%c%lld",&day1,&c1,&c2,&c3,&hour1,&c4,&min1,&c5,&sec1);
		scanf("%lld%c%c%c%lld%c%lld%c%lld",&day2,&c1,&c2,&c3,&hour2,&c4,&min2,&c5,&sec2);
		long long day = day2 - day1;
		long long min = min2 - min1;
		long long hour= hour2- hour1;
		long long sec = sec2 - sec1;
		long long res = (long long)day*60*60*24 + (long long)hour*60*60+(long long)min*60+sec;
		cout<<res<<endl;
	}
	return 0;
}
