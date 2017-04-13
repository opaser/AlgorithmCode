#include<cstdio>
#include<iostream>
#include<cmath>
const int maxn = 1000015;
int a[maxn];
int b[maxn];
int main() {
	for(int i = 2; i <= 1005; ++i)
		for(int j = 2; j <= maxn/i; ++j)
			a[i*j] = 1;
	a[0] = a[1] = 1;
	for(int i = 1; i < maxn; ++ i)
		b[i] = (1 - a[i]) + b[i-1];
	int n;
	std::cin >> n;
	for(int i = n; i < maxn ; ++i)
		if(a[i] == 0 && a[ b[i] ] == 0) {
			n = i;
			break;
		}
	printf("%d\n", n);
	return 0;
}
