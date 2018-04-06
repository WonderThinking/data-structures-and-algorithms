/*********************************************
 * 基数排序 Radix Sort
 * 算法思想：按照低位先排序,然后收集;再按照高位排序,然后再收集;依次类推,直到最高位 LSD
 * 算法描述：
 *		1、取得数组中的最大数，并取得位数；
 *		2、arr为原始数组，从最低位开始取每个位加入对应桶中，再收集
 *		3、以此类推，直到所有的位数都分配收集完成
 **********************************************/

#include<iostream>
#include<vector>
using namespace std;

//这里只对正数进行分析 
vector<int> radixSort(vector<int> arr)
{
	if (arr.size() <= 1)
		return arr;
	int n = arr.size();
	
	// 计算最大元素的位数
	int maxValue = arr[0];
	for (int i = 0;i < n;++i)
		if (arr[i] > maxValue)
			maxValue = arr[i];
	int maxDigit = 1;
	int den = 10;
	while (maxValue / den != 0)
	{
		++maxDigit;
		den = den * 10;
	}

	vector<int> res = arr;
	vector<vector<int> > buckets(10); //定义十个桶
	den = 1;
	for (int k = 1;k <= maxDigit;++k)
	{
		// 分配
		for (int i = 0;i < n;++i)
			buckets[(res[i] / den) % 10].push_back(res[i]);
		den = den * 10;
		// 收集
		int pos = 0;
		for (int i = 0;i <= 9;++i)
		{
			if (!buckets[i].empty())
				for (int j = 0;j < buckets[i].size();++j)
					res[pos++] = buckets[i][j];
			buckets[i].clear();
		}
	}
	return res;
}
