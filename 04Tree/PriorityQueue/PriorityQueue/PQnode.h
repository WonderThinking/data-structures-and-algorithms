#ifndef PQnode_H
#define PQnode_H

struct PQnode
{
	int key;		/* ����Ƚϵļ�ֵ,�����ȼ� */
	int element;	/* Ԫ�� */
	PQnode(int pri, int ele) :key(pri), element(ele)
	{}
};

#endif // !PQnode_H
