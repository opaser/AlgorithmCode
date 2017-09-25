#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
const int maxn = 605;
struct line_l{
	int L,R;
}P[605];
int dp[maxn][maxn];
char s[maxn*2];
void dfs(int L, int R,int L_loc, int R_loc)
{
	if(L>R) return ;
	if(dp[L][R] == R){
	  s[L_loc] = '(';
		s[R_loc] = ')';
		dfs(L+1, R, L_loc+1, R_loc-1);
	}else{
		int mid = (dp[L][R] - L + 1)*2 + L_loc - 1;
		dfs(L,dp[L][R], L_loc, mid);
		dfs(dp[L][R] + 1,R, mid + 1, R_loc);
	}
}
int main() {
	freopen("in","r",stdin);
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < n; ++ i)
	{
		scanf("%d%d",&P[i].L, &P[i].R);
		if(P[i].L == 1) dp[i][i]=i; 
	}
	for(int k = 1; k < n; ++k)
	{
		for(int i = 0; i + k < n; ++ i)
		{  
			int max_len = (P[i].R-1)/2;
			int min_len = P[i].L/2;
			for(int j = i; j < i + k; ++ j){
				if(dp[i][j] != -1 && dp[j+1][i+k] != -1)	{
					dp[i][i+k] = j;
					break;
				}
			} 
			if(dp[i][i+k] == -1 && k <= max_len && dp[i+1][i+k] != -1 && k >= min_len)
			{
				dp[i][i+k] = i+k;
			}
		}
	}
	if(dp[0][n-1] != -1){
			dfs(0,n-1,0,n*2-1);
			s[n*2]='\0';
			printf("%s\n",s);
	}else{
		printf("IMPOSSIBLE\n");
	}
		return 0;
}
