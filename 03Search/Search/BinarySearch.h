/* 二分查找 Binary Search */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> arr, int value)
{
	int left = 0;
	int right = arr.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (arr[mid] == value)
			return mid;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
