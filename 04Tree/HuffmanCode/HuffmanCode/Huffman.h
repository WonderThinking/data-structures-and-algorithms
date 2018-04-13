/* ������С���ȶ��й���Huffman��������Huffman������� */

#ifndef Huffman_H
#define Huffman_H

#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include"HTNode.h"
using namespace std;

/* �������ȶ����еıȽϺ��� */
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
	priority_queue<HTNode*, vector<HTNode*>, cmp> pQueue; /* ��С���ȶ���*/
	vector<string> codeTable;							/* ��¼Huffman����Ĺ�ϣ�� */
public:
	Huffman();							  /* ���캯�� */
	~Huffman();							  /* �������� */
	void HuffmanTree(string str);		  /* ����Huffman�� */
	void HuffmanCode();					  /* Huffman���� */
	string HuffmanCompress(string &file); /* �ļ�ѹ�� */
	string HuffmanDecode(string &code);	  /* Huffman���� */
private:
	void HuffmanCode(HTNode *root, string str);  /* ��������������� */
	void HuffmanDecode(HTNode *root, char *code, string &decode); /* Huffman����ʵ��*/
};

#endif // !Huffman_H

/* ���캯�� */
Huffman::Huffman()
{
	codeTable.resize(256, "\0"); /* 1��charռ8λ����ȡ256����� */
}

/* ����Huffman�� */
void Huffman::HuffmanTree(string str)
{
	while (!pQueue.empty())			/* ��ʼ�����ȶ��� */
		pQueue.pop();
	codeTable.resize(256, "\0");	/* ��ʼ������� */

	vector<int> frequency(256, 0);  /* ͳ�Ƹ��ַ�Ƶ�� */
	for (int i = 0; i < str.size(); ++i)
		++frequency[str[i]];

	for(int i = 0;i<256;++i)		/* ��ӽڵ� */
		if (frequency[i] != 0)
		{
			HTNode *node = new HTNode(i - 48 + '0', frequency[i], NULL, NULL);
			pQueue.push(node);
		}

	/* ������С���ȶ��н�Huffman�� */
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

/* Huffman���� */
void Huffman::HuffmanCode()
{
	if (pQueue.empty())									/* ���ļ� */
		return;
	HTNode *root = pQueue.top();
	string str = "";
	if (root->lchild == NULL && root->rchild == NULL)	/* ֻ��һ���ַ�,û���γ�·��,�������� */
		codeTable[root->c] = "0";
	else												/* ����һ���ַ���������������������� */
		HuffmanCode(root, str);
}

void Huffman::HuffmanCode(HTNode *root,string str)
{
	if (root->lchild == NULL && root->rchild == NULL)  /* ����Ҷ�ӽڵ� */
	{
		codeTable[root->c] = str;
		return;
	}
	if (root->lchild != NULL)						   /* ������ */
	{
		str += "0";
		HuffmanCode(root->lchild, str);
		str.erase(str.end() - 1);
	}
	if (root->rchild != NULL)						  /* ������ */
	{
		str += "1";
		HuffmanCode(root->rchild, str);
	}
}

/* �ļ�ѹ�� */
string Huffman::HuffmanCompress(string &file)
{
	string code = "";
	int n = file.size();
	for (int i = 0; i < n; ++i)
		code += codeTable[file[i]];
	return code;
}

/* Huffman���� */
string Huffman::HuffmanDecode(string &code)
{
	string decode = "";		/* �洢���������� */
	if (pQueue.empty())		/* ���ļ� */
		return decode;

	HTNode *root = pQueue.top();
	if (root->lchild == NULL && root->rchild == NULL) /* ֻ��һ���ַ�,û���γ�·��,�������� */
		for (int i = 0; i < root->freq; ++i)
			decode += root->c;
	else											  /* ����һ���ַ� */
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

/* �������� */
Huffman::~Huffman()
{
	while (!pQueue.empty())
		pQueue.pop();
	codeTable.clear();
}
