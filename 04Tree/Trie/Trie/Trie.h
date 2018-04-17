/* 字典树的实现 */

#include<iostream>
#include<string>
#include"TrieNode.h"
using namespace std;

class Trie
{
private:
	TrieNode *root;
public:
	Trie();							/* 构造函数 */
	void insert(string word);		/* 插入单词 */
	bool search(string word);		/* 查找单词 */
	void remove(string word);		/* 删除单词 */
	int prefixNumber(string pre);	/* 以pre为前缀的单词数量 */
	void prePrint();				/* 字典序输出 */

private:
	void Trie::prePrint(TrieNode *node, string str);
};

/* 构造函数 */
Trie::Trie()
{
	root = new TrieNode();
}

/* 插入单词 */
void Trie::insert(string word)		
{
	if (word.empty())
		return;
	TrieNode *node = root;
	int index = 0;
	int n = word.size();
	for (int i = 0; i < n; ++i)
	{
		index = word[i] - 'a';
		if (node->map[index] == NULL)
			node->map[index] = new TrieNode();
		node = node->map[index];
		node->path++;
	}
	node->end++;
}

/* 查找单词 */
bool Trie::search(string word)		
{
	if (word.empty())
		return false;
	TrieNode *node = root;
	int index = 0;
	int n = word.size();
	for (int i = 0; i < n; ++i)
	{
		index = word[i] - 'a';
		if (node->map[index] == NULL)
			return false;
		node = node->map[index];
	}
	return node->end != 0;
}

/* 删除单词 */
void Trie::remove(string word)
{
	if (search(word))
	{
		TrieNode *node = root;
		int index = 0;
		int n = word.size();
		for (int i = 0; i < n; ++i)
		{
			index = word[i] - 'a';
			if (node->map[index]->path-- == 1)
			{
				delete[] node->map[index];
				node->map[index] = NULL;
				return;
			}
		}
		node->end--;
	}
}

/* 以pre为前缀的单词数量 */
int Trie::prefixNumber(string pre)	
{
	if (pre.empty())
		return 0;
	TrieNode *node = root;
	int index = 0;
	int n = pre.size();
	for (int i = 0; i < n; ++i)
	{
		index = pre[i] - 'a';
		if (node->map[index] == NULL)
			return 0;
		node = node->map[index];
	}
	return node->path;
}

/* 字典序输出,先序遍历 */
void Trie::prePrint()
{
	if (root == NULL)
		return;
	prePrint(root, "");
}

void Trie::prePrint(TrieNode *node,string str)
{
	if (node->end != 0)
	{
		cout << str << endl;
	}
	for (int i = 0; i < MaxBranchSize; ++i)
	{
		if (node->map[i] != NULL)
		{
			str = str + (char)(i + 'a');
			prePrint(node->map[i], str);
			str.erase(str.end() - 1);
		}
	}
}
