/********************
Function:   有依赖的背包问题
			这里没有某个物品既依赖于别的物品,又被别的物品所依赖
			也没有某件物品同时依赖多件物品 （主件-附件）
Inputs:     二维数组中v[i][k]表示第i组中的第k个物品的value
			二维数组中w[i][k]表示第i组中的第k个物品的weight
			int[] W 表示主件的weight
			数组m中m[i]记录第i组中的物品数;
			int c   背包容量capability
			int n   表示多少组
Return:     返回该问题的最优值
Others:		例题http://blog.csdn.net/keeping111/article/details/50803339
			kdp是假设选了i主件的最优解，dp[j] = max(dp[j], kdp[j - W[i]]) 相当于0/1背包问题
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  有依赖的背包问题
int Knapsack7(vector<vector<int> > v, vector<vector<int> > w, vector<int> W, vector<int> m, int c, int n)
{
	vector<int> dp(c + 1, 0);
	vector<int> kdp(c + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		kdp = dp;
		for (int k = 0; k < m[i]; ++k)
			for (int j = c - W[i]; j >= w[i][k]; --j)
				kdp[j] = max(kdp[j], kdp[j - w[i][k]] + v[i][k]);
		for (int j = W[i]; j <= c; ++j)
			dp[j] = max(dp[j], kdp[j - W[i]]);
	}
	return dp[c];
}