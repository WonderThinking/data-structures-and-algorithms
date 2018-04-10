/* �ֿ����(�ֳ�����˳�����) Block Search 
 * �ص㣺�������򣬿�����򣻿���ʹ����ʽ�洢
 */
#include<iostream>
#include<vector>
using namespace std;

typedef struct
{
	int maxKey;		//�������ؼ���
	int firstLink;  //�����һ���ڵ��±�
}IndexTable;

int blockSearch(vector<int> arr, vector<IndexTable> IT, int key)
{
	/* ��������� */
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

	/* ���ڲ���(˳�����) */
	int j = IT[i].firstLink;
	while (j < arr.size() && arr[j] != key && arr[j] <= IT[i].maxKey)
		++j;

	/* ������ҽ�� */
	if (j == arr.size() || arr[j] != key)
	{
		cout << "Not Found" << endl;
		return -1;
	}
	return j;
}

