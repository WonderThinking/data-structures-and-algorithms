/********************
��Ŀ��HDU 2844 Coins
Function:   ���ر������� ��Ҫת��Ϊ01�������Ⲣ���ж������Ż�
			ÿ��Ǯ�ҵ�������Լ��������ЩǮ����ϳ���1��m֮������ж�����
Inputs:		int[] v  ������Ʒ�ļ�ֵvalue
			int[] w  ����Ǯ�ҵ�����
			int   m  ����
			int   n  ��Ʒ��������v,w�������С
Return:     ���ظ����������ֵ
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
			if (v[i] * w[i] >= m)	// ��ȫ��������
			{
				for (int j = v[i];j <= m;++j)
					dp[j] = dp[j] || dp[j - v[i]];
			}
			else					// ���ر�������ת��Ϊ01����������������˼��
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
