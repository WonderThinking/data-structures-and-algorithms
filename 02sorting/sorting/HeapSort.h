/*********************************************
 * 堆排序 Heap Sort
 * 算法思想：构建最大堆,每次都取堆顶的元素,将其放在序列最后面,然后将剩余的元素重新调整为最大堆,依次类推,最终得到排序的序列
 *           堆实质上是满足如下性质的完全二叉树:树中任一非叶子结点的关键字均不大于(或不小于)其左右孩子(若存在)结点的关键字
 *           堆分为最大堆和最小堆:最大堆要求节点的元素都要不小于其孩子,最小堆要求节点元素都不大于其左右孩子,
 * 算法描述：
 *		1、将原始数组(R0,R1….Rn-1)构造最大堆
 *		2、将堆顶元素R[0]与最后一个元素R[n-1]交换，此时得到新的无序区(R0,R1,……Rn-2)和新的有序区(Rn-1),且满足R[1,2…n-1]<=R[n]，
 *		3、将无序区(R0,R1,……Rn-2)调整为最大堆，然后将堆顶元素R[0]与无序区最后一个元素R[n-2]交换
 *		4、以此类推，直至全部调整为有序区
 **********************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void buildMaxHeap(vector<int> &res, int i);
int len;

vector<int> heapSort(vector<int> arr)
{
	len = arr.size();
	vector<int> res = arr;
	for (int i = len / 2 - 1; i >= 0; --i)
		buildMaxHeap(res, i);
	for (int i = res.size() - 1; i > 0; --i)
	{
		swap(res[0], res[i]);
		len--;
		buildMaxHeap(res, 0);
	}
	return res;
}

void buildMaxHeap(vector<int> &res, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left<len && res[left] > res[largest])
		largest = left;
	if (right<len && res[right] > res[largest])
		largest = right;
	if (largest != i)
	{
		swap(res[i], res[largest]);
		buildMaxHeap(res, largest);
	}
}


