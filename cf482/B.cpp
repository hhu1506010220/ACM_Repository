#include<bits/stdc++.h>
using namespace std;
string s[4];
int cnt[4][100];
int maxn[4];
int main(){
	int n;
	cin>>n;
//	memset(s,0,sizeof(s));
	memset(cnt,0,sizeof(cnt));
	memset(maxn,0,sizeof(maxn));
	for(int i=0;i<3;i++){
		cin>>s[i];
		int len = s[i].length();
		int minn = 99999;
		for(int j=0;j<len;j++){
//			cout<<s[i][j]-'A'<<endl;
			cnt[i][s[i][j]-'A']++;
		}
		for(int j=0;j<='z'-'A';j++){
			if(((j>='A'-'A'&&j<='Z'-'A')||(j>='a'-'A'&&j<='z'-'A'))){
				maxn[i]=max(maxn[i],cnt[i][j]);
				minn = min(minn,cnt[i][j]);	
			}
		}
		if(n==1&&len==maxn[i]){
			maxn[i] = len - 1;
		}
		else
			maxn[i] = min(len,maxn[i]+n);
//		if(n+maxn[i]<=len){
//			maxn[i] = maxn[i]+n;		
//		}
//		else if(n+maxn[i]>len){
//			int left = len-maxn[i];
//			int q = max(left,maxn[i]);
//			int sol1 = len-(n+maxn[i]-len);
//			int e = -1;
//			for(int j=0;j<='z'-'A';j++)
//				if(cnt[i][j]+n<=len&&cnt[i][j]>e&&((j>='A'-'A'&&j<='Z'-'A')||(j>='a'-'A'&&j<='z'-'A')))
//					e = cnt[i][j];
//			int sol2; 
//			if(e!=-1) 
//				sol2 = e+n;
//			else{
//				sol2 = len-(n+minn-len);	
//			}
//			maxn[i] = max(sol1,sol2);
//		}
//		
//		int cntt =0;
//		for(int j=0;j<='z'-'A';j++){
//			if(cnt[i][j]!=0)
//				cntt ++;	
//		}
//		if(cntt==1&&n>=1)
//			maxn[i] = max(0,maxn[i]-1);
	}
//	for(int i=0;i<='z'-'A';i++)
//		cout<<cnt[1][i]<<" ";cout<<endl;
//
//	for(int i=0;i<3;i++)
//		cout<<maxn[i]<<endl;
	int mm = 0;
	int nn = maxn[0];
	for(int i=0;i<3;i++){
		if(maxn[i]>nn){
			mm = i;
			nn = maxn[i];	
		}
//		cout<<maxn[i]<<endl;
	}
	int cntt =0;
	for(int i=0;i<3;i++){
		if(nn==maxn[i])
			cntt++;
	}
	if(cntt>=2){
		puts("Draw");
		return 0;	
	}
	if(mm==0)puts("Kuro");
	else if(mm==1)puts("Shiro");
	else puts("Katie");

	return 0;
}
