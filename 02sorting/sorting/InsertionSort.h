/*********************************************
 * 插入排序 Insertion Sort
 * 算法思想：通过构建有序序列,对于未排序数据,在已排序序列中从后向前扫描,找到相应位置并插入
 * 算法描述：
 *		1、从第一个元素开始,该元素可以认为已经被排序；
 *		2、取出下一个元素，在已排序的元素序列中从后向前扫描,如果该元素大于新元素,将该元素移到下一位置，
 *		3、直到找到已排序的元素小于或者等于新元素的位置,将新元素插入到该位置后；
 *		4、总共插入n-1次
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> insertionSort(vector<int> arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i)
	{
		int tmp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
	return arr;
}