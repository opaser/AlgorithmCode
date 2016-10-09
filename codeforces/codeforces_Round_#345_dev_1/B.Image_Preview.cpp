/***************************
 * author opas chenxin     *
 * Email opaser@foxmail.com*
 * *************************/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 500005;

char S[maxn];
bool vis[maxn];
int ans = 0;
int Solve(int n, int a, int b, int T)
{
	memset(vis, false, sizeof(vis));
	int left_time = T;
	int p_ans = 0, cnt = 0;  
	
	for(int i = 0; i < n; ++ i) {
		if(S[i] == 'w') left_time -= b;
		-- left_time;
		if(left_time < 0 ) break;
		++ cnt;
		left_time -= a;
	}
	p_ans = cnt;
	left_time = T;
	
	for(int i = 0; i < cnt; ++i) {
		if(S[i] == 'w') left_time -= b;
		vis[i] = true;
		-- left_time;
		if(i != cnt - 1)
			left_time -= a;
	}
	int head = 0;	
	int tail = cnt - 1; 
	while(true) {
		--head;
		left_time -= a * 2;
		if(head == -1) head = n - 1;
		if(S[ head ] == 'w') left_time -= b;
		-- left_time;
		++ cnt;
		if( vis[head] )break;
		while(left_time < 0 && tail > 0) {
			vis[tail] = false;
			if(S[tail] == 'w') left_time += b;
			++ left_time;
			left_time += a;
			-- tail;
			-- cnt;
		}
		if(left_time < 0 || tail <= 0 )break;
	  p_ans = max(cnt, p_ans);
	}
	return p_ans;
}
void Reverse(int len, char *ch)
{
	for(int i = 0; i < len/2 ; ++ i) {
		char c = ch[i];
		ch[i] = ch[len - i - 1];
		ch[len - i - 1] = c;
	}
}
int main() 
{
	freopen("in", "r", stdin);
	int n,a,b,T;
	while(scanf("%d%d%d%d",&n, &a, &b, &T) == 4) {
		scanf("%s",S);
		ans = Solve(n, a, b, T);
		Reverse(n - 1, S+1);
		ans = max(Solve(n, a, b, T), ans);
		printf("%d\n",ans);
	}
	return 0;
}
