/* �����������C++ʵ�� Binary Search Tree */

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

	cout << "�Ƿ���9�� " << bstree.contains(9) << endl;
	cout << "�Ƿ���20�� " << bstree.contains(20) << endl;

	cout << "��Сֵ:\t" << bstree.findMin() << endl;
	cout << "���ֵ:\t" << bstree.findMax() << endl;

	bstree.remove(0);
	cout << "ɾ��Ԫ��0 ";
	bstree.inOrder();

	bstree.remove(6);
	cout << "ɾ��Ԫ��6 ";
	bstree.inOrder();
	system("pause");
	return 0;
}