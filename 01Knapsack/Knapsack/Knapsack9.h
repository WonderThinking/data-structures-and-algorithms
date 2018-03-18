/********************
Function:   ���������ʷ��仯--����Ž⡢��K�Ž�
Inputs:     int[] v  ������Ʒ�ļ�ֵvalue
			int[] w  ������Ʒ������weight
			int   c  ��������capability
			int   n  ��Ʒ��������v,w�������С
			int   K  ��K�Ž�  
Return:     ���ظ����������ֵ
Others:		ʵ����һ����ȷ��״̬ת�Ʒ��������Ĺ����б��������еĿ��ò��ԣ�Ҳ�͸�������������з���.
			ֻ���������������Ž⣬�������ﲻ�����Ų��Եķ�������������.
			��������Ž�͵�K�Ž�ķ����� ����������״̬��max����ȼ��������ɴ�С˳�����еĶ��н��кϲ�.����HDU2639
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  �����������K�Ž�
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