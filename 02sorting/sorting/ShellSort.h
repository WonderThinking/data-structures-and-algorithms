/*********************************************
 * ϣ������ Shell Sort
 * �㷨˼�룺�Ǽ򵥲�������ĸĽ���,�����������Ĳ�֮ͬ������,�������ȱȽϾ����Զ��Ԫ��,ϣ�������ֽ���С��������
 * �㷨������
 *		1��ѡ��һ����������
 *		2�����������и���k
 *		3�������������з���������򣬹���k������
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> shellSort(vector<int> arr)
{
	int n = arr.size();
	int gap = 1;
	while (gap < n / 3)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = gap / 3)
	{
		for (int i = gap; i < n; ++i)
		{
			int tmp = arr[i];
			int j = i - gap;
			while (j >= 0 && arr[j] > tmp)
			{
				arr[j + gap] = arr[j];
				j = j - gap;
			}
			arr[j + gap] = tmp;
		}
	}
	return arr;
}