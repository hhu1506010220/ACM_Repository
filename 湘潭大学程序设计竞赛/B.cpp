#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
const int maxn = 510;
char s[maxn];
char tt[6][6] = {{'0','1','2','3','4','5'},
    {'6','7','8','9','A','B'},
    {'C','D','E','F','G','H'},
    {'I','J','K','L','M','N'},
    {'O','P','Q','R','S','T'},
    {'U','V','W','X','Y','Z'}
};
 
struct Node {
    char c;
    int row;
    int col;
} c[10][10];
 
void init() {
    for(int i = 0; i < 6; i ++) {
        for(int j = 0; j < 6 ; j ++) {
            c[i][j].c = tt[i][j];
            c[i][j].row = c[i][j].col = 0;
        }
    }
}
 
int main() {
    int T,len,row,col;
    scanf("%d",&T);
    getchar();
    while(T --) {
        init();
        scanf("%s",s);
        getchar();
        len = strlen(s);
 
        for(int i = 0 ; i < 6; i ++) {
            row = 0;
            for(int j = 0 ; j < 6 ; j ++) {
                for(int k = 0; k < len ; k ++) {
                    if(c[i][j].c == s[k]) {
                        row ++;
                    }
                }
            }
            for(int j = 0; j < 6 ; j ++) {
                c[i][j].row = row;
            }
        }
 
        for(int j = 0 ; j < 6; j ++) {
            col = 0;
            for(int i = 0 ; i < 6 ; i ++) {
                for(int k = 0; k < len ; k ++) {
                    if(c[i][j].c == s[k]) {
                        col ++;
                    }
                }
            }
 
            for(int i = 0; i < 6 ; i ++) {
                c[i][j].col = col;
            }
        }
 
        int maxrow = 0, maxcol = 0;
        for(int i = 0; i < 6 ; i ++) {
            for(int j = 0; j < 6 ; j ++) {
                maxrow = max(maxrow, c[i][j].row);
                maxcol = max(maxcol, c[i][j].col);
            }
        }
 
        for(int i = 0; i < 6 ; i ++) {
            for(int j = 0; j < 6 ; j ++) {
                if(c[i][j].row == maxrow && c[i][j].col == maxcol) {
                    printf("%c",c[i][j].c);
                }
            }
        }
 
        puts("");
    }
    return 0;
}
