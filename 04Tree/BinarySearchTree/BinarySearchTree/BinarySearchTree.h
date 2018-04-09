#ifndef  BinarySearchTree_H
#define BinarySearchTree_H

#include<iostream>
#include"TreeNode.h"
using namespace std;

class BinarySearchTree
{
private:
	TreeNode *mRoot;		/* 根结点 */
public:
	BinarySearchTree();		/* 构造函数 */

	void insert(int key);	/* 插入 */
	void remove(int key);	/* 删除 */

	bool contains(int key);	/* 查找键值key */

	int findMin();			/* 查找最小值 */
	int findMax();			/* 查找最大值 */

	void preOrder();		/* 前序遍历 */
	void inOrder();			/* 中序遍历 */
	void postOrder();		/* 后序遍历 */

private:
	TreeNode* BinarySearchTree::removeNode(TreeNode* root, int value);

	TreeNode* BinarySearchTree::findMin(TreeNode *root);
	TreeNode* BinarySearchTree::findMax(TreeNode *root);

	void preOrder(TreeNode *root);
	void inOrder(TreeNode *root);
	void postOrder(TreeNode *root);
};

#endif // ! BinarySearchTree_H



