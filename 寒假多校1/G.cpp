#include<bits/stdc++.h>
using namespace std;

#define N 1000

char a[N][N];

void draw(int x, int y, int n){
    int temp = pow(3,n-2);
    if(n==1){
        a[x][y] = 'O';
    }
    else{
        draw(x-temp,y,n-1);
        draw(x+temp,y,n-1);
        draw(x,y-temp,n-1);
        draw(x,y+temp,n-1);
    }
}

int main(){
//	freopen("out.txt","w",stdout);
    int n;
    int b;
    cin>>n;
    int m = n;

    while(n--){
        cin>>b;
        memset(a,' ',sizeof(a));
        if(b == 0){
            puts("O");
        }
        else{
        	b = b+1 ;
            int x= pow(3,b-2)+(pow(3,b-2)+1)/2;
            draw(x,x,b);
        }

        int temp = pow(3,b-1);
        for(int i=1; i<=temp; i++){
            for(int j=1; j<=temp; j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
