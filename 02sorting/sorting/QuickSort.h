/*********************************************
 * �������� Quick Sort
 * �㷨˼�룺ͨ��һ������Ҫ��������ݷָ�ɶ�����������,����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС
 *           Ȼ���ٰ��˷����������������ݷֱ���п�������,����������̿��Եݹ����,�Դ˴ﵽ�������ݱ����������
 * �㷨������
 *		1��������������һ��Ԫ��,��Ϊ"��׼"��pivot��
 *		2��������������,����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ���
 *		3���ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<int> &arr, int left, int right);

vector<int> quickSort(vector<int> arr)
{
	vector<int> res = arr;
	quickSort(res, 0, res.size() - 1);
	return res;
}

void quickSort(vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;
	int pivot = arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (j>i && arr[j] >= pivot)
			--j;
		if (i < j)
			arr[i++] = arr[j];
		while (i < j && arr[i] < pivot)
			++i;
		if (i < j)
			arr[j--] = arr[i];
	}
	arr[j] = pivot;
	quickSort(arr, left, j - 1);
	quickSort(arr, j + 1, right);
	return;
}