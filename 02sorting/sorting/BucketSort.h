/* Ͱ���� Bucket Sort
 * �㷨˼�룺Ͱ�����Ǽ��������������,�������˺�����ӳ���ϵ,��Ч���Ĺؼ����������ӳ�亯����ȷ��
 * �㷨������
 *		1������һ�����Ŀ�Ͱ
 *		2���������齫Ԫ��ӳ�䵽��ӦͰ��
 *		3����ÿ����Ͱ��������
 *		4��������������ƴ��
 * �㷨������
 *
 * ���ó�����
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

	/* Ͱ�ĳ�ʼ�� */
	int bucketCount = 5;	// Ͱ��Ĭ������
	vector<vector<int> > buckets(bucketCount);

	int bucketSize = (maxValue - minValue) / bucketCount + 1;
	for (int i = 0;i < n;++i)
		buckets[floor(arr[i] - minValue) / bucketSize].push_back(arr[i]);	// ӳ�亯��

	vector<int> res;
	for (int i = 0;i < bucketCount;++i)
	{
		sort(buckets[i].begin(), buckets[i].end());
		for (int j = 0;j < buckets[i].size();++j)
			res.push_back(buckets[i][j]);
	}
	return res;
}