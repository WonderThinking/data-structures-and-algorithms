/* 分块查找(又称索引顺序查找) Block Search 
 * 特点：块内无序，块间有序；可以使用链式存储
 */
#include<iostream>
#include<vector>
using namespace std;

typedef struct
{
	int maxKey;		//本块最大关键字
	int firstLink;  //本块第一个节点下标
}IndexTable;

int blockSearch(vector<int> arr, vector<IndexTable> IT, int key)
{
	/* 索引表查找 */
	int left = 0;
	int right = IT.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (key == IT[mid].maxKey)
			break;
		else if (key > IT[mid].maxKey)
			left = mid + 1;
		else
			right = mid;
	}
	int i = left;
	if (i == IT.size())
	{
		cout << "Not Found" << endl;
		return -1;
	}

	/* 块内查找(顺序查找) */
	int j = IT[i].firstLink;
	while (j < arr.size() && arr[j] != key && arr[j] <= IT[i].maxKey)
		++j;

	/* 输出查找结果 */
	if (j == arr.size() || arr[j] != key)
	{
		cout << "Not Found" << endl;
		return -1;
	}
	return j;
}

