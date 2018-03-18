/********************
Function:   泛化物品的背包问题
Inputs:     int[] v   各个物品的价值value
			int[] w   各个物品的重量weight
			数组m中m[i]记录第i组中的物品数
			int   c  背包容量capability
			int   n  物品的种数
Return:     返回该问题的最优值
Others:		泛化物品的背包问题本质上与分组背包问题 类似
			泛化物品 w = h(v)， 首先需要根据容量c的约束先计算出v和w
			例题一http://blog.csdn.net/qq_39670434/article/details/79483102
			例题二http://www.hihocoder.com/discuss/question/2640
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  泛化物品的背包问题
int Knapsack8(vector<vector<int> > v, vector<vector<int> > w, vector<int> m, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j > 0; --j)
			for (int k = 0; k < m[i]; ++k)
				if (j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
	return dp[c];
}