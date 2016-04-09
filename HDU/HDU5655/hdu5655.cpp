/*************************************************************************
 > File Name: hdu5655.cpp
 > Author: opas_chenxin
 > Mail: 1017370773@qq.com 
 > Created Time: 2016年04月07日 星期四 21时41分35秒    
*************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef unsigned long long LL;
LL A[5];
int main(int argc, char *argv[])
{
    freopen("in","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int cc = 1; cc <= cas; ++ cc)
	{
	   for(int i = 0; i < 4; ++ i)
	   {
		   cin>>A[i];
	   }
	   sort(A,A+4);
	   if(A[0] <=0 )
	   {
		   puts("No");
		   continue;
	   }
	   LL a = 0;
	   bool l_issucceed = false;
	   for(int i = 0; i < 3; ++i)
	   {
		   a += A[i];
		   if(a > A[3] || (i != 2 &&a >= A[3]) )
		   {
			   l_issucceed = true;
			   break;
		   }
	   }
	   if(l_issucceed)
	   {
		   puts("Yes");
	   }else{
		   puts("No");
	   }
	}

	return 0;
}
