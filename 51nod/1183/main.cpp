#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
const int maxn = 1005;
int dp[maxn][maxn];
char A[maxn],B[maxn];
int main() {
	gets(A);
	gets(B);
	int len_A = strlen(A);
	int len_B = strlen(B);
	for(int i = 0; i <= len_A; ++ i)
		dp[i][0] = i;
	for(int j = 0; j <= len_B; ++ j)
		dp[0][j] = j;
	for(int i = 1; i <= len_A; ++ i)
	{
		for(int j = 1; j <= len_B; ++ j) {
			dp[i][j] = std::min(dp[i-1][j] , dp[i][j-1]) + 1;
		  dp[i][j] = std::min(dp[i][j] , dp[i-1][j-1] + ( (A[i-1] == B[j-1])?0:1) );
		}
	}
	std::cout<<dp[len_A][len_B]<<std::endl;
	return 0;
}
