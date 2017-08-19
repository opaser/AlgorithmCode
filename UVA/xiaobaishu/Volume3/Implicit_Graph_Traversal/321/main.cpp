#include<cstdio>
#include<string.h>
#include<algorithm>
const int maxn = 10;
const int maxn_status = 1 << 10;
int connect_door[maxn][maxn];
int switch_to[maxn][maxn];
struct Status
{
	Status(int loc_ = 0, int status_ = 0, int op_ = 0, int to_ = 0)
	{
		loc = loc_, statu = status_, op = op_, to = to_;
	}
	int loc,statu,op,to;
};
int dp[maxn][maxn_status];
struct Status per_status[maxn][maxn_status];
void ClearData(int room_num)
{
	for(int i = 0; i < room_num; ++ i)
		for(int j = 0; j < room_num; ++j)
			connect_door[i][j] = switch_to[i][j] = 0;
	for(int i = 0; i < room_num; ++ i)
		for(int j = 0; j < 1<<room_num; ++j)
			dp[i][j] = -1;		

}
void dfs(int room_num, int loc, int stat_now)
{
	int now_cost = dp[loc][stat_now];
	for(int j = 0; j < room_num; ++j)
	{
		if(switch_to[loc][j])
		{
			
			if(stat_now&(1<<j))							
			{
				if(j != loc)
				{
					int next_stat = stat_now ^ (1 << j);
					int will_cost = dp[loc][next_stat];
					if(will_cost == -1 || will_cost > now_cost + 1)
					{
						per_status[loc][next_stat] = Status(loc, stat_now, 0, j);
						dp[loc][next_stat] = now_cost + 1;
						dfs(room_num, loc, next_stat);
					}
				}
			}
			else
			{
				int next_stat = stat_now | (1 << j);
				int will_cost = dp[loc][next_stat];
				if(will_cost == -1 || will_cost > now_cost + 1)
				{
					per_status[loc][next_stat] = Status(loc, stat_now, 1, j);
					dp[loc][next_stat] = now_cost + 1;
					dfs(room_num, loc, next_stat);
				}
			}
		}
		if(connect_door[loc][j])
		{
			if( loc != j && (stat_now & (1 << j)))
			{
				int next_stat = stat_now;
				int will_cost = dp[j][next_stat];
				if(will_cost == -1 || will_cost > now_cost + 1)
				{
					per_status[j][next_stat] = Status(loc, stat_now, 2, j);
					dp[j][next_stat] = now_cost + 1;
					dfs(room_num, j, next_stat);
				}
					
			}
		}
	}
}
void Output(int loc, int statu)
{
	Status &a = per_status[loc][statu];
	if(a.loc != -1)
	{
		Output(a.loc, a.statu);
		if(a.op == 0)
			printf("- Switch off light in room %d.\n", a.to+1);
		else if(a.op == 1)
			printf("- Switch on light in room %d.\n", a.to+1);
		else
			printf("- Move to room %d.\n", a.to+1);

	}
}
int main() 
{
	int r,d,s;
	for(int cc = 1; ; ++ cc)
	{
		scanf("%d%d%d", &r, &d, &s);
		if(r + d + s == 0)
			break;
		ClearData(r);
		for(int i = 0; i < d; ++ i)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			--a,--b;
			connect_door[a][b] = connect_door[b][a] = 1;
		}

		for(int i = 0; i < s; ++ i)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			--a,--b;
			switch_to[a][b] = 1;
		}
		dp[0][1] = 0;
		per_status[0][1].loc = -1, per_status[0][1].statu = -1;
		dfs(r, 0, 1);
		printf("Villa #%d\n", cc);
		if(dp[r-1][1<<(r-1)] != -1)
		{
			printf("The problem can be solved in %d steps:\n",dp[r-1][1<<(r-1)]); 	
			Output(r-1, 1<<(r-1));
		}
		else
		{
			printf("The problem cannot be solved.\n");			
		}
		puts("");
	}
	return 0;
}

