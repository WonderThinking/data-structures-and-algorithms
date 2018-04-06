/*********************************************
 *   �������� Counting Sort
 *   �㷨˼�룺���������ǻ��ڱȽϵ������㷨,��������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ���
 *	 �㷨������
 *		1���ҵ�������СԪ�أ�������Ӧ�ļ�������
 *		2��ͳ��Ԫ�س��ֵĴ������ۼӵ�����������
 *		3���������Ŀ�����飺��ÿ��Ԫ�ط�����������У�ÿ��һ��Ԫ�ؾͽ����������ȥ1
 **********************************************/

#include<vector>
using namespace std;
vector<int> countingSort(vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	int n = arr.size();

	int minValue = arr[0];
	int maxValue = arr[0];
	for (int i = 0;i < n;++i)
	{
		if (arr[i] > maxValue)
			maxValue = arr[i];
		else if (arr[i] < minValue)
			minValue = arr[i];
	}
	int len = maxValue - minValue + 1;
	vector<int> bucket(len, 0);

	for (int i = 0;i < n;++i)
		bucket[arr[i] - minValue]++;

	int sortedIndex = 0;
	for (int i = 0;i < len;++i)
		while (bucket[i]>0)
		{
			arr[sortedIndex++] = i + minValue;
			bucket[i]--;
		}
	return arr;
}