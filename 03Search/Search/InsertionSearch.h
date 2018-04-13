/* 插值查找 Insertion Search */

#include<iostream>
#include<vector>
using namespace std;

int insertionSearch(vector<int> arr, int value)
{
	int left = 0;
	int right = arr.size() - 1;
	int mid;
	while (left <= right)
	{
		if (arr[right] - arr[left] != 0)
			mid = left + (value - arr[left]) / (arr[right] - arr[left])*(right - left);
		else
			return arr[left] == value ? left : -1;
		if (arr[mid] == value)
			return mid;
		if (arr[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
