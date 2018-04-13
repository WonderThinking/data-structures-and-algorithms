/* 基于最小优先队列构建Huffman树，进行Huffman编码解码 */

#ifndef Huffman_H
#define Huffman_H

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include"HTNode.h"
using namespace std;

/* 重载优先队列中的比较函数 */
struct cmp
{
	bool operator()(HTNode *node1, HTNode *node2)
	{
		return node1->freq > node2->freq;
	}
};

class Huffman
{
private:
	priority_queue<HTNode*, vector<HTNode*>, cmp> pQueue; /* 最小优先队列*/
	vector<string> codeTable;							/* 记录Huffman编码的哈希表 */
public:
	Huffman();							  /* 构造函数 */
	~Huffman();							  /* 析构函数 */
	void HuffmanTree(string str);		  /* 构造Huffman树 */
	void HuffmanCode();					  /* Huffman编码 */
	string HuffmanCompress(string &file); /* 文件压缩 */
	string HuffmanDecode(string &code);	  /* Huffman解码 */
private:
	void HuffmanCode(HTNode *root, string str);  /* 深度优先搜索编码 */
	void HuffmanDecode(HTNode *root, char *code, string &decode); /* Huffman解码实现*/
};

#endif // !Huffman_H

/* 构造函数 */
Huffman::Huffman()
{
	codeTable.resize(256, "\0"); /* 1个char占8位，可取256种情况 */
}

/* 构造Huffman树 */
void Huffman::HuffmanTree(string str)
{
	while (!pQueue.empty())			/* 初始化优先队列 */
		pQueue.pop();
	codeTable.resize(256, "\0");	/* 初始化编码表 */

	vector<int> frequency(256, 0);  /* 统计各字符频数 */
	for (int i = 0; i < str.size(); ++i)
		++frequency[str[i]];

	for(int i = 0;i<256;++i)		/* 添加节点 */
		if (frequency[i] != 0)
		{
			HTNode *node = new HTNode(i - 48 + '0', frequency[i], NULL, NULL);
			pQueue.push(node);
		}

	/* 依据最小优先队列建Huffman树 */
	HTNode *l, *r;
	while (pQueue.size() > 1)
	{
		HTNode *newNode = new HTNode;
		r = pQueue.top();
		pQueue.pop();
		l = pQueue.top();
		pQueue.pop();
		newNode->lchild = l;
		newNode->rchild = r;
		newNode->freq = l->freq + r->freq;
		pQueue.push(newNode);
	}	 
}

/* Huffman编码 */
void Huffman::HuffmanCode()
{
	if (pQueue.empty())									/* 空文件 */
		return;
	HTNode *root = pQueue.top();
	string str = "";
	if (root->lchild == NULL && root->rchild == NULL)	/* 只有一种字符,没有形成路径,单独考虑 */
		codeTable[root->c] = "0";
	else												/* 大于一种字符，进行深度优先搜索解码 */
		HuffmanCode(root, str);
}

void Huffman::HuffmanCode(HTNode *root,string str)
{
	if (root->lchild == NULL && root->rchild == NULL)  /* 到达叶子节点 */
	{
		codeTable[root->c] = str;
		return;
	}
	if (root->lchild != NULL)						   /* 左子树 */
	{
		str += "0";
		HuffmanCode(root->lchild, str);
		str.erase(str.end() - 1);
	}
	if (root->rchild != NULL)						  /* 右子树 */
	{
		str += "1";
		HuffmanCode(root->rchild, str);
	}
}

/* 文件压缩 */
string Huffman::HuffmanCompress(string &file)
{
	string code = "";
	int n = file.size();
	for (int i = 0; i < n; ++i)
		code += codeTable[file[i]];
	return code;
}

/* Huffman解码 */
string Huffman::HuffmanDecode(string &code)
{
	string decode = "";		/* 存储解码后的内容 */
	if (pQueue.empty())		/* 空文件 */
		return decode;

	HTNode *root = pQueue.top();
	if (root->lchild == NULL && root->rchild == NULL) /* 只有一种字符,没有形成路径,单独考虑 */
		for (int i = 0; i < root->freq; ++i)
			decode += root->c;
	else											  /* 大于一种字符 */
		HuffmanDecode(root, &code[0], decode);
	return decode;
}

void Huffman::HuffmanDecode(HTNode *root, char *code, string &decode)
{
	if (*code == '\0')
		return;
	while (root->lchild != NULL && root->rchild != NULL)
	{
		if (*code == '0')
			root = root->lchild;
		else
			root = root->rchild;
		++code;
	}
	decode += root->c;
	HuffmanDecode(pQueue.top(), code, decode);
}

/* 析构函数 */
Huffman::~Huffman()
{
	while (!pQueue.empty())
		pQueue.pop();
	codeTable.clear();
}
