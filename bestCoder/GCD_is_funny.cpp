#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000005;
int gcd(int a, int b) {	
	return b == 0?a:gcd(b,a%b);
}
int A[1000005];
int B[1000005];
int C[1000005];
int main() 
{
	freopen("in","r",stdin);
	int cas;
	scanf("%d", &cas);
	for(int cc = 1; cc <= cas; ++ cc) {
		int n;
		scanf("%d",&n);
		memset(A, 0, sizeof(A));
		memset(C, 0, sizeof(C));
		int maxv = 0;
		for(int i = 0; i < n; ++ i) {
			int v;
			scanf("%d",&v);
			for(int j = 1; j*j <= v; ++ j ) {
				if(v % j == 0) {
					int a = j, b = v/j;
					++ C[a];
					if(A[a] == 0) 
						 A[a] = v;
					A[a] = gcd(A[a], v);
					if(b == a)
						continue;
					++ C[b];
					if(A[b] == 0) 
						A[b] =v;
					A[b] = gcd(A[b], v);
				}
			}
			maxv = max(v, maxv);
		}
		int num=0;
		for(int i = 1; i <= maxv; ++ i)
			if(A[i] == i && C[i] > 1) 
				B[ num ++ ] = i;
		for(int i = 0; i < num; ++i)
			printf("%d%c", B[i], i==(num-1)?'\n':' ');
	}
	return 0;
}
