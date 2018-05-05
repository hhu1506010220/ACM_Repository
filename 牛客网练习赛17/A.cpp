#include<bits/stdc++.h>
#define ll long long
using namespace std ;

int main(){
    double a,b,c;
    ll A,B,C;
    cin>>A>>B>>C;
    ll abc = sqrt(A*B*C);
    c = (double)(abc*1.0)/(double)(A*1.0);
    b = (double)(abc*1.0)/(double)(B*1.0);
    a = (double)(abc*1.0)/(double)(C*1.0);
    cout<<(double)(4*1.0)*(a+b+c)<<endl;
    return 0;
}
