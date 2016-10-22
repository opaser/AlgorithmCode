/*************************************************************************
    > File Name: 297.cpp
    > Author: opas-chenxin
    > Mail: opaser@foxmail.com 
    > Created Time: 2016年10月07日 星期五 15时59分41秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 8200;
struct Node {
	int color,number;
	int ch[4];
};
Node node[maxn];
char S[maxn];
int color_loc,node_loc;

int BuildTree(int number)	{
	int loc_c = 0;
	int fa = node_loc;
	if (S[color_loc] == 'f') 
		loc_c = 1;
	else if(S[color_loc] == 'p') 
		loc_c = 3;
	else 
		loc_c = 7;
	node[node_loc].color = loc_c;
	node[node_loc].number = number;
	++ node_loc;
	++ color_loc;	
	if (loc_c == 3) {
		int child_num = number/4;
		for(int i = 0; i < 4; ++ i)
			node[fa].ch[i] = BuildTree(child_num);
	}else {
		for(int i = 0; i < 4; ++ i)
			node[fa].ch[i] = -1;
	}
	return fa;
}
int CalNumber(int node_a, int node_b) {
	if (node[node_a].color == 1 || node[node_b].color == 1)	{
		return node[node_a].number;
	}
	if (node[node_a].color == 7 && node[node_b].color == 7) {
		return 0;
	}
	int sum = 0;
	if (node[node_a].color == 3 && node[node_b].color == 3) {
		for(int i = 0; i < 4; ++ i)
			sum += CalNumber(node[node_a].ch[i], node[node_b].ch[i]);
		return sum;
	}
	if (node[node_a].color == 3)	{
		for(int i = 0; i < 4; ++ i)
			sum += CalNumber(node[node_a].ch[i], node[node_a].ch[i]);
	} else {
		for(int i = 0; i < 4; ++ i)
			sum += CalNumber(node[node_b].ch[i], node[node_b].ch[i]);
	}
	return sum;
}
int main()
{
	freopen("in", "r", stdin);
	int cas = 0;
	scanf("%d",&cas);
	for( int cc = 1; cc <= cas; ++ cc) {
		color_loc = node_loc = 0;
		scanf("%s", S);
		int root1 = BuildTree(1024);
		scanf("%s", S);
		color_loc = 0;
		int root2 = BuildTree(1024);
		int sum_num = CalNumber(root1, root2);
		printf("There are %d black pixels.\n", sum_num);
	}
	return 0;
}



