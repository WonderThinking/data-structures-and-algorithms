/* ������������ڵ�����  Huffman Tree Node */

#ifndef HTNode_H
#define HTNode_H

#include<iostream>
using namespace std;
class HTNode
{
public:
	char c;				/* �ַ� */
	unsigned int freq;  /* ���ַ����ļ��г��ֵĴ��� */
	HTNode *lchild;		
	HTNode *rchild;

	HTNode(char key = '\0', unsigned int fr = 0,HTNode *l = NULL,HTNode *r = NULL):
		c(key),freq(fr),lchild(l),rchild(r)
	{}
};

#endif // !HTNode_H
