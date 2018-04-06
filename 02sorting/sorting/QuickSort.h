/*********************************************
 * 快速排序 Quick Sort
 * 算法思想：通过一趟排序将要排序的数据分割成独立的两部分,其中一部分的所有数据都比另外一部分的所有数据都要小
 *           然后再按此方法对这两部分数据分别进行快速排序,整个排序过程可以递归进行,以此达到整个数据变成有序序列
 * 算法描述：
 *		1、从数列中挑出一个元素,称为"基准"（pivot）
 *		2、重新排序数列,所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面
 *		3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序
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