#ifndef AvlNode_H
#define AvlNode_H

#include<iostream>
using namespace std;

/* ����ڵ����� */
struct AvlNode
{
	int element;
	AvlNode *left;
	AvlNode *right;
	int height;
	AvlNode(int key, AvlNode *lt, AvlNode *rt, int h = 0) :element(key), left(lt), right(rt), height(h)
	{}
};

#endif // !AvlNode_H
