/********************
Function:   背包问题问法变化--求次优解、第K优解
Inputs:     int[] v  各个物品的价值value
	    int[] w  各个物品的重量weight
	    int   c  背包容量capability
	    int   n  物品的种数即v,w的数组大小
	    int   K  第K优解  
Return:     返回该问题的最优值
Others:	    实际上一个正确的状态转移方程在求解的过程中遍历了所有的可用策略，也就覆盖了问题的所有方案.
	    只不过由于是求最优解，把其他达不到最优策略的方案都给忽略了.
	    对于求次优解和第K优解的方法： 对于任两个状态的max运算等价于两个由大到小顺序排列的队列进行合并.例子HDU2639
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  背包问题求第K优解
int Knapsack9(int* v, int* w, int c, int n, int K)
{
	vector<vector<int> > dp(c + 1, vector<int>(K, 0));
	vector<int> a(K, 0);
	vector<int> b(K, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
		{
			for (int k = 0; k < K; ++k)
			{
				a[k] = dp[j][k];
				b[k] = dp[j - w[i]][k] + v[i];
			}
			int x = 0, y = 0, k = 0;
			while (k < K)
			{
				if (y == K || (x<K && a[x]>b[y]))
					dp[j][k] = a[x++];
				else
					dp[j][k] = b[y++];
				if (k == 0 || dp[j][k] == 0 || dp[j][k] != dp[j][k - 1])
					++k;
			}
		}
	return dp[c][K - 1];
}
