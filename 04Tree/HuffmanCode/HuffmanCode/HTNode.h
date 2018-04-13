/* 定义哈夫曼树节点类型  Huffman Tree Node */

#ifndef HTNode_H
#define HTNode_H

#include<iostream>
using namespace std;
class HTNode
{
public:
	char c;				/* 字符 */
	unsigned int freq;  /* 该字符在文件中出现的次数 */
	HTNode *lchild;		
	HTNode *rchild;

	HTNode(char key = '\0', unsigned int fr = 0,HTNode *l = NULL,HTNode *r = NULL):
		c(key),freq(fr),lchild(l),rchild(r)
	{}
};

#endif // !HTNode_H
