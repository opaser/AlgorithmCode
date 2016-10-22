/*************************************************************************
    > File Name: 10129.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年10月07日 星期五 22时39分44秒
 ************************************************************************/
#include<cstdio>
#include<string.h>
const int maxn = 27;
const int maxm = 100005;
const int char_len = 1005;
int head_table[maxn], num_of_edg, next_edg[maxm], next_to[maxm], vis_edg[maxm];
int in_num[maxn], out_num[maxn];
int now_step[maxn];
char S[char_len];
void AddEdge(int from, int to)	{
	++ num_of_edg;
	next_to[num_of_edg] = to;
	next_edg[num_of_edg] = head_table[from];
	vis_edg[num_of_edg] = 0;
	head_table[from] = num_of_edg;
	++ in_num[to];
	++ out_num[from];
}
void euler(int x)	{
	for(int &i = now_step[x]; i; i = next_edg[i])	{
		if(vis_edg[i] == 0)	{
			vis_edg[i] = 1;
			-- in_num[next_to[i]];
			-- out_num[x];
			euler(next_to[i]);
		}
	}
}
char unpatter[30] = "The door cannot be opened.";
char patter[30] = "Ordering is possible.";
int main() 
{
	freopen("in", "r", stdin);
	int cas;
	scanf("%d", &cas);
	for(int cc = 1; cc <= cas; ++ cc)	{
		num_of_edg = 0;
		memset(head_table, 0, sizeof(head_table));
		memset(in_num, 0, sizeof(in_num));
		memset(out_num, 0, sizeof(out_num));
		int n;
		scanf("%d", &n);
		int st=0, ge =0;
		for(int i = 0; i < n; ++ i) {
			scanf("%s", S);
			int len = strlen(S);
			AddEdge(S[0] - 'a', S[len - 1] - 'a');
			st = S[0] - 'a';
		}
		
		for(int i = 0; i < 26; ++ i)	{
			now_step[i] = head_table[i];
			if(in_num[i] != out_num[i]) {
				ge++;
				if(in_num[i] < out_num[i]) 
					st = i;
				if(in_num[i] - out_num[i] < -1 || in_num[i] - out_num[i] > 1)	{
					ge = 3;
					break;
				}
			}	
		}
		if (ge > 2 )	{
			puts(unpatter);
			continue;
		}
		euler(st);
		for(int i = 0; i < 26; ++ i)	{
			if(in_num[i] > 0 || out_num[i] > 0) {
				ge = 3;
				break;
			}
		}
		if(ge > 2) 
			puts(unpatter);
		else
			puts(patter);
	}
	return 0;
}
