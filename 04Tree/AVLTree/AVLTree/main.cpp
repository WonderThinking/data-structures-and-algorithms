/* ƽ���������C++ʵ�� AVL Tree
 * �ص㣺ƽ�������Ҫ�����ÿһ���ڵ���˵���������������ĸ߶�֮��ܳ���1����������ܺõĽ���˶���������˻������������
 * ʱ�临�Ӷȣ�����,����,ɾ����ʱ�临�Ӷ���������������ά����O(logN)������Ƶ����ת��ʹ�����ɾ��������O(logN)���ҵ�ʱ��
 */

#include<iostream>
#include"AvlNode.h"
#include"AVLTree.h"
using namespace std;

int main()
{
	AVLTree tree;
	for (int i = 1; i < 9; ++i)
		tree.insert(i);
	tree.inOrder();
	cout << endl;
	tree.remove(4);
	tree.inOrder();
	system("pause");
	return 0;
}
