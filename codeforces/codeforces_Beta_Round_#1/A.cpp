/*************************************************************************
 > File Name: A.cpp
 > Author: opas_chenxin
 > Mail: 1017370773@qq.com 
 > Created Time: 2016年05月06日 星期五 02时22分23秒    
*************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(int argc, char *argv[])
{
	int n,m,a;
	freopen("in","r",stdin);
	while(scanf("%d%d%d",&n,&m,&a) == 3)
	{
		int d1 = (n+a-1)/a;
		int d2 = (m+a-1)/a;
		cout<<1LL*d1*d2<<endl;
	}
    return 0;
}
