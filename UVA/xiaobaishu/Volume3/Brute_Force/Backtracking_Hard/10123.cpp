/*************************************************************************
    > File Name: 10123.cpp
    > Author: opas
    > Mail: 1017370773@qq.com 
    > Created Time: 2016年10月22日 星期六 22时58分53秒
 ************************************************************************/
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxm = 20;
const int maxn = 1<<maxm;
struct Node {
	int id,weight,dist;
	Node (int l_id = 0, int l_weight = 0, int l_dist = 0)	{
		id = l_id;
		weight = l_weight;
		dist = l_dist;
	}
	bool operator < (const Node A)const {
		if (weight != A.weight ) return weight < A.weight;
		return id < A.id;
	}
}package[maxm];
int dp[maxn];
int weight_val[maxn][4];
int ans[maxm];
void InitVal(int n)	{
	int max_val = 1<<n;
	for(int i = 0; i < max_val; ++ i)	{
		dp[i] = 0;
	}
}
int length ,weight, num_package;
void AddPackage(int per_status ,int now_status, int id)	{
	for ( int i = 0; i < 4; ++ i)
		weight_val[now_status][i] = weight_val[per_status][i];
	if(package[id].dist <= -3)	{
		weight_val[now_status][0] = weight_val[per_status][0] + - ( package[id].dist + 3) * package[id].weight; 
		weight_val[now_status][3] = weight_val[per_status][3] + - ( package[id].dist - 3) * package[id].weight;
	}else if(package[id].dist < 3){
		weight_val[now_status][1] = weight_val[per_status][1] + (package[id].dist + 3) * package[id].weight;
		weight_val[now_status][3] = weight_val[per_status][3] + - (package[id].dist - 3) * package[id].weight;
	}else{
		weight_val[now_status][1] = weight_val[per_status][1] + (package[id].dist + 3)*package[id].weight;
		weight_val[now_status][2] = weight_val[per_status][2] + (package[id].dist - 3)*package[id].weight;
	}
}
int CheckPackage(int now_status)	{
	int l_val1 = weight_val[now_status][0];
	int l_val2 = weight_val[now_status][1] +3 * weight;
	if(l_val1 > l_val2){
	  return dp[now_status] = 2; 
	}
	l_val1 = weight_val[now_status][2];
	l_val2 = weight_val[now_status][3] + 3 * weight;
	if(l_val1 > l_val2) {
		return dp[now_status] = 2;
	}
		return dp[now_status] = 1;
}
int dfs(int now_loc, int now_status)	{
	if(now_loc == num_package)	{
		return 1; 
	}
	dp[now_status] = 2;
	for(int i = 0; i< num_package ; ++ i)	{
		if(now_status & (1<<i)) 
			continue;
		int next_status = now_status | (1<<i);
		if(dp[next_status] == 2) return dp[next_status];
		AddPackage(now_status, next_status, i);
		if(CheckPackage(next_status) == 2) 
			continue;
		ans[now_loc] = i;
		if (dfs(now_loc+1, next_status) == 1)	{
			return dp[now_status]=1;
		} 
	}
	return 2;
}
int main(){ 
	freopen("in", "r", stdin);	
	for(int cc = 1; ; ++ cc) {	
		cin>>length>>weight>>num_package;
		if(length + weight + num_package == 0)
				break;
		InitVal(num_package);
		for(int i = 0; i < num_package; ++ i)	{
			int l_weight , l_dist;
			scanf("%d%d",&l_dist, &l_weight);	
			l_dist = l_dist * 2;
			package[i] = Node(i, l_weight, l_dist);
		}
		printf("Case %d:\n",cc);
		if( dfs(0 , 0) == 1) {
			for(int i = num_package - 1; i >= 0; -- i)	{
				printf("%d %d\n", package[ans[i]].dist/2, package[ans[i]].weight);
			} 
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
}
