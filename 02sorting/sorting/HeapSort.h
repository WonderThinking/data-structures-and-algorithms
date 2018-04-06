/*********************************************
 * ������ Heap Sort
 * �㷨˼�룺��������,ÿ�ζ�ȡ�Ѷ���Ԫ��,����������������,Ȼ��ʣ���Ԫ�����µ���Ϊ����,��������,���յõ����������
 *           ��ʵ�����������������ʵ���ȫ������:������һ��Ҷ�ӽ��Ĺؼ��־�������(��С��)�����Һ���(������)���Ĺؼ���
 *           �ѷ�Ϊ���Ѻ���С��:����Ҫ��ڵ��Ԫ�ض�Ҫ��С���亢��,��С��Ҫ��ڵ�Ԫ�ض������������Һ���,
 * �㷨������
 *		1����ԭʼ����(R0,R1��.Rn-1)��������
 *		2�����Ѷ�Ԫ��R[0]�����һ��Ԫ��R[n-1]��������ʱ�õ��µ�������(R0,R1,����Rn-2)���µ�������(Rn-1),������R[1,2��n-1]<=R[n]��
 *		3����������(R0,R1,����Rn-2)����Ϊ���ѣ�Ȼ�󽫶Ѷ�Ԫ��R[0]�����������һ��Ԫ��R[n-2]����
 *		4���Դ����ƣ�ֱ��ȫ������Ϊ������
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


