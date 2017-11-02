#include <iostream>
using namespace std;
const int maxn = (1<<20)+5;
int dp[maxn],col[21];
void solve(int n,int ans){
    if(n==0)
        return;
    int t = col[n];
    dp[(1<<(t-1))+ans]++;
    solve(n-1,ans);
    solve(n-1,ans+(1<<(t-1)));
}
int read(){
    int tot=0,a;
    char c;
    int flag= 0;
    while(1){
        if(scanf("%d",&a)!=EOF){
            //cout<<a<<endl;
        }else{
            //cout<<1<<endl;
            flag = 1;break;
        }
        scanf("%c",&c);
        //cout<<c<<endl;
        col[++tot] = a;
        
        if(c=='\n'){
            //cout<<2<<endl;
            break;
        }
    }
	//cout<<tot<<endl; 
    solve(tot,0);
    if(flag)
    return -1;
    return 0;
}
int main(){
    //freopen("in.txt","r",stdin);
    
    int n,m;
    m = 0;
    double a;
    scanf("%d%lf",&n,&a);
    for(int i=1;i<(1<<n);i++){
        dp[i] = 0;
    }
    while(read()!=-1){
        m++;
        //cout<<"hh"<<endl;
    }
    m++;
    a = a*m;
    //cout<<a<<endl;
    int ans = 0;
    for(int i=1;i<(1<<n);i++){
        if(dp[i]>=a){
//        	int t = i;
//			while(t){
//				if(t%2==0){
//					cout<<0;	
//				}else{
//					cout<<1;
//				}
//				t/= 2;
//			}
//			cout<<endl;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

