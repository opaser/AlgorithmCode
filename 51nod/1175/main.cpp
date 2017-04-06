#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
const int maxn = 10005;
const int maxm = 20;
int dp[maxn][maxm];
int RMQ_init(int n)
{
	for(int i = 1; (1 << i) <= n; ++i)
		for(int j = 0; j + (1 << i) - 1 < n ; ++ j)
			dp[j][i] = std::max(dp[j][i-1], dp[j +(1<<(i-1))][i-1]);
}
int RMQ(int L, int R)
{
	int k = int(log((double)(R-L+1))/log(2.0));
	return std::max(dp[L][k],dp[R-(1<<k)+1][k]);
}
int main() {
	int n;
	std::cin>>n;
	for(int i = 0; i < n; ++ i)
		std::cin>>dp[i][0];
	RMQ_init(n);
	int q;
  std::cin>>q;
	for(int i = 0; i < q; ++i) {
		int L,R;
		std::cin>>L>>R;
		std::cout<<RMQ(L,R)<<std::endl;
	}
	return 0;
}
