/* 哈夫曼树 Huffman Tree
 * 使用优先队列来构建Huffman树并编码、解码
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

/* 定义Huffman树节点类型 */
typedef struct HTNode
{
	char c;
	unsigned int freq;
	HTNode *lchild, *rchild;
	HTNode(char key = '\0', unsigned int fr = 0, HTNode *l = NULL, HTNode *r = NULL) :
		c(key), freq(fr), lchild(l), rchild(r)
	{}
}HTNode, *pNode;

/* 重载优先队列里的比较函数 */
struct cmp
{
	bool operator()(pNode node1, pNode node2)
	{
		return node1->freq > node2->freq;
	}
};

/* 包含节点指针的最小优先队列 */
priority_queue<pNode, vector<pNode>, cmp> pq;

/* 记录Huffman编码的哈希表 */
vector<string> hashTable(256, "\0");

/* 依据优先队列构建Huffman树 */
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

/* 中序递归遍历Huffman树求解HuffmanCode */
void PrintCode(pNode t, string str)
{
	if (t == NULL)
		return;
	/* 遍历左子树 */
	if (t->lchild)
	{
		str += '0';
		PrintCode(t->lchild, str);
	}
	/* 到达叶子节点，打印编码 */
	if (t->lchild == NULL && t->rchild == NULL)
	{
		hashTable[t->c] = str;
		cout << t->c << " 's code: " << str << " frequency:" << t->freq << endl;
	}
	str.erase(str.end() - 1); /* 删除最后一个字符 */
							  /* 遍历右子树 */
	if (t->rchild != NULL)
	{
		str += '1';
		PrintCode(t->rchild, str);
	}
}

/* Huffman解码 */
string decode;	/* 存储解码后的内容 */

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
	cout << "原始内容：\n" << source << endl;
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
	cout << "\n哈夫曼编码后的内容：\n" << res << endl;

	decode = "";
	HuffmanDecode(pq.top(), &res[0]);
	cout << "\n哈夫曼解码后的内容：\n" << decode << endl;

	system("pause");
	return 0;
}
