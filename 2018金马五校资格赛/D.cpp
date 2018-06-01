#include<bits/stdc++.h>
using namespace std;

const int maxn = 510;
string s1[maxn];
string s2[maxn];
int dp[maxn][maxn];
int len1,len2;

void maxL() {
	for(int i=0; i<len1; i++)
		dp[i][0] = 0;
	for(int j=0; j<len2; j++)
		dp[0][j] = 0;

	for(int i = 1; i <= len1 ; i ++) {
		for(int j = 1 ; j <= len2 ; j ++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}

int main() {
	int T;
	while(cin >> T) {
		getchar();
		while(T--) {
			string tmp;
			getline(cin, tmp);

			for(int i = 0; i < tmp.length() ; i ++) {
				if(tmp[i] >= 'A' && tmp[i] <= 'Z') {
					tmp[i] = tmp[i] + ('a' - 'A');
				}
			}

			int s = 0;
			len1 = 0;
			for(int i = 0; i < tmp.length() ; i ++) {
				if(tmp[i] == ' ') {
					s1[len1 ++] = tmp.substr(s,i-s);
					s = i + 1;
				}
			}
			if(tmp[tmp.length() -  1] != ' ') {
				s1[len1 ++] = tmp.substr(s, tmp.length() - s + 1);
			}

			getline(cin, tmp);

			for(int i = 0; i < tmp.length() ; i ++) {
				if(tmp[i] >= 'A' && tmp[i] <= 'Z') {
					tmp[i] = tmp[i] + ('a' - 'A');
				}
			}

			s = 0;
			len2 = 0;
			for(int i = 0; i < tmp.length() ; i ++) {
				if(tmp[i] == ' ') {
					s2[len2 ++] = tmp.substr(s,i-s);
					s = i + 1;
				}
			}
			if(tmp[tmp.length() -  1] != ' ') {
				s2[len2 ++] = tmp.substr(s, tmp.length() - s + 1);
			}

			maxL();
			printf("%d\n",dp[len1][len2]);
		}
	}
}

