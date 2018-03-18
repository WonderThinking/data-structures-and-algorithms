/********************
Function:   0/1背包问题
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

//  0/1背包问题(不超过背包容量)
int Knapsack1_1(int* v, int* w, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c];
}

//  0/1背包问题(不超过背包容量),输出最优值及打印组成最大的价值的背包(最优解)
int Knapsack1_2(int* v, int* w, int c, int n)
{
	vector<vector<int> > dp(n, vector<int>(c + 1, 0));
	for (int j = w[0]; j <= c; ++j)
		dp[0][j] = v[0];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= c; ++j)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	// 打印组成最优解的物品号
	int value = dp[n - 1][c];
	int i = n - 1;
	int j = c;
	while (value > 0)
	{
		if (i <= 0 || dp[i - 1][j] != value)
		{
			printf("%d ", i);
			value = value - v[i];
			j = c - w[i];
		}
		--i;
	}
	return dp[n - 1][c];
}

// 0/1背包问题(恰好装满问题)
int Knapsack1_3(int* v, int* w, int c, int n)
{
	int MIN = 0x80000000; //最小负数标记非法状态,正常运算中不能出现达到或者超过INF的情况,即MIN应足够小
	vector<int> dp(c + 1, MIN);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c] >= 0 ? dp[c] : 0;
}
