#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double dx[20][20];
double dy[20][20];
int main(){
	freopen("in.txt","r",stdin);
    dx[9][9] = dy[9][9] = 0;
    for(int i=-9;i<=10;i++){
        if(i==0)continue;
        dx[i+9][9] = dx[9][9]+1.0*i*sqrt(3)*5;
        dy[i+9][9] = 0;
    }
    for(int i=-9;i<=10;i++){
        for(int j=-9;j<=10;j++){
            if(j==0)
                continue;
            dy[i+9][j+9] = dy[9][9]+1.0*j*5*3/2;
            dx[i+9][j+9] = dx[i+9][9]+1.0*j*sqrt(3)*5/2;
        }
    }
    int a,b;
    int t=0;
    while(scanf("%d%d",&a,&b)!=EOF){
        for(int i=0;i<=19;i++){
            for(int j=0;j<=19;j++){
                if(sqrt(pow((dx[i][j]-a),2)+(pow((dy[i][j]-b),2)))<=5){
                    cout<<"["<<i-9<<","<<j-9<<"]";
                    t++;
                    if(t!=10){
			            cout<<", ";
			            continue;
			        }
                }
            }
        }
    }
    cout<<endl;
    return 0;
}
