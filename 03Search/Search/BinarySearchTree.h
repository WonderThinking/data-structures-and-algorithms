/* ������������� Binary Search Tree */

#include<iostream>
#include<vector>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{}
};

class BinarySearchTree
{
private:
	TreeNode *mRoot;		/* ����� */
public:
	BinarySearchTree()		/* ���캯�� */
	{
		mRoot = NULL;
	}

	void insert(int key)	/* ���� */
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

	bool BinarySearchTree::contains(int key) 	/* ���Ҽ�ֵkey */
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
};


bool binarySearchTree(vector<int> arr, int value)
{
	BinarySearchTree BST;
	for (int i = 0; i < arr.size(); ++i)
		BST.insert(arr[i]);
	return BST.contains(value) == false ? -1 : 1;
}