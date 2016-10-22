/*************************************************************************
    > File Name: a.cpp
    > Author: opas_chenxin
    > Mail: 1017370773@qq.com 
    > Created Time: 2016年10月08日 星期六 20时40分40秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
char A[10][10]={"sunday" , "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int day[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int have[10][10];
int main() {
	freopen("in", "r", stdin);
	memset(have, 0, sizeof(have));
	for(int i = 0; i < 7; ++ i)  {
		int perk = i;
		int k = i;
		for(int j = 0; j < 11; ++ j)	{
			 k = (k + day[j])%7;
			 have[perk][k] = 1;
			 perk = k;
		}
	}
	char S[2][10];
	while(scanf("%s%s", S[0], S[1]) == 2)	{
		int a = 0;
		for(int i = 0; i < 7; ++ i)
			if(strcmp(A[i],S[0]) == 0)	{
				a = i ; break;
			}
		int b = 0;
		for(int i = 0; i < 7; ++ i)	{
			if(strcmp(A[i] ,S[1]) == 0) {
				b = i; break;
			}
		}
		if(have[a][b]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
