#include<iostream>
#include<vector>
#include"SequenceSearch.h"
#include"BinarySearch.h"
#include"InsertionSearch.h"
#include"FibonacciSearch.h"
using namespace std;

void main()
{
	//vector<int> arr = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	vector<int> arr = { 6 };
	int value = 6;
	cout << "Sequence Search " << sequenceSearch(arr, value) << endl;
	cout << "Binary Search " << binarySearch(arr, value) << endl;
	cout << "Insertion Search " << insertionSearch(arr, value) << endl;
	cout << "Fibonacci Search " << fibonacciSearch(arr, value) << endl;
	system("pause");
}