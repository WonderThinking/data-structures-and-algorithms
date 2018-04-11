/* 平衡二叉树的C++实现 AVL Tree
 * 特点：平衡二叉树要求对于每一个节点来说，它的左右子树的高度之差不能超过1，这个方案很好的解决了二叉查找树退化成链表的问题
 * 时间复杂度：插入,查找,删除的时间复杂度最好情况和最坏情况都维持在O(logN)。但是频繁旋转会使插入和删除牺牲掉O(logN)左右的时间
 */

#include<iostream>
#include"AvlNode.h"
#include"AVLTree.h"
using namespace std;

int main()
{
	AVLTree tree;
	for (int i = 1; i < 9; ++i)
		tree.insert(i);
	tree.inOrder();
	cout << endl;
	tree.remove(4);
	tree.inOrder();
	system("pause");
	return 0;
}
