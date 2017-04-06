#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
const int maxn =105;
typedef long long LL;
LL A[maxn][maxn],B[maxn][maxn],C[maxn][maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++j)
			std::cin>>A[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			std::cin>>B[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			LL sum = 0;
			for(int k = 0; k < n; ++k)
				sum += A[i][k] * B[k][j];
			C[i][j] = sum;
		}
	for(int i = 0; i < n ; ++i)
		for(int j = 0; j < n; ++j) {
			std::cout<<C[i][j];
			printf("%c", j==n-1?'\n':' ');
		}
	return 0;
}
