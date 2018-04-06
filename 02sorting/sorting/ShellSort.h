/*********************************************
 * 希尔排序 Shell Sort
 * 算法思想：是简单插入排序的改进版,它与插入排序的不同之处在于,它会优先比较距离较远的元素,希尔排序又叫缩小增量排序
 * 算法描述：
 *		1、选择一个增量序列
 *		2、按增量序列个数k
 *		3、根据增量进行分组插入排序，共有k趟排序
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