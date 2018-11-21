#include<bits/stdc++.h>
using namespace std;
const int MAXX = 50 + 5;
const int MAXY = 50 + 5;
string s;
char z;
int X,Y;
int m[MAXX][MAXY];// 可通过为 1，不可通过为 0，现在可到为 3，起点特殊标记；
char zm[MAXX][MAXY];
int x,y,n;//起点坐标
bool bm[MAXX][MAXY];
void zhuan(int xx,int yy,char b) {
	if(b=='.') {
		m[xx][yy] = 1;
		return ;
	}
	if(b=='X') {
		m[xx][yy] = 0;
		return ;
	}
	if(b=='*') {
		m[xx][yy] = 3;
		x=xx;
		y=yy;
	}
}
void zhuan(int xx,int yy,int b) {
	if(b==1) {
		zm[xx][yy] = '.';
		return ;
	}
	if(b==0) {
		zm[xx][yy] = 'X';
		return ;
	}
	if(b==3) {
		zm[xx][yy] = '*';
		return ;
	}
}
void zou(string a) {
	memset(bm,0,sizeof(bm));
	if(a == "NORTH") {
		for(int i = 1; i <= X; i ++)
			for(int j = 1; j <= Y; j ++) {
				if(m[i][j] == 3) {  
					for(int k = i - 1; k > 0; k --) {
						if(m[k][j]) {
							m[k][j] = 3;
							bm[k][j] = true;
						} else
							break;
					}
					if(!bm[i][j])
						m[i][j] = 1;
				}
			}
	}
	if(a == "WEST") {
		for(int i = 1; i <= X; i ++)
			for(int j = 1; j <= Y; j ++) {
				if(m[i][j] == 3) {
					for(int k = j - 1; k > 0; k --) {
						if(m[i][k]) {
							m[i][k] = 3;
							bm[i][k] = true;
						} else
							break;

					}
					if(!bm[i][j])
						m[i][j] = 1;
				}

			}
	}
	if(a == "SOUTH") {// 1='.'  3='x' 
		for(int i = 1; i <= X; i ++)
			for(int j = 1; j <= Y; j ++) {
				if(m[i][j] == 3) {
					for(int k = i + 1; k <= X; k ++) {
						if(m[k][j]) {
							m[k][j]=3;
							bm[k][j] = true;
						} else
							break;

					}
					if(!bm[i][j])
						m[i][j] = 1;
				}
			}
	}
	if(a == "EAST") {
		for(int i = 1; i <= X; i ++)
			for(int j = 1; j <= Y; j ++) {
				if(m[i][j]==3) {
					for(int k = j + 1; k <= Y; k ++) {
						if(m[i][k]) {
							m[i][k] = 3;
							bm[i][k] = true;
						} else
							break;
					}
					if(!bm[i][j])
						m[i][j] = 1;
				}
			}
	}

}
int main() {
	cin>>X>>Y;
	for(int i = 1 ; i <= X ; i ++)
		for(int j = 1; j <= Y ; j ++) {
			cin >> z;
			zhuan(i,j,z);
		}
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>s;
		zou(s);
	}
	for(int i=1; i<=X; i++)
		for(int j=1; j<=Y; j++) {
			zhuan(i,j,m[i][j]);
		}
	for(int i=1; i<=X; i++) {
		for(int j=1; j<=Y; j++) {
			cout<<zm[i][j];
		}
		cout<<endl;
	}
	return 0;
}
