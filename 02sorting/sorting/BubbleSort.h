/* 冒泡排序 Bubble Sort
 * 算法思想：一次比较两个元素,大数下沉，小数上冒
 * 算法描述：
 *		1、比较相邻的元素; 如果第一个比第二个大，就交换它们两个
 *		2、第一趟将最大的数放在了最后
 *		3、第二趟将第二大的数放好
 *		4、以此类推
 * 算法分析：
 *		
 * 适用场景：
 */	

#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n - i - 1; ++j) 
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = tmp;
			}
		}
	}
	return arr;
}