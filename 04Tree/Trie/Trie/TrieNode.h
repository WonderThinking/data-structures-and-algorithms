/* 定义字典树节点类型 */

#include<iostream>
using namespace std;

const int MaxBranchSize = 26;

class TrieNode
{
public:
	int path;		/* 共用该节点的单词数 */
	int end;		/* 以此节点结尾的单词数 */
	TrieNode *map[26];	/* 26个小写字母的哈希表 */

	TrieNode()
	{
		path = 0;
		end = 0;
		memset(map, NULL, sizeof(TrieNode*)*MaxBranchSize); 
	}
};
