/********************
Function:   ��ȫ�������� 
			ÿ����Ʒ��������ʹ�ã��󲻳�����������������ֵ
Inputs:     int[] v  ������Ʒ�ļ�ֵvalue
			int[] w  ������Ʒ������weight
			int   c  ��������capability
			int   n  ��Ʒ��������v,w�������С
Return:     ���ظ����������ֵ
Others:     ���������ֵ���ÿռ�ѹ������������Ž�����ѹ���ռ�
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  ��ȫ������������ֵ
int Knapsack2_1(int* v, int* w, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = w[i]; j <= c; ++j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c];
}

//  ��ȫ�������������ֵ���䷽��
int Knapsack2_2(int* v, int* w, int c, int n)
{
	vector<vector<int> > dp(n, vector<int>(c + 1, 0));
	int k = 1;
	for (int j = w[0]; j <= c; ++j)
		dp[0][j] = dp[0][j - w[0]] + v[0];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= c; ++j)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	int value = dp[n - 1][c];
	int j = c;
	int i = n - 1;
	while (value > 0)
	{
		if (i <= 0 || dp[i - 1][j] != value)
		{
			printf("%d ", i);
			value = value - v[i];
			j = j - w[i];
		}
		else
			--i;
	}
	return dp[n - 1][c];
}