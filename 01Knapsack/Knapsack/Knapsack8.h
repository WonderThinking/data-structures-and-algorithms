/********************
Function:   ������Ʒ�ı�������
Inputs:     int[] v   ������Ʒ�ļ�ֵvalue
			int[] w   ������Ʒ������weight
			����m��m[i]��¼��i���е���Ʒ��
			int   c  ��������capability
			int   n  ��Ʒ������
Return:     ���ظ����������ֵ
Others:		������Ʒ�ı������Ȿ��������鱳������ ����
			������Ʒ w = h(v)�� ������Ҫ��������c��Լ���ȼ����v��w
			����һhttp://blog.csdn.net/qq_39670434/article/details/79483102
			�����http://www.hihocoder.com/discuss/question/2640
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  ������Ʒ�ı�������
int Knapsack8(vector<vector<int> > v, vector<vector<int> > w, vector<int> m, int c, int n)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < n; ++i)
		for (int j = c; j > 0; --j)
			for (int k = 0; k < m[i]; ++k)
				if (j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
	return dp[c];
}