#ifndef AVLTree_H
#define AVLTree_H

#include<iostream>
#include"AvlNode.h"
using namespace std;

class AVLTree
{
private:
	AvlNode *m_root; /* 根结点 */
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
	void rotateWithRightChild(AvlNode * &k2);	/* RR型 单向左旋 */
	void rotateWithLeftChild(AvlNode * &k2);	/* LL型 单向右旋 */
	void doubleWithRightChild(AvlNode * &k2);	/* RL 双旋转 先右旋后左旋 */
	void doubleWithLeftChild(AvlNode * &k2);	/* LR 双旋转 先左旋后右旋 */
	bool contains(AvlNode * &root, int &key);
	void preOrder(AvlNode *root);
	void inOrder(AvlNode *root);
	void postOrder(AvlNode *root);
};

#endif // !AVLTree_H
