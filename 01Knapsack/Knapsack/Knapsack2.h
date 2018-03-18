/********************
Function:   完全背包问题 
			每件物品可以无限使用，求不超过背包容量的最大价值
Inputs:     int[] v  各个物品的价值value
			int[] w  各个物品的重量weight
			int   c  背包容量capability
			int   n  物品的种数即v,w的数组大小
Return:     返回该问题的最优值
Others:     仅输出最优值采用空间压缩，若输出最优解则不能压缩空间
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  完全背包问题最优值
int Knapsack2_1(int* v, int* w, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = w[i]; j <= c; ++j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c];
}

//  完全背包问题的最优值及其方案
int Knapsack2_2(int* v, int* w, int c, int n)
{
	vector<vector<int> > dp(n, vector<int>(c + 1, 0));
	int k = 1;
	for (int j = w[0]; j <= c; ++j)
		dp[0][j] = dp[0][j - w[0]] + v[0];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= c; ++j)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	int value = dp[n - 1][c];
	int j = c;
	int i = n - 1;
	while (value > 0)
	{
		if (i <= 0 || dp[i - 1][j] != value)
		{
			printf("%d ", i);
			value = value - v[i];
			j = j - w[i];
		}
		else
			--i;
	}
	return dp[n - 1][c];
}