#include <iostream>  
#include <cstring>
#include <cstdio>  
#include <algorithm>  
using namespace std;  
const int MAX = 110;  
int a, b, c, r, l, vis[MAX][MAX], step[MAX*MAX];  
string opr[7] = {" ", "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(2,1)", "POUR(1,2)"};  
  
struct Info  
{  
       int x;  
       int y;  
       int operation;  
       int pre;//Á´±í»ØËÝÕÒÂ·¾¶ 
}info[MAX*MAX];  
  
void solve(int xx, int yy, int ss)  
{  
     if (vis[xx][yy])  
         return ;  
     vis[xx][yy] = 1;  
     info[r].x = xx;  
     info[r].y = yy;  
     info[r].operation = ss;  
     info[r].pre = l;  
     r++;  
}  
  
void print()  
{  
     int i, ans;  
     ans = 0;  
     while (l != 0){  
           step[ans++] = info[l].operation;  
           l = info[l].pre;  
     }  
       
     cout << ans << endl;  
     for (i = ans - 1; i >= 0; i--){  
         cout << opr[step[i]] << endl;  
     }  
}  
  
  
void BFS()  
{  
     info[0].x = 0;  
     info[0].y = 0;  
     vis[0][0] = 1;  
     l = 0;  
     r = 1;  
     while (l != r){     
           if (info[l].y == c || info[l].x == c){  
               print();  
               return ;  
           }  
             
           int tmpx, tmpy;  
           //fill(1)   
           tmpx = a;  
           tmpy = info[l].y;  
           solve(tmpx, tmpy, 1);  
             
           //fill(2)   
           tmpx = info[l].x;  
           tmpy = b;  
           solve(tmpx, tmpy, 2);  
             
           //drop(1);   
           tmpx = 0;  
           tmpy = info[l].y;  
           solve(tmpx, tmpy, 3);  
              
           //drop(2)   
           tmpx = info[l].x;  
           tmpy = 0;  
           solve(tmpx, tmpy, 4);  
             
           //fill(2, 1)   
           tmpx = info[l].x + min(a - info[l].x, info[l].y);  
           tmpy = info[l].y - min(a - info[l].x, info[l].y);  
           solve(tmpx, tmpy, 5);  
             
           //fill(1, 2)   
           tmpx = info[l].x - min(b - info[l].y, info[l].x);  
           tmpy = info[l].y + min(b - info[l].y, info[l].x);  
           solve(tmpx, tmpy, 6);  
             
           l++;  
     }  
     if (l >= r)  
         cout << "impossible" << endl;  
}  
  
  
int main()  
{  
    cin >> a >> b >> c;  
    memset(vis, 0, sizeof(vis));  
    BFS();  
      
    system("pause");  
}  
