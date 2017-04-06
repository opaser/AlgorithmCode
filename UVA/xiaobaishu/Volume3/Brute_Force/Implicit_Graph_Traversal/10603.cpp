#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iosteam>
#include<queue>
using namespace std;
const int maxn= 205;
struct status{
	int v[3];
	status(){
		for(int i = 0; i < 3; ++ i)
			v[i] = 0;
	}
	status(int a, int b, int c) {
		v[0] = a;
		v[1] = b;
		v[2] = c;
	}
}start;
int dp[maxn][maxn][maxn];

void init() {
	memset(dp, -1, sizeof(dp));
}

int Change(int a, int b, struct status &from, struct status &to ) {
	if( from.v[a] == 0 || to.v[b] == start.v[b] ) {
		return 0;
	} 
	
} 

void Work_Bfs(struct status start) {
	dp[0][0][start.v[2]] = 0;
	queue<status> Q;
	Q.push( status(0, 0, start.v[2]) );
	while( !Q.empty() ) {
		struct status from = Q.front()
		Q.pop();
		for(int a = 0; a < 3; ++ a)
		 if(from.v[a] != 0) {
			for(int b = 0; b < 3; ++ b) 
				if(a != b) {
					struct status pd;
					int use_v = 0;
					if( (use_v = Change(a, b, from, pd) ) != 0) {
					  int next_v = dp[ from.v[0] ][ from.v[1] ][ from.v[2] ] + use_v;	
						if( dp[ pd.v[0] ][ pd.v[1] ][ pd.v[2] ] == -1 || 
								next_v < dp[ pd.v[0] ][ pd.v[1] ][ pd.v[2] ] ) {
								dp[ pd.v[0] ][ pd.v[1] ][ pd.v[2] ] = next_v;
								Q.push( pd );
						}
				 }
			}
		 }
	}
}

int mian(int argc,char *argv[])
{
	int cas;
	scanf("%d", &cas);
	for(int cc = 1; cc <= cas; ++ cc) {
		int d;
		scanf("%d%d%d%d", &start.v[0], &start.v[1], &start.v[2], &d);
		Work_Bfs(start);
	}
	return 0;
}
