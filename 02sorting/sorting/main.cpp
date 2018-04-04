#include<iostream>
#include<vector>
#include"CountingSort.h"
using namespace std;

int main()
{
	vector<int> arr = { 2,3,8,7,1,2,2,2,7,3,9,2,1,4,2,4,6,9,2 };
	for (int i = 0;i < arr.size();++i)
		cout << arr[i] << ' ';
	cout << endl;
	vector<int> result = countingSort(arr);
	for (int i = 0;i < result.size();++i)
		cout << result[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}