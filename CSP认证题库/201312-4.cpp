#include <bits/stdc++.h>
long long status[1005][6];
long long mod = 1000000007;

/*
	status[i][j]到第i个位置满足第j种状态的所有可能数。 
	6种状态： 
		0 -- 0 1 (2) 3
		1 -- (0) 1 (2) 3
		2 -- 0 1 (2) (3)
		3 -- (0) (1) (2) 3
		4 -- (0) 1 (2) (3)
		5 -- (0) (1) (2) (3)
*/

int main(){
    int n;
    scanf("%d",&n);
	
    for (int i=0;i<6;i++)
    	status[0][i] = 0;

    for (int i= 1; i <= n; i++){
	    status[i][0] = 1;
	    status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % mod;
	    status[i][2] = (status[i - 1][2] + status[i - 1][0]) % mod;
	    status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % mod;
	    status[i][4] = (status[i - 1][4] * 2 + status[i - 1][2] + status[i - 1][1]) % mod;
	    status[i][5] = (status[i - 1][5] * 2 + status[i - 1][4] + status[i - 1][3]) % mod;
    }
    printf("%lld",status[n][5]);
    return 0;
}
