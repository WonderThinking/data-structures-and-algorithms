/********************
Function:   ���鱳������
			��Ʒ��Ϊ�����飬ÿ�����ѡһ����Ʒ����������������������ֵ
Inputs:     ��ά������v[i][k]��ʾ��i���еĵ�k����Ʒ��value
			��ά������w[i][k]��ʾ��i���еĵ�k����Ʒ��weight
			����m��m[i]��¼��i���е���Ʒ��;
			int c  ��������capability
			int g  ��ʾ������group
Return:     ���ظ����������ֵ
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  ���鱳������
int Knapsack6(vector<vector<int> > v, vector<vector<int> > w, vector<int> m, int c, int g)
{
	vector<int> dp(c + 1, 0);
	for (int i = 0; i < g; ++i)
		for (int j = c; j > 0; --j)
			for (int k = 0; k < m[i]; ++k)
				if (j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
	return dp[c];
}