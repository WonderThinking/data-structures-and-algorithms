/* 쳲��������� Fibonacci Search */

#include<iostream>
#include<vector>
using namespace std;

int fibonacciSearch(vector<int> arr, int value)
{
	int n = arr.size();
	vector<int> F = {0,1};				// ����쳲���������
	int k;
	for (k = 1;F[k] - 1 < n;++k)
		F.push_back(F[k] + F[k - 1]);
	--k;
	vector<int> tmp = arr;
	for (int i = n; i < F[k];++i)		// ��������չ��F[k]-1�ĳ���
		tmp.push_back(arr[n - 1]);
	
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + F[k - 1] - 1;
		if (value < tmp[mid])
		{
			right = mid - 1;
			k -= 1;
		}
		else if (value > tmp[mid])
		{
			left = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid < n)
				return mid;		// �������˵��mid��Ϊ���ҵ���λ��
			else
				return n - 1;	// ��mid>=n��˵������չ����ֵ,����n-1
		}
	}
	return -1;
}