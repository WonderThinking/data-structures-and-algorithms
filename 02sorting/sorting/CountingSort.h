/*********************************************
 *   计数排序 Counting Sort
 *   算法思想：计数排序不是基于比较的排序算法,其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中
 *	 算法描述：
 *		1、找到最大和最小元素，开辟相应的计数数组
 *		2、统计元素出现的次数，累加到计数数组中
 *		3、反向填充目标数组：将每个元素放在新数组的中，每放一个元素就将计数数组减去1
 **********************************************/

#include<vector>
using namespace std;
vector<int> countingSort(vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	int n = arr.size();

	int minValue = arr[0];
	int maxValue = arr[0];
	for (int i = 0;i < n;++i)
	{
		if (arr[i] > maxValue)
			maxValue = arr[i];
		else if (arr[i] < minValue)
			minValue = arr[i];
	}
	int len = maxValue - minValue + 1;
	vector<int> bucket(len, 0);

	for (int i = 0;i < n;++i)
		bucket[arr[i] - minValue]++;

	int sortedIndex = 0;
	for (int i = 0;i < len;++i)
		while (bucket[i]>0)
		{
			arr[sortedIndex++] = i + minValue;
			bucket[i]--;
		}
	return arr;
}