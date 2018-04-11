#ifndef AVLTree_H
#define AVLTree_H

#include<iostream>
#include"AvlNode.h"
using namespace std;

class AVLTree
{
private:
	AvlNode *m_root; /* ����� */
public:
	AVLTree();
	~AVLTree();
	int getHeight(AvlNode *t);
	void insert(int x);
	bool contains(int x);
	void remove(int x);
	void preOrder();
	void inOrder();
	void postOrder();
private:
	void insert(int x, AvlNode * &t);
	void rotateWithRightChild(AvlNode * &k2);	/* RR�� �������� */
	void rotateWithLeftChild(AvlNode * &k2);	/* LL�� �������� */
	void doubleWithRightChild(AvlNode * &k2);	/* RL ˫��ת ������������ */
	void doubleWithLeftChild(AvlNode * &k2);	/* LR ˫��ת ������������ */
	bool contains(AvlNode * &root, int &key);
	void preOrder(AvlNode *root);
	void inOrder(AvlNode *root);
	void postOrder(AvlNode *root);
};

#endif // !AVLTree_H
