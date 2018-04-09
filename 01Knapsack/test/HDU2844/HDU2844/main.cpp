/********************
题目：HDU 2844 Coins
Function:   多重背包问题 需要转化为01背包问题并进行二进制优化
			每种钱币的数量有约束，用这些钱币组合出在1到m之间的数有多少种
Inputs:		int[] v  各种物品的价值value
			int[] w  各种钱币的数量
			int   m  容量
			int   n  物品的种数即v,w的数组大小
Return:     返回该问题的最优值
*********************/

#include<iostream>
#include<vector>
using namespace std;
int v[101];
int w[101];
bool dp[100001];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		for (int i = 0;i < n; ++i)
			cin >> v[i];
		for (int i = 0;i < n; ++i)
			cin >> w[i];
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for (int i = 0;i < n;++i)
		{
			if (v[i] * w[i] >= m)	// 完全背包问题
			{
				for (int j = v[i];j <= m;++j)
					dp[j] = dp[j] || dp[j - v[i]];
			}
			else					// 多重背包问题转化为01背包问题加入二进制思想
			{
				for (int k = 1;k <= w[i];k=k*2)
				{
					for (int j = m; j >= k*v[i];--j)
						dp[j] = dp[j] || dp[j - k*v[i]];
					w[i] -= k;
				}
				if (w[i] > 0)
				{
					for (int j = m;j >= w[i] * v[i];--j)
						dp[j] = dp[j] || dp[j - w[i] * v[i]];
				}
			}
		}
		int res = 0;
		for (int j = 1;j <= m; ++j)
			if (dp[j] == true)
				++res;
		cout << res << endl;
	}
	return 0;
}
