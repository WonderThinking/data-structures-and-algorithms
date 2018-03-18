/********************
Function:   0/1��������
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

//  0/1��������(��������������)
int Knapsack1_1(int* v, int* w, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c];
}

//  0/1��������(��������������),�������ֵ����ӡ������ļ�ֵ�ı���(���Ž�)
int Knapsack1_2(int* v, int* w, int c, int n)
{
	vector<vector<int> > dp(n, vector<int>(c + 1, 0));
	for (int j = w[0]; j <= c; ++j)
		dp[0][j] = v[0];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= c; ++j)
		{
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	// ��ӡ������Ž����Ʒ��
	int value = dp[n - 1][c];
	int i = n - 1;
	int j = c;
	while (value > 0)
	{
		if (i <= 0 || dp[i - 1][j] != value)
		{
			printf("%d ", i);
			value = value - v[i];
			j = c - w[i];
		}
		--i;
	}
	return dp[n - 1][c];
}

// 0/1��������(ǡ��װ������)
int Knapsack1_3(int* v, int* w, int c, int n)
{
	int MIN = 0x80000000; //��С������ǷǷ�״̬,���������в��ܳ��ִﵽ���߳���INF�����,��MINӦ�㹻С
	vector<int> dp(c + 1, MIN);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = c; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[c] >= 0 ? dp[c] : 0;
}