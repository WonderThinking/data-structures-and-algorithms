/********************
Function:   �������ı�������
			����û��ĳ����Ʒ�������ڱ����Ʒ,�ֱ������Ʒ������
			Ҳû��ĳ����Ʒͬʱ���������Ʒ ������-������
Inputs:     ��ά������v[i][k]��ʾ��i���еĵ�k����Ʒ��value
			��ά������w[i][k]��ʾ��i���еĵ�k����Ʒ��weight
			int[] W ��ʾ������weight
			����m��m[i]��¼��i���е���Ʒ��;
			int c   ��������capability
			int n   ��ʾ������
Return:     ���ظ����������ֵ
Others:		����http://blog.csdn.net/keeping111/article/details/50803339
			kdp�Ǽ���ѡ��i���������Ž⣬dp[j] = max(dp[j], kdp[j - W[i]]) �൱��0/1��������
*********************/
#include<vector>
#include<algorithm>
using namespace std;

//  �������ı�������
int Knapsack7(vector<vector<int> > v, vector<vector<int> > w, vector<int> W, vector<int> m, int c, int n)
{
	vector<int> dp(c + 1, 0);
	vector<int> kdp(c + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		kdp = dp;
		for (int k = 0; k < m[i]; ++k)
			for (int j = c - W[i]; j >= w[i][k]; --j)
				kdp[j] = max(kdp[j], kdp[j - w[i][k]] + v[i][k]);
		for (int j = W[i]; j <= c; ++j)
			dp[j] = max(dp[j], kdp[j - W[i]]);
	}
	return dp[c];
}