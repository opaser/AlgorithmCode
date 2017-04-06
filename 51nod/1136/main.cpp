#include<cstdio>
#include<iostream>
#include<algorithm>
int euler(int n)
{
	int i;
	int res = n, a= n;
	for(i = 2; i*i <= a; ++i) {
		if(a%i == 0) {
			res -= res/i;
			while(a%i == 0) a/=i;
		}
	}
	if(a > 1) res -= res/a;
	return res;
}
int main()
{
	int n;
	std::cin>>n;
	std::cout<<euler(n)<<std::endl;
	return 0;
}
