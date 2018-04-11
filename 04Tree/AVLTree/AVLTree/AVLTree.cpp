#include<iostream>
#include<algorithm>
#include"AvlNode.h"
#include"AVLTree.h"
using namespace std;

/* ���캯�� */
AVLTree::AVLTree()
{
	m_root = NULL;
}


/* �������� */
AVLTree::~AVLTree()
{

}


/* ��ȡ�߶� */
int AVLTree::getHeight(AvlNode *t)
{
	return t == NULL ? -1 : t->height;
}


/* ����Ԫ�� */
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

void AVLTree::rotateWithLeftChild(AvlNode * &k2)		/* LL�� �������� */
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), k2->height) + 1;
	k2 = k1;
}

void AVLTree::doubleWithLeftChild(AvlNode * &k2)		/* LR�� ˫��ת ������������ */
{
	rotateWithLeftChild(k2->left);
	rotateWithRightChild(k2);
}

void AVLTree::rotateWithRightChild(AvlNode * &k2)		/* RR�� �������� */
{
	AvlNode *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->left)) + 1;
	k1->height = max(getHeight(k1->right), k2->height) + 1;
	k2 = k1;
}

void AVLTree::doubleWithRightChild(AvlNode * &k2)		/* RL�� ˫��ת ������������ */
{
	rotateWithRightChild(k2->right);
	rotateWithLeftChild(k2);
}


/* ����Ԫ�� */
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


/* ɾ��Ԫ�� */
void AVLTree::remove(int key)
{



}


/* ǰ����� */
void AVLTree::preOrder() 
{
	preOrder(m_root);
}
void AVLTree::preOrder(AvlNode *root)
{
	printf("%d ", root->element);
	preOrder(root->left);
	preOrder(root->right);
}

/* ������� */
void AVLTree::inOrder()
{
	inOrder(m_root);
}
void AVLTree::inOrder(AvlNode *root)
{
	inOrder(root->left);
	printf("%d ", root->element);
	inOrder(root->right);
}

/* ������� */
void AVLTree::postOrder()
{
	postOrder(m_root);
}
void AVLTree::postOrder(AvlNode *root)
{
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->element);
}

https://blog.csdn.net/u010672692/article/details/45749071
https://blog.csdn.net/sysu_arui/article/details/7897017
https://blog.csdn.net/sysu_arui/article/details/7865864
https://blog.csdn.net/sysu_arui/article/details/7906303
