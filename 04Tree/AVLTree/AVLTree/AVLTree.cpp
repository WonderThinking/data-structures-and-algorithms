#include<iostream>
#include<algorithm>
#include"AvlNode.h"
#include"AVLTree.h"
using namespace std;

/* 构造函数 */
AVLTree::AVLTree()
{
	m_root = NULL;
}


/* 析构函数 */
AVLTree::~AVLTree()
{
	deleteTree(m_root);
}

void AVLTree::deleteTree(AvlNode *root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
	return;
}

/* 获取高度 */
int AVLTree::getHeight(AvlNode *t)
{
	return t == NULL ? -1 : t->height;
}


/* 插入元素 */
void AVLTree::insert(int x)
{
	insert(x, m_root);
}

void AVLTree::insert(int x, AvlNode * &t)
{
	if (t == NULL)
		t = new AvlNode(x, NULL, NULL);
	else if (x < t->element)
	{
		insert(x, t->left);
		if (getHeight(t->left) - getHeight(t->right) == 2)
		{
			if (x < t->left->element)	/* LL */
				rotateWithLeftChild(t);
			else						/* LR */
				doubleWithLeftChild(t);
		}
	}
	else if(x>t->element)
	{
		insert(x, t->right);
		if (getHeight(t->right) - getHeight(t->left) == 2)
		{
			if (x > t->right->element)
				rotateWithRightChild(t); /* RR */
			else
				doubleWithRightChild(t); /* RL */
		}
	}
}

void AVLTree::rotateWithLeftChild(AvlNode * &k2)		/* LL型 单向右旋 */
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), k2->height) + 1;
	k2 = k1;
}

void AVLTree::doubleWithLeftChild(AvlNode * &k2)		/* LR型 双旋转 先左旋后右旋 */
{
	rotateWithLeftChild(k2->left);
	rotateWithRightChild(k2);
}

void AVLTree::rotateWithRightChild(AvlNode * &k2)		/* RR型 单向左旋 */
{
	AvlNode *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->left)) + 1;
	k1->height = max(getHeight(k1->right), k2->height) + 1;
	k2 = k1;
}

void AVLTree::doubleWithRightChild(AvlNode * &k2)		/* RL型 双旋转 先右旋后左旋 */
{
	rotateWithRightChild(k2->right);
	rotateWithLeftChild(k2);
}


/* 查找元素 */
bool AVLTree::contains(int key) 
{
	return contains(m_root, key);
}

bool AVLTree::contains(AvlNode * &root, int &key)
{
	if (root == NULL)
		return false;
	if (root->element == key)
		return true;
	else if (root->element > key)
		return contains(root->left, key);
	else
		return contains(root->right, key);
}


/* 删除元素 */
void AVLTree::remove(int x)
{
	remove(m_root, x);
}

void AVLTree::remove(AvlNode * &node, int x)
{
	if (node == NULL)		 /* 没有找到节点 */
		return; 
	if (x < node->element)	 /* 在左子树删除*/
	{
		remove(node->left, x);
		if (getHeight(node->right) - getHeight(node->left) == 2)
		{
			if (node->right->left != NULL && getHeight(node->right->left) > getHeight(node->right->right))
				doubleWithRightChild(node);
			else
				rotateWithRightChild(node);
		}
	}
	else if (x > node->element)	/* 在右子树删除 */
	{
		remove(node->right, x);
		if (getHeight(node->left) - getHeight(node->right) == 2)
		{
			if (node->left->right != NULL && getHeight(node->left->right) > getHeight(node->left->left))
				doubleWithLeftChild(node);
			else
				rotateWithLeftChild(node);
		}
	}
	else						/* 找到要删除的节点 */
	{
		if (node->left != NULL && node->right != NULL) /* 此节点有两个子树*/
		{
			AvlNode *tmp = node->right;
			while (tmp->left != NULL)
				tmp = tmp->left;				 /* 找到右子树中值最小的节点 */
			node->element = tmp->element;		 /* 把右子树中最小节点的值赋值给本节点 */
			remove(node->right, tmp->element);	 /* 删除右子树中最小值的节点 */
			if (getHeight(node->left) - getHeight(node->right) == 2)
			{
				if (node->left->right != NULL && getHeight(node->left->right) > getHeight(node->left->left))
					doubleWithLeftChild(node);
				else
					rotateWithLeftChild(node);
			}
		}
		else	/* 此节点有1个或0个子树 */
		{
			AvlNode *tmp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			delete(tmp);
			tmp = NULL;
		}
	}
}
/* 前序遍历 */
void AVLTree::preOrder() 
{
	preOrder(m_root);
}
void AVLTree::preOrder(AvlNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->element);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* 中序遍历 */
void AVLTree::inOrder()
{
	inOrder(m_root);
}
void AVLTree::inOrder(AvlNode *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->element);
		inOrder(root->right);
	}
}

/* 后序遍历 */
void AVLTree::postOrder()
{
	postOrder(m_root);
}
void AVLTree::postOrder(AvlNode *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->element);
	}
}
