/*************************************************************************
    > File Name: b.cpp
    > Author: opas_chenxin
    > Mail: 1017370773@qq.com 
    > Created Time: 2016年10月08日 星期六 21时29分53秒
 ************************************************************************/
#include<cstdio>
#include<string.h>
using namespace std;
const int maxn = 25;
int A[maxn][maxn];
int n,m;
void solve(int a, int b) {
	for(int i = 0; i < n; ++ i) {
		int temp = A[i][a];
		A[i][a] = A[i][b];
		A[i][b] = temp;
	}
}
bool check() {
	for(int i = 0; i < n; ++ i) {
		int ge = 0;
		for(int j = 0; j < m; ++ j)
			if(A[i][j] != j+1) {
				 ge++;
			}
		if(ge > 2) return false;
	}
	return true;
}
int main() {
	freopen("in","r",stdin);
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 0; i < n; ++ i)
			for(int j = 0; j < m; ++ j)
				scanf("%d", &A[i][j]);
		bool is_success = check();
		for(int i = 0; i < m; ++ i)
			for(int j = i + 1; j < m; ++ j) {
				solve(i, j);
				if(check()) is_success = true;
				solve(j, i);
			}
		if(is_success) puts("YES");
		else puts("NO");
	}
	return 0;
}
