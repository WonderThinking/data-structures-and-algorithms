/* ð������ Bubble Sort
 * �㷨˼�룺һ�αȽ�����Ԫ��,�����³���С����ð
 * �㷨������
 *		1���Ƚ����ڵ�Ԫ��; �����һ���ȵڶ����󣬾ͽ�����������
 *		2����һ�˽����������������
 *		3���ڶ��˽��ڶ�������ź�
 *		4���Դ�����
 * �㷨������
 *		
 * ���ó�����
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