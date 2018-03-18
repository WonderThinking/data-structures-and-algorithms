/********************
Function:   ���ر�������
			ÿ����Ʒ��������Լ�����󲻳�����������������ֵ
Inputs:     int[] v  ������Ʒ�ļ�ֵvalue
			int[] w  ������Ʒ������weight
			int   c  ��������capability
			int   n  ��Ʒ��������v,w�������С
Return:     ���ظ����������ֵ
*********************/
#include<vector>
#include<algorithm>
using namespace std;

// ���ر�������
int Knapsack3(int* v, int* w, int* N, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			for (int k = 1; k <= N[i] && j - k*w[i] >= 0; ++k)
				dp[j] = max(dp[j], dp[j - k*w[i]] + k*v[i]);
	return dp[c];
}