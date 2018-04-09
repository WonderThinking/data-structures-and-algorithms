#ifndef TreeNode_H
#define TreeNode_H

#include<iostream>
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

#endif // !TreeNode_H
