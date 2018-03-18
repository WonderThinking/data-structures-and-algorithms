/********************
Function:   二维费用的背包问题
	    受到背包容量及
Inputs:     int[] v   各个物品的价值value
	    int[] w   各个物品的重量weight
	    int[] q   每种物品的数量
	    int   cw  背包要装物品的重量约束
	    int   cq  背包要装物品的数量约束
	    int   n   物品的种数
Return:     返回该问题的最优值
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  二维费用的背包问题
int Knapsack5(int* v, int* w, int* q, int cw, int cq, int n)
{
	vector<vector<int> > dp(cw + 1, vector<int>(cq + 1, 0));
	for (int i = 0; i < n; ++i)
		for (int j = cw; j >= w[i]; --j)
			for (int k = cq; k >= q[i]; --k)
				dp[j][k] = max(dp[j][k], dp[j - w[i]][k - q[i]] + v[i]);
	return dp[cw][cq];
}
