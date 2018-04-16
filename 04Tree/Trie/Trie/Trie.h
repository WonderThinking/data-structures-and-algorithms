/* �ֵ�����ʵ�� */

#include<iostream>
#include<string>
#include"TrieNode.h"
using namespace std;

class Trie
{
private:
	TrieNode *root;
public:
	Trie();							/* ���캯�� */
	void insert(string word);		/* ���뵥�� */
	bool search(string word);		/* ���ҵ��� */
	void remove(string word);		/* ɾ������ */
	int prefixNumber(string pre);	/* ��preΪǰ׺�ĵ������� */
	void prePrint();				/* �ֵ������ */

private:
	void Trie::prePrint(TrieNode *node, string str);
};

/* ���캯�� */
Trie::Trie()
{
	root = new TrieNode();
}

/* ���뵥�� */
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

/* ���ҵ��� */
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

/* ɾ������ */
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
				delete node->map[index];
				node->map[index] = NULL;
				return;
			}
		}
		node->end--;
	}
}

/* ��preΪǰ׺�ĵ������� */
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

/* �ֵ������,������� */
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
