#include<iostream>
#include<vector>
#include"SequenceSearch.h"
#include"BinarySearch.h"
#include"InsertionSearch.h"
#include"FibonacciSearch.h"
#include"BinarySearchTree.h"
using namespace std;

void main()
{
	vector<int> arr = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	//vector<int> arr = { 6 };
	int value = 6;
	cout << "Sequence Search   (���ڷ����±�,�����ڷ���0)  " << sequenceSearch(arr, value) << endl;
	cout << "Binary Search     (���ڷ����±�,�����ڷ���0)  " << binarySearch(arr, value) << endl;
	cout << "Insertion Search  (���ڷ����±�,�����ڷ���0)  " << insertionSearch(arr, value) << endl;
	cout << "Fibonacci Search  (���ڷ����±�,�����ڷ���0)  " << fibonacciSearch(arr, value) << endl;
	cout << "Binary Search Tree(���ڷ���1,�����ڷ���0)     " << binarySearchTree(arr, value) << endl;
	system("pause");
}