/*********************************************
 * �鲢���� Merge Sort
 * �㷨˼�룺���η�(Divide and Conquer),��ʹÿ������������,��ʹ�����жμ�����.�������������ϲ���һ�������,��Ϊ2-·�鲢
 * �㷨������
 *		1���ѳ���Ϊn���������зֳ���������Ϊn/2��������
 *		2���������������зֱ���ù鲢����
 *		3������������õ������кϲ���һ�����յ���������
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;
void mergeSort(vector<int> &arr, int left, int right);

vector<int> mergeSort(vector<int> arr)
{
	vector<int> res = arr;
	mergeSort(res, 0, res.size() - 1);
	return res;
}

void mergeSort(vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	vector<int> tmp;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			tmp.push_back(arr[i++]);
		else
			tmp.push_back(arr[j++]);
	}
	while (i <= mid)
		tmp.push_back(arr[i++]);
	while (j <= right)
		tmp.push_back(arr[j++]);
	for (int k = 0; k < tmp.size(); ++k)
		arr[left++] = tmp[k];
}