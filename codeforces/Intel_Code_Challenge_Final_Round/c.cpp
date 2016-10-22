/*************************************************************************
    > File Name: c.cpp
    > Author: opas_chenxin
    > Mail: 1017370773@qq.com 
    > Created Time: 2016年10月08日 星期六 22时01分54秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
struct point{
	ll x,y,d;
	point(ll x1 = 0, ll y1 = 0, ll d1 = 0) {
		x = x1; y = y1; d = d1;
	}
 	bool operator < (point const&A) const{
		 if(x != A.x) return x < A.x;
		 if(y != A.y) return y < A.y;
		 return d < A.d;
	}
	//bool operator == (point &A){
	//	return x == A.x && y == A.y && d == A.d;
	//}
};
map<point,ll> G;
ll n,m,k;
ll edg_w[4]={0,0,0,0};
bool GetNextPoint(int loc, point A, ll &t, point &B, int fu) {
		ll b = A.y - A.d * A.x;
		if(loc&1) {
			B.y = edg_w[loc];
			B.x = (B.y - b) * A.d;
			t = abs(A.y - edg_w[loc]);
		}	else {
			B.x = edg_w[loc];
			B.y = B.x * A.d + b;
			t = abs(A.x - edg_w[loc]); 
		}
		B.d = A.d * fu; 
		if(B.x < 0 || B.x > n || B.y < 0 || B.y > m || (B.x == A.x && B.y == A.y) )
			return false;
		return true;
}
point GetNextLoc(point &A, ll &t ) {
	point next_loc;
	ll tt;
	for(int i = 0; i < 4; ++ i) {
		if(GetNextPoint(i, A, tt, next_loc, -1)) {
			t += tt;
			return next_loc;
		}
	}
	return next_loc;
}
bool JudEnd(point &A){
	if(A.x == 0 && A.y == 0) return true;
	if(A.x == 0 && A.y == m) return true;
	if(A.x == n && A.y == 0) return true;
	if(A.x == n && A.y == m) return true;
	return false;
}
ll GetAns(point &A){
	ll t=0;
	ll ans = -1;
	for(int i = 0; i < 2; ++ i) {
		A.d = -A.d;
		for(int j = 0; j < 4; ++ j) {
			point B;
			if(GetNextPoint(j, A, t, B, 1)) {
				if(G.count(B) > 0) {
					if(ans == -1) 
						ans = G[B]+t;
					else
						ans = min(G[B]+t, ans); 
				}
			}
		}
	}
	if(ans != -1) ans = ans -1;
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	while( cin>>n>>m>>k ) {
		edg_w[2] = n;
		edg_w[3] = m;
		G.clear();
		point now = point(0,0,1);
		ll t = 1;
		G.insert(pair<point,ll>(now,t));
		while(true) {
			point next_loc = GetNextLoc(now, t);
			if(JudEnd(next_loc)) break;
			if(G.count(next_loc) > 0) break;
			else G.insert(pair<point,ll>(next_loc,t));
			now = next_loc;
			G.insert(pair<point,ll>(now,t));
		}
		for(int i = 0; i < k; ++ i) {
			ll x, y;
			cin>>x>>y;
			point A = point(x, y, 1);
			cout<<GetAns(A)<<endl;
		}
	}
	return 0;
}
