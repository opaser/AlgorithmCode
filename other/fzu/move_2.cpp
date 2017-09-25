#include <cstdio>
#include <algorithm>
#include <iostream>
const int MAX_STATUSA = 1<<16;
const int MAX_NUM = 33;
long long dp[2][MAX_STATUSA]; 
long long per_volume[MAX_NUM];


long long FindData(int num, long long target)
{
	int L = 0, R = num;
	while(L < R)
	{
		int mid = (L + R + 1) >> 1;
		
		if(dp[0][mid] > target)
			R = mid - 1;
		else if(dp[0][mid] <= target) 
			L = mid;

	}	
	return dp[0][L];
}

long long ProcessData(int num, long long sum_volume)
{
	int half_num = (num + 1) >> 1;
	for(int i = 0; i < (1 << half_num); ++ i)	
	{
		dp[1][i] = dp[0][i] = 0;
		for(int j = 0; j < half_num; ++ j)
		{
			if(i & (1<<j))
			{
				dp[0][i] += per_volume[j << 1];
				if( (j<<1) + 1 < num)
					dp[1][i] += per_volume[ (j << 1) + 1];
			}
		}
	}
	std::sort(dp[0], dp[0] + (1 << half_num));
	int enum_num = num >> 1;
	long long ans = sum_volume;
	for(int i = 0; i < (1 << enum_num); ++i)
	{
		long long remain = sum_volume - dp[1][i];
		if(remain < 0)
			continue;
		long long volume_other = FindData((1 << half_num) - 1, remain); 
		remain -= volume_other;	
		ans = ans > remain ? remain : ans; 
	}
	return ans;
}
int
main()
{
	int sum_num;
	long long sum_volume;

	while(std::cin >> sum_num >> sum_volume)
	{
		for(int i = 0; i < sum_num; ++ i)
			std::cin>>per_volume[i];
		std::cout << ProcessData(sum_num, sum_volume) << std::endl;
	}

	return 0;
}

