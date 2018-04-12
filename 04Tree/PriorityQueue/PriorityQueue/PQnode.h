#ifndef PQnode_H
#define PQnode_H

struct PQnode
{
	int key;		/* 参与比较的键值,即优先级 */
	int element;	/* 元素 */
	PQnode(int pri, int ele) :key(pri), element(ele)
	{}
};

#endif // !PQnode_H
