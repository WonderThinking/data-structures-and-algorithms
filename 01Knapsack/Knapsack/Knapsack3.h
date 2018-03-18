/********************
Function:   多重背包问题
			每件物品的数量有约束，求不超过背包容量的最大价值
Inputs:     int[] v  各个物品的价值value
			int[] w  各个物品的重量weight
			int   c  背包容量capability
			int   n  物品的种数即v,w的数组大小
Return:     返回该问题的最优值
*********************/
#include<vector>
#include<algorithm>
using namespace std;

// 多重背包问题
int Knapsack3(int* v, int* w, int* N, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			for (int k = 1; k <= N[i] && j - k*w[i] >= 0; ++k)
				dp[j] = max(dp[j], dp[j - k*w[i]] + k*v[i]);
	return dp[c];
}