/********************
Function:   分组背包问题
			物品分为若干组，每组最多选一件物品，不超过背包容量的最优值
Inputs:     二维数组中v[i][k]表示第i组中的第k个物品的value
			二维数组中w[i][k]表示第i组中的第k个物品的weight
			数组m中m[i]记录第i组中的物品数;
			int c  背包容量capability
			int g  表示多少组group
Return:     返回该问题的最优值
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  分组背包问题
int Knapsack6(vector<vector<int> > v, vector<vector<int> > w, vector<int> m, int c, int g)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < g; ++i)
		for (int j = c; j > 0; --j)
			for (int k = 0; k < m[i]; ++k)
				if (j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
	return dp[c];
}