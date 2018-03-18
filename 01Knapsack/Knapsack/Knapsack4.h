/********************
Function:   混合三种背包问题
	    有的物品只能用一次(0/1背包),有的物品能用无限次(完全背包),有的物品数量有上限(多重背包)		
Inputs:     int[] v  各个物品的价值value
	    int[] w  各个物品的重量weight
	    int[] N  各个物品的数量约束numbers
	    int   c  背包容量capability
	    int   n  物品的种数即v,w的数组大小
Return:     返回该问题的最优值
Others:	    可转化为多重背包问题,0/1背包-物品数量为1; 完全背包--物品数量为大于c/v[i]的数;多重背包--物品数量为N[i]
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  混合三种背包问题
int Knapsack4(int* v, int* w, int* N, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		if (N[i] == 1)	// 0/1背包
			for (int j = c; j >= w[i]; --j)  //逆序运算（注意覆盖顺序）
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		else if (N[i] * w[i] >c)  // 完全背包
			for (int j = w[i]; j <= c; ++j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		else // 多重背包
			for (int j = c; j >= w[i]; --j)
				for (int k = 1; k <= N[i] && j - k*w[i] >= 0; ++k)
					dp[j] = max(dp[j], dp[j - k*w[i]] + k*v[i]);
	}
	return dp[c];
}
