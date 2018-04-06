/*********************************************
 * 归并排序 Merge Sort
 * 算法思想：分治法(Divide and Conquer),先使每个子序列有序,再使子序列段间有序.若将两个有序表合并成一个有序表,称为2-路归并
 * 算法描述：
 *		1、把长度为n的输入序列分成两个长度为n/2的子序列
 *		2、对这两个子序列分别采用归并排序
 *		3、将两个排序好的子序列合并成一个最终的有序序列
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