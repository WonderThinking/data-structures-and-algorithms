/* �����ֵ����ڵ����� */

#include<iostream>
using namespace std;

const int MaxBranchSize = 26;

class TrieNode
{
public:
	int path;		/* ���øýڵ�ĵ����� */
	int end;		/* �Դ˽ڵ��β�ĵ����� */
	TrieNode *map[26];	/* 26��Сд��ĸ�Ĺ�ϣ�� */

	TrieNode()
	{
		path = 0;
		end = 0;
		memset(map, NULL, sizeof(TrieNode*)*MaxBranchSize); 
	}
};
