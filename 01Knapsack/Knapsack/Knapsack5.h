/********************
Function:   ��ά���õı�������
			�ܵ�����������
Inputs:     int[] v   ������Ʒ�ļ�ֵvalue
			int[] w   ������Ʒ������weight
			int[] q   ÿ����Ʒ������
			int   cw  ����Ҫװ��Ʒ������Լ��
			int   cq  ����Ҫװ��Ʒ������Լ��
			int   n   ��Ʒ������
Return:     ���ظ����������ֵ
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  ��ά���õı�������
int Knapsack5(int* v, int* w, int* q, int cw, int cq, int n)
{
	vector<vector<int> > dp(cw + 1, vector<int>(cq + 1, 0));
	for (int i = 0; i < n; ++i)
		for (int j = cw; j >= w[i]; --j)
			for (int k = cq; k >= q[i]; --k)
				dp[j][k] = max(dp[j][k], dp[j - w[i]][k - q[i]] + v[i]);
	return dp[cw][cq];
}