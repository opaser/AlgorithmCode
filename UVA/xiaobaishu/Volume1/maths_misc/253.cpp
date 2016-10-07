#include<iostream>
#include<string.h>
#include<cstdio>
int level_change[7] = {0, 1, 4, 2, 5, 3, 6};
int vertical_change[7]= {0, 2, 6, 3, 4, 1, 5};
struct Cube
{
	char ch[7];
	void clear() {
		for(int i = 0; i < 7; ++ i) {
			ch[i] = 'b';
		}
	}
	void init(char *s) {
		for(int i = 1; i < 7; ++ i) {
			ch[i] = s[i - 1];
		}
	}
	void levelChange() {
		char C[7];
		for(int i = 1; i < 7; ++ i) {
			char c = ch[i];
			C[ level_change[i] ] = c;
		}
		for(int i = 1; i < 7; ++ i) {
			ch[i] = C[i];
		}
	}
	void verticalChange() {
		char C[7];
		for(int i = 1; i < 7; ++ i) {
			char c = ch[i];
			C[vertical_change[i]] = c;
		}
		for(int i = 1; i < 7; ++ i) {
			ch[i] = C[i];
		}
	}
	void changeLoc(int level, int ver) {
		for(int i = 0; i < level; ++ i)
			levelChange();
		for(int i = 0; i < ver; ++ i)
			verticalChange();
	}
	void copyCube(Cube &cu) {
		for(int i = 0; i < 7; ++ i)
			ch[i] = cu.ch[i];
	}
};
bool CubeCmp(Cube &A, Cube &B) {
	for(int i = 1; i < 7; ++ i)
		if(A.ch[i] != B.ch[i])
			return false;
	return true;
}
int step_change[6][2] = {{0, 0},{0, 3},{1, 3},{1, 1},{0, 1},{0, 2}};
char S[16];
Cube A,B,C;
int main()
{
	freopen("in", "r", stdin);
	while(scanf("%s",S) == 1) {
		A.init(S);	
		B.init(S+6);
		bool is_same = false;
		for(int i = 0; i < 6; ++ i) {
			C.copyCube(B);
			C.changeLoc(step_change[i][0], step_change[i][1]);
			for(int i = 0; i < 4; ++ i)
			{
				C.levelChange();
				if(CubeCmp(C, A)) {
					is_same = true;
					break;
				}
			}
			if(is_same == true)
				break;
		}
		printf("%s\n", is_same ? "TRUE":"FALSE" );
	}		 
	return 0;
}
