#include<iostream>
#include<vector>
#include"SequenceSearch.h"
#include"BinarySearch.h"
#include"InsertionSearch.h"
#include"FibonacciSearch.h"
#include"BinarySearchTree.h"
#include"BlockSearch.h"
#include"HashSearch.h"
using namespace std;

void main()
{
	vector<int> arr = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
	//vector<int> arr = { 6 };
	int value = 6;
	cout << "Sequence Search   (存在返回下标,不存在返回0)  " << sequenceSearch(arr, value) << endl;
	cout << "Binary Search     (存在返回下标,不存在返回0)  " << binarySearch(arr, value) << endl;
	cout << "Insertion Search  (存在返回下标,不存在返回0)  " << insertionSearch(arr, value) << endl;
	cout << "Fibonacci Search  (存在返回下标,不存在返回0)  " << fibonacciSearch(arr, value) << endl;
	cout << "Binary Search Tree(存在返回1,不存在返回0)     " << binarySearchTree(arr, value) << endl;
	HashTable HT(arr.size());
	for (int i = 0;i < arr.size();++i)
		HT.insert(arr[i]); 
	cout << "Hash Table	(存在返回1,不存在返回0)     " << HT.contains(value) << endl;

	//分块查找需根据实际情况进行分块，这里没有测试分块查找的测试用例
	system("pause");
}