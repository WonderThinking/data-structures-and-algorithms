/* �������� Huffman Tree
 * ʹ�����ȶ���������Huffman�������롢����
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

/* ����Huffman���ڵ����� */
typedef struct HTNode
{
	char c;
	unsigned int freq;
	HTNode *lchild, *rchild;
	HTNode(char key = '\0', unsigned int fr = 0, HTNode *l = NULL, HTNode *r = NULL) :
		c(key), freq(fr), lchild(l), rchild(r)
	{}
}HTNode, *pNode;

/* �������ȶ�����ıȽϺ��� */
struct cmp
{
	bool operator()(pNode node1, pNode node2)
	{
		return node1->freq > node2->freq;
	}
};

/* �����ڵ�ָ�����С���ȶ��� */
priority_queue<pNode, vector<pNode>, cmp> pq;

/* ��¼Huffman����Ĺ�ϣ�� */
vector<string> hashTable(256, "\0");

/* �������ȶ��й���Huffman�� */
void HuffmanCode()
{
	pNode l, r;
	while (pq.size() > 1)
	{
		pNode z = new HTNode;
		r = pq.top();
		pq.pop();
		l = pq.top();
		pq.pop();
		z->rchild = r;
		z->lchild = l;
		z->freq = l->freq + r->freq;
		pq.push(z);
	}
}

/* ����ݹ����Huffman�����HuffmanCode */
void PrintCode(pNode t, string str)
{
	if (t == NULL)
		return;
	/* ���������� */
	if (t->lchild)
	{
		str += '0';
		PrintCode(t->lchild, str);
	}
	/* ����Ҷ�ӽڵ㣬��ӡ���� */
	if (t->lchild == NULL && t->rchild == NULL)
	{
		hashTable[t->c] = str;
		cout << t->c << " 's code: " << str << " frequency:" << t->freq << endl;
	}
	str.erase(str.end() - 1); /* ɾ�����һ���ַ� */
							  /* ���������� */
	if (t->rchild != NULL)
	{
		str += '1';
		PrintCode(t->rchild, str);
	}
}

/* Huffman���� */
string decode;	/* �洢���������� */

void HuffmanDecode(pNode node, char *code)
{
	if (*code == '\0')
		return;
	while (node->lchild != NULL && node->rchild != NULL)
	{
		if (*code == '0')
			node = node->lchild;
		else
			node = node->rchild;
		++code;
	}
	decode = decode + node->c;
	HuffmanDecode(pq.top(), code);
}

int main()
{
	string source = "This is the Huffman coding file.Author:Wang Xinqi";
	cout << "ԭʼ���ݣ�\n" << source << endl;
	int frequency[256] = { 0 };
	for (int i = 0; i < source.size() - 1; ++i)
		++frequency[source[i]];
	for (int i = 0; i < 256; ++i)
		if (frequency[i] != 0)
		{
			pNode node = new HTNode(i - 48 + '0', frequency[i], NULL, NULL);
			pq.push(node);
		}
	HuffmanCode();
	string str = "";
	PrintCode(pq.top(), str);
	string res = "";
	for (int i = 0; i < source.size(); ++i)
		res = res + hashTable[source[i]];
	cout << "\n���������������ݣ�\n" << res << endl;

	decode = "";
	HuffmanDecode(pq.top(), &res[0]);
	cout << "\n���������������ݣ�\n" << decode << endl;

	system("pause");
	return 0;
}
