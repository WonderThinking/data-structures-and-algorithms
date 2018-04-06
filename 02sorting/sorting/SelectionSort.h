/*********************************************
 * ѡ������ Selection Sort
 * �㷨˼�룺ͨ��������������,����δ��������,�������������дӺ���ǰɨ��,�ҵ���Ӧλ�ò�����
 * �㷨������
 *		1������һ�齫��СԪ�����һ��Ԫ�ؽ���,������һ��Ԫ�ؾ�ȷ����
 *		2������δ�����Ԫ�ؽ���СԪ��ڶ���Ԫ�ؽ���,�ڶ���Ԫ��Ҳ��ȷ����
 *		3���Դ�����,����n-1��
 **********************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> selectionSort(vector<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i)
	{
		int minValue = arr[i];
		int minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < minValue)
			{
				minValue = arr[j];
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
	return arr;
}