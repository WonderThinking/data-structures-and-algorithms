/* 二叉查找树的C++实现 Binary Search Tree */

#include<iostream>
#include<vector>
#include"TreeNode.h"
#include"BinarySearchTree.h"
using namespace std;

int main()
{
	vector<int> arr = { 0,6,2,3,4,5,9,8,7,1 ,-1,-2 };

	BinarySearchTree bstree;
	for (int i = 0; i < arr.size(); ++i)
		bstree.insert(arr[i]);
	bstree.preOrder();
	bstree.inOrder();
	bstree.postOrder();

	cout << "是否含有9： " << bstree.contains(9) << endl;
	cout << "是否含有20： " << bstree.contains(20) << endl;

	cout << "最小值:\t" << bstree.findMin() << endl;
	cout << "最大值:\t" << bstree.findMax() << endl;

	bstree.remove(0);
	cout << "删除元素0 ";
	bstree.inOrder();

	bstree.remove(6);
	cout << "删除元素6 ";
	bstree.inOrder();
	system("pause");
	return 0;
}