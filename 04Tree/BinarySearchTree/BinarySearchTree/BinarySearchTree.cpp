#include<iostream>
#include"BinarySearchTree.h"
using namespace std;

/* ���캯�� */
BinarySearchTree::BinarySearchTree()
{
	mRoot = NULL;
}

/* ���� */
void BinarySearchTree::insert(int key)
{
	TreeNode *Node = new TreeNode(key);
	if (mRoot == NULL)
		mRoot = Node;
	else
	{
		TreeNode *childNode = mRoot;
		TreeNode *parentNode = NULL;
		while (childNode != NULL)
		{
			parentNode = childNode;
			if (key > childNode->val)
				childNode = childNode->right;
			else
				childNode = childNode->left;
		}
		if (key > parentNode->val)
			parentNode->right = Node;
		else
			parentNode->left = Node;
	}
}


/* ɾ�� */
void BinarySearchTree::remove(int key)
{
	mRoot = removeNode(mRoot, key);
}

TreeNode* BinarySearchTree::removeNode(TreeNode* root, int value)
{
	if (root == NULL)
		return NULL;
	if (root->val > value)
		root->left = removeNode(root->left, value);
	else if (root->val < value)
		root->right = removeNode(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
			root = (root->left != NULL) ? root->left : root->right;
		else
		{
			TreeNode *cur = root->right;
			while (cur->left != NULL)
				cur = cur->left;
			root->val = cur->val;
			root->right = removeNode(root->right, cur->val);
		}
	}
	return root;
}

/* ���Ҽ�ֵkey */
bool BinarySearchTree::contains(int key)
{
	TreeNode *tmpNode = mRoot;
	while (tmpNode != NULL)
	{
		if (key > tmpNode->val)
			tmpNode = tmpNode->right;
		else if (key < tmpNode->val)
			tmpNode = tmpNode->left;
		else
			return true;
	}
	return false;
}

/* ������Сֵ */
int BinarySearchTree::findMin()
{
	TreeNode *minNode = findMin(mRoot);
	if (minNode == NULL)
		return 0x80000000;			//int��С����
	return minNode->val;
}

TreeNode* BinarySearchTree::findMin(TreeNode *root)
{
	TreeNode *tmpNode = root;
	if (root == NULL)
		return NULL;			//int��С����
	while (tmpNode->left != NULL)
		tmpNode = tmpNode->left;
	return tmpNode;
}

/* �������ֵ */
int BinarySearchTree::findMax()
{
	TreeNode *maxNode = findMax(mRoot);
	if (mRoot == NULL)
		return 0x7fffffff;			// int�������
	return maxNode->val;
}

TreeNode* BinarySearchTree::findMax(TreeNode *root)
{
	TreeNode *tmpNode = root;
	if (root == NULL)
		return NULL;			//int��С����
	while (tmpNode->right != NULL)
		tmpNode = tmpNode->right;
	return tmpNode;
}

/* ǰ����� */
void BinarySearchTree::preOrder()
{
	cout << "preOrder:\t";
	preOrder(mRoot);
	cout << endl;
}

void BinarySearchTree::preOrder(TreeNode *root)
{
	if (root != NULL)
	{
		cout << root->val << ' ';
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* ������� */
void BinarySearchTree::inOrder()
{
	cout << "inOrder:\t";
	inOrder(mRoot);
	cout << endl;
}

void BinarySearchTree::inOrder(TreeNode *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->val << ' ';
		inOrder(root->right);
	}
}

/* ������� */
void BinarySearchTree::postOrder()
{
	cout << "postOrder:\t";
	postOrder(mRoot);
	cout << endl;
}

void BinarySearchTree::postOrder(TreeNode *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->val << ' ';
	}
}
