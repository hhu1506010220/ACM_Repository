#include<bits/stdc++.h>
#define maxn 10005
#define inf 0x3f3f3f3f
using namespace std;

int a[maxn];
int aa[maxn];
int b[maxn]; 
int dis[11];

int sta;

bool cmp(int a,int b){
	if(abs(a-sta)==abs(b-sta)){
		return a>b;	
	}
	return abs(a-sta)<abs(b-sta);	
}

int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[i] = s[i]-'0';
		aa[i] = s[i]-'0';
	}
	for(int i=0;i<10;i++){
		sta = i;
		sort(a,a+n,cmp);
		int cnt = 0;
		int sum = 0;
		for(int j=0;j<n;j++){
			if(a[j]==sta){
				cnt++;	
			}
			else{
				sum += abs(a[j]-sta);
				cnt++;
			}
			if(cnt==k)break;
		}
		dis[i] = sum;
	}
//	for(int i=0;i<10;i++)cout<<dis[i]<<endl;
	int ans = -1;
	int MAX = inf;
	for(int i=0;i<10;i++){
		if(dis[i]<MAX){
			ans = i;
			MAX = dis[i];	
		}
	}
	cout<<MAX<<endl;
	sta = ans;
	sort(a,a+n,cmp);
	int cnt = 0;
	int sum = 0;
	int end_dis = -1;
	int end_num = -1;
	int end_pos = -1;
	for(int j=0;j<n;j++){
		if(a[j]==sta){
			cnt++;
			end_dis = abs(a[j]-sta);
			end_num = a[j];
			end_pos = j;
		}
		else{
			sum += abs(a[j]-sta);
			cnt++;
			end_dis = abs(a[j]-sta);
			end_num = a[j];	
			end_pos = j;
		}
		if(cnt==k)break;
	}
	int mm = 0;
	for(int i=0;i<n;i++){
		if(aa[i]==sta)
			mm++;	
	}
	k-=mm;
	if(end_num>=sta){
		int cntt = 0;
		int cnt_sum =0 ;
		for(int i=0;i<n;i++){
			if(aa[i]==sta)continue;
			if(abs(aa[i]-sta)<end_dis){
				cnt_sum ++;
				aa[i] = sta;	
			}
			else if(abs(aa[i]-sta)>end_dis){
				continue;
			}
			else{
				if(aa[i]>end_num){
					cnt_sum ++;
					aa[i] = sta;
				}
				else if(aa[i]==end_num&&cnt_sum<k){
					cnt_sum ++;
					aa[i] = sta;	
				}
			}
		}
	}
	else{
		int cntt = 0;
		int nn = 0;
		int cnt_sum =0 ;
		for(int i=0;i<n;i++){
			if(aa[i]==sta)continue;
			if(abs(aa[i]-sta)<end_dis){
				cnt_sum ++;
				aa[i] = sta;	
			}
			else if(abs(aa[i]-sta)>end_dis){
				continue;
			}
			else{
				if(aa[i]>end_num){
					cnt_sum ++;
					aa[i] = sta;
				}
				else{
					continue;	
				}
			}
			
//			cout<<i<<": "<<cnt_sum<<endl;
		}
		for(int i=n-1;i>=0;i--){
			if(aa[i]==end_num&&cnt_sum<k){
				cnt_sum ++;
				aa[i] = sta;
			}
		}
	}
	for(int i=0;i<n;i++)cout<<aa[i];cout<<endl;
	return 0;	
}
