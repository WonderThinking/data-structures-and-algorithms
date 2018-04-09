#ifndef  BinarySearchTree_H
#define BinarySearchTree_H

#include<iostream>
#include"TreeNode.h"
using namespace std;

class BinarySearchTree
{
private:
	TreeNode *mRoot;		/* ����� */
public:
	BinarySearchTree();		/* ���캯�� */

	void insert(int key);	/* ���� */
	void remove(int key);	/* ɾ�� */

	bool contains(int key);	/* ���Ҽ�ֵkey */

	int findMin();			/* ������Сֵ */
	int findMax();			/* �������ֵ */

	void preOrder();		/* ǰ����� */
	void inOrder();			/* ������� */
	void postOrder();		/* ������� */

private:
	TreeNode* BinarySearchTree::removeNode(TreeNode* root, int value);

	TreeNode* BinarySearchTree::findMin(TreeNode *root);
	TreeNode* BinarySearchTree::findMax(TreeNode *root);

	void preOrder(TreeNode *root);
	void inOrder(TreeNode *root);
	void postOrder(TreeNode *root);
};

#endif // ! BinarySearchTree_H



