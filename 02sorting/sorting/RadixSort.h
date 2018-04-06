/*********************************************
 * �������� Radix Sort
 * �㷨˼�룺���յ�λ������,Ȼ���ռ�;�ٰ��ո�λ����,Ȼ�����ռ�;��������,ֱ�����λ LSD
 * �㷨������
 *		1��ȡ�������е����������ȡ��λ����
 *		2��arrΪԭʼ���飬�����λ��ʼȡÿ��λ�����ӦͰ�У����ռ�
 *		3���Դ����ƣ�ֱ�����е�λ���������ռ����
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;

//����ֻ���������з��� 
vector<int> radixSort(vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	int n = arr.size();
	
	// �������Ԫ�ص�λ��
	int maxValue = arr[0];
	for (int i = 0;i < n;++i)
		if (arr[i] > maxValue)
			maxValue = arr[i];
	int maxDigit = 1;
	int den = 10;
	while (maxValue / den != 0)
	{
		++maxDigit;
		den = den * 10;
	}

	vector<int> res = arr;
	vector<vector<int> > buckets(10); //����ʮ��Ͱ
	den = 1;
	for (int k = 1;k <= maxDigit;++k)
	{
		// ����
		for (int i = 0;i < n;++i)
			buckets[(res[i] / den) % 10].push_back(res[i]);
		den = den * 10;
		// �ռ�
		int pos = 0;
		for (int i = 0;i <= 9;++i)
		{
			if (!buckets[i].empty())
				for (int j = 0;j < buckets[i].size();++j)
					res[pos++] = buckets[i][j];
			buckets[i].clear();
		}
	}
	return res;
}
