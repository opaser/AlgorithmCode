/*************************************************************************
 > File Name: a.cpp
 > Author: opas_chenxin
 > Mail: 1017370773@qq.com 
 > Created Time: 2016年05月03日 星期二 07时29分34秒    
*************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 105;
int A[maxn];
int main(int argc, char *argv[])
{
	int n,t;
	freopen("in","r",stdin);
	while(scanf("%d%d",&n,&t)==2)
	{
		if(t == 10 && n == 1)
		{
			printf("-1\n"); 
			continue;	
		}
		if(n == 1)
		{
			printf("%d\n",t);
			continue;
		}
		for(int i = 1; i < n; ++ i)
		{
			A[i-1]=1;
		}
		int end_d=-1;
		int d = 0;
		for(int i=0; i<n-1; ++i)
		{
		  d = d * 10 + A[i];
		  d = d % t;
		}
		for(int i = 0; i < 10; ++ i)
		{
			int te = d * 10 + i;
			if(te % t == 0)
			{
				end_d = i; 
				break;
			}
		}
		A[n-1] = end_d;
		for(int i = 0; i < n; ++ i)
			printf("%d",A[i]);
		puts("");
	}
    return 0;
}
