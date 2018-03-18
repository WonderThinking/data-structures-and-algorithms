/********************
Function:   ������ֱ�������
			�е���Ʒֻ����һ��(0/1����),�е���Ʒ�������޴�(��ȫ����),�е���Ʒ����������(���ر���)		
Inputs:     int[] v  ������Ʒ�ļ�ֵvalue
			int[] w  ������Ʒ������weight
			int[] N  ������Ʒ������Լ��numbers
			int   c  ��������capability
			int   n  ��Ʒ��������v,w�������С
Return:     ���ظ����������ֵ
Others:		��ת��Ϊ���ر�������,0/1����-��Ʒ����Ϊ1; ��ȫ����--��Ʒ����Ϊ����c/v[i]����;���ر���--��Ʒ����ΪN[i]
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  ������ֱ�������
int Knapsack4(int* v, int* w, int* N, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		if (N[i] == 1)	// 0/1����
			for (int j = c; j >= w[i]; --j)  //�������㣨ע�⸲��˳��
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		else if (N[i] * w[i] >c)  // ��ȫ����
			for (int j = w[i]; j <= c; ++j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		else // ���ر���
			for (int j = c; j >= w[i]; --j)
				for (int k = 1; k <= N[i] && j - k*w[i] >= 0; ++k)
					dp[j] = max(dp[j], dp[j - k*w[i]] + k*v[i]);
	}
	return dp[c];
}