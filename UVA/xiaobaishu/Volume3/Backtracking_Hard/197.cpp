#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct Point{
	int x,y;
	Point(int l_x = 0, int l_y = 0){
		x = l_x;
		y = l_y;
	}
};
struct Cube{
	int A[3][3][3];
};
class Change {
	public:
		Change(){
			change_location_corner[0] = Point(0,0);
			change_location_corner[1] = Point(0,2);
			change_location_corner[2] = Point(2,2);
			change_location_corner[3] = Point(2,0);
			change_location_center[0] = Point(0,1);
			change_location_center[1] = Point(1,2);
			change_location_center[2] = Point(2,1);
			change_location_center[3] = Point(1,0);
		}
		void ChangeVertical(Cube &A)	{
			for(int i3 = 0; i3 < 3; ++ i3)	{
				Point l_a = change_location_corner[0];
				int v = A.A[l_a.x][l_a.y][i3];
				for(int j = 0; j < 3; ++ j) {
					Point l_loc = change_location_corner[j];
					Point l_nex = change_location_corner[j+1];
					A.A[l_loc.x][l_loc.y][i3] = A.A[l_nex.x][l_nex.y][i3];
				}
				l_a = change_location_corner[3];
				A.A[l_a.x][l_a.y][i3] = v;
				l_a = change_location_center[0];
				v = A.A[l_a.x][l_a.y][i3];
				for(int j = 0; j < 3; ++ j)	{
					Point l_loc = change_location_center[j];
					Point l_nex = change_location_center[j+1];
					A.A[l_loc.x][l_loc.y][i3] = A.A[l_nex.x][l_nex.y][i3];
				}
				l_a = change_location_center[3];
				A.A[l_a.x][l_a.y][i3] = v;
			}
		}
		void ChangeLevel(Cube &A)	{
			for(int i1 = 0; i1 < 3; ++ i1)	{
				Point l_a = change_location_corner[0];
				int v = A.A[i1][l_a.x][l_a.y];
				for(int j = 0; j < 3; ++ j)	{
					Point l_loc = change_location_corner[j];
					Point l_nex = change_location_corner[j+1];
					A.A[i1][l_loc.x][l_loc.y] = A.A[i1][l_nex.x][l_nex.y];
				}
				l_a = changet_location_corner[3];
				A.A[i1][l_a.x][l_a.y] = v;

				l_a = change_location_center[0];
				v = A.A[i1][l_a.x][l_a.y];
				for(int j = 0; j < 3; ++ j)	{
					Point l_loc = change_location_center[j];
					Point l_nex = change_location_center[j+1];
					A.A[i1][l_loc.x][l_loc.y] = A.A[i1][l_nex.x][l_nex.y];
				}
				l_a = change_location_center[3];
				A.A[i1][l_a.x][l_a.y] = v;
			} 
		}
	private:
		Point change_location_corner[4];
		Point change_location_center[4];
};
int main()	{


	return 0;
}
