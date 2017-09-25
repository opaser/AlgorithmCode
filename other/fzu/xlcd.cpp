#include <algorithm>
#include <cstdio>
#include <string.h>
#include<iostream>
using namespace std;
const int maxn = 9;
const int maxn_len = 10;
char str[maxn][maxn_len];
int now_pro[maxn];
int str_len[maxn];
struct node{
	char a;
	int num;
	node(){
		a=0;
		num=0;
	}
	bool operator < ( const struct node &A) const{
		return num > A.num;
	}
};
int ans =0;
void dfs(int dep, int n)
{
	if(dep >= ans ) return;
	struct node a[4];
	int mark[maxn];
	memset(mark, 0, sizeof(mark));
	for(int i = 0; i< 4; ++i)
	 a[i].a = 'a'+i, a[i].num=0;
	for(int i = 0; i < n ; ++ i) 
		if(now_pro[i] < str_len[i])
			a[ str[i][ now_pro[i] ] - 'a' ].num++;
	sort(a,a+4);
	if(a[0].num == 0) {
		ans = dep;
		return ;
	}
	for(int i = 0; i < 4; ++ i)
		if(a[i].num > 0){
			for(int j = 0; j < n; ++ j)
				if(a[i].a == str[j][ now_pro[j]  ]) 
						 mark[j] = 1, now_pro[j]++;
				else mark[j] = 0;
			dfs(dep+1, n);
			for(int j = 0; j < n; ++ j)
				if(mark[j]) now_pro[j]--,mark[j] = 0;
		}
}
int main()	{
	freopen("in","r",stdin);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) {
		scanf("%s", str[i]);
		str_len[i] = strlen(str[i]);
		ans += str_len[i];
		now_pro[i]=0;
	}
	dfs(0,n);
	printf("%d\n", ans);
	return 0;
}
