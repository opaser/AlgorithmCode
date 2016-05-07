/*************************************************************************
 > File Name: B.cpp
 > Author: opas_chenxin
 > Mail: 1017370773@qq.com 
 > Created Time: 2016年05月06日 星期五 20时28分30秒    
*************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 5000000;
char A[maxn];
char B[maxn];
void solve1(int len)
{
	int a1 = 0;
	int loc = 0;
	while(loc<len)
	{
		if(A[loc] >= 'A' && A[loc] <= 'Z')
		{
			a1 = a1 * 26 + A[loc] - 'A' + 1; 
		}else
		{
			break;
		}
		loc++;
	}
	int b1 = 0;
	while(loc<len)
	{
		b1 = b1*10 + A[loc] -'0';
		loc++;
	}
   printf("R%dC%d\n",b1,a1);
}
void solve2(int len)
{
  int b1 = 0;
  int loc=1;
  while(loc < len)
  {
	if(A[loc] == 'C') break;
	b1=b1*10+A[loc]-'0';
	loc++;
  }
  loc++;
  int a1 = 0;
  while(loc < len)
  {
	  a1 = a1 * 10 + A[loc] - '0';
	  loc++;
  }
  loc = 0;
  while(a1>0)
  {
	int v = a1%26;
	char c='Z';
	if(v != 0)
		c = 'A'+ v - 1;
	a1 -= c - 'A' + 1;
	a1 /= 26;
    B[loc ++] = c;
  }
  B[loc]='\0';
  for(int i = 0; i < loc/2; ++ i)
  {
	  char tem = B[i];
	  B[i] = B[loc-i-1];
	  B[loc - i - 1] = tem;
  }
  printf("%s%d\n",B,b1);
}
int main(int argc, char *argv[])
{
	freopen("in","r",stdin);
	int cas;
	scanf("%d",&cas);
	for(int cc = 1; cc <= cas; ++ cc)
	{
		scanf("%s",A);
		int len = strlen(A);
		int num = 0, per = 0;
		for(int i = 0; i < len; ++ i)
		{
			if(A[i] >= 'A' && A[i] <= 'Z')
			{
				if(per == 0) 
				{
					per = 1;
					num++;
				}
			}else{
				per = 0;
			}
		}
		if(num == 1)
			solve1(len);
		else solve2(len);
	}
	return 0;
}
