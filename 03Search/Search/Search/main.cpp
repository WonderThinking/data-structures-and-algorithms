#include<iostream>
#include<vector>
#include"SequenceSearch.h"
using namespace std;

void main()
{
	vector<int> arr = { 1,5,21,6,43 };
	int value = 6;
	cout << "Sequence Search " << sequenceSearch(arr, value) << endl;
	system("pause");
}