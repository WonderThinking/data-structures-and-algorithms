/* 桶排序 Bucket Sort
 * 算法思想：桶排序是计数排序的升级版,它利用了函数的映射关系,高效与否的关键就在于这个映射函数的确定
 * 算法描述：
 *		1、设置一定量的空桶
 *		2、遍历数组将元素映射到对应桶中
 *		3、对每个空桶进行排序
 *		4、将排序后的数据拼接
 * 算法分析：
 *
 * 适用场景：
 *  
 */

#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> bucketSort(vector<int> arr)
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

	/* 桶的初始化 */
	int bucketCount = 5;	// 桶的默认数量
	vector<vector<int> > buckets(bucketCount);

	int bucketSize = (maxValue - minValue) / bucketCount + 1;
	for (int i = 0;i < n;++i)
		buckets[floor(arr[i] - minValue) / bucketSize].push_back(arr[i]);	// 映射函数

	vector<int> res;
	for (int i = 0;i < bucketCount;++i)
	{
		sort(buckets[i].begin(), buckets[i].end());
		for (int j = 0;j < buckets[i].size();++j)
			res.push_back(buckets[i][j]);
	}
	return res;
}