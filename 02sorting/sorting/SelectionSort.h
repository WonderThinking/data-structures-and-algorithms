/* 选择排序 Selection Sort
 * 算法思想：
 * 算法描述：
 *		1、遍历一遍将最小元素与第一个元素交换，这样第一个元素就确定了
 *		2、遍历未排序的元素将最小元与第二个元素交换，第二个元素也就确定了
 *		3、以此类推，共有n-1趟
 * 算法分析：
 *		
 * 适用场景：
 */	

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