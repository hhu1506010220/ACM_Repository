#include <bits/stdc++.h>
#define ll long long

using namespace std;
int arr1[25];
bool ch(int i,int b,int c,int d){
    return (arr1[i]==arr1[b]&&arr1[b]==arr1[c]&&arr1[c]==arr1[d]);
}

int main(){
    for(int i=1;i<25;i++)   cin>>arr1[i];
    bool arr[6][4];
    arr[0][0]=ch(5,7,2,4);
    arr[0][1]=ch(9,11,6,8);
    arr[0][2]=ch(22,24,10,12);
    arr[0][3]=ch(21,23,1,3);
    arr[1][0]=ch(5,7,10,12);
    arr[1][1]=ch(9,11,21,23);
    arr[1][2]=ch(1,3,6,8);
    arr[1][3]=ch(2,4,22,24);
    arr[2][0]=ch(17,19,1,2);
    arr[2][1]=ch(9,10,18,20);
    arr[2][2]=ch(14,16,12,11);
    arr[2][3]=ch(13,15,3,4);
    arr[3][0]=ch(17,19,12,11);
    arr[3][1]=ch(10,9,13,15);
    arr[3][2]=ch(3,4,18,20);
    arr[3][3]=ch(1,2,14,16);
    arr[4][0]=ch(5,6,15,16);
    arr[4][1]=ch(7,8,18,17);
    arr[4][2]=ch(19,20,21,22);
    arr[4][3]=ch(13,14,23,24);
    arr[5][0]=ch(5,6,19,20);
    arr[5][1]=ch(13,14,7,8);
    arr[5][2]=ch(17,18,23,24);
    arr[5][3]=ch(21,22,15,16);
    for(int i=0;i<6;i++)
    {
        bool ans2=true;
        for(int j=0;j<4;j++){
            ans2&=arr[i][j];
        }
        if(ans2==true){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
