#include<bits/stdc++.h>
using namespace std;
const int N = 1003;
int a[N];

int main(){
    int n;
    scanf("%d",&n); 
    for(int i =0  ;i < n;++i){
        scanf("%d",&a[i]);
    }
    int ans = -1;
    for(int i = 0 ; i< n;++i){
        int low = a[i];
        for(int j =  i ; j < n;++j){
            if(low > a[j])
                low = a[j];
            int temp = (j - i + 1) * low;
            if(temp > ans)
                ans = temp;
        }
    }
    printf("%d\n",ans);
	return 0;
}
