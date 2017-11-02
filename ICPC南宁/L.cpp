#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int res[maxn];

int _stack[maxn];
int lis(int arr[],int n)
{
    int i,top,mid,low,high;
    top = 0;
    _stack[0] = -1;
    for(i=0;i<n;i++)
    {
        if(arr[i]>=_stack[top])
            _stack[++top] = arr[i];
        else
        {
            low = 1;
            high = top;
            while(low <= high)
            {
                mid = (low + high)/2;
                if(arr[i] >= _stack[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            _stack[low] = arr[i];
        }
    }
    return top;
}
int main(){
    int a;
    int tot = 0;
    while(scanf("%d",&a)!=EOF){
        if(a<0)
            continue;
        if(a>=10000){
            for(int i=0;i<5;i++){
                res[tot++] = a-10000;
            }
        }else{
            res[tot++] = a;
        }
    }
//    cout<<tot<<endl;
    printf("%d\n",lis(res, tot));
    return 0;
}

