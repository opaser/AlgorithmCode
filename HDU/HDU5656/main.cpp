/*************************************************************************
 > File Name: main.cpp
 > Author: opas_chenxin
 > Mail: 1017370773@qq.com 
 > Created Time: 2016年05月06日 星期五 07时12分03秒    
*************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn =1005;
typedef long long LL;
LL dp[maxn][maxn];
const LL mod = 100000007;
int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);	
}
int A[maxn];
int main(int argc, char *argv[])
{
	freopen("in","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int cc = 1; cc <= cas; ++ cc)
	{
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d", &n);
		int maxv=1;
		for(int i = 1; i <= n; ++ i)
		{
			scanf("%d", &A[i]);
			maxv=max(maxv, A[i]);
		}
		for(int i = 1; i <= n; ++ i)
		{
			for(int j = 1; j <=maxv; ++ j)
			{
				dp[i][j] =(dp[i][j] + dp[i-1][j])%mod;
				if(dp[i - 1][ j ] == 0) continue;
				int k = gcd(j,A[i]);
				dp[i][k] =(dp[i][k] + dp[i-1][j])%mod;
			}
			dp[i][ A[i] ]++;
		
		}
		LL ans=0;
		for(int i = 1; i <= maxv; ++ i)
		{
			ans = (ans + dp[n][i] * i)%mod;
		}
		printf("%lld\n",ans);
	}
    return 0;
}
