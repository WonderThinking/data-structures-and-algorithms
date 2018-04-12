#ifndef PriorityQueue_H
#define PriorityQueue_H

#include<iostream>
#include<vector>
#include"PQnode.h"
using namespace std;
class PriorityQueue
{
private:
	vector<PQnode> heap;
	int heapSize;
public:
	PriorityQueue();
	void push(PQnode node);
	bool empty();
	PQnode top();
	void pop();
};

PriorityQueue::PriorityQueue()
{
	PQnode nullNode(INT_MIN, INT_MIN);  /* ��0λ�����һ���ڵ㣬ʹ�öѵ��±��1��ʼ*/
	heap.push_back(nullNode);
	heapSize = 0;
}

void PriorityQueue::push(PQnode node)
{
	heap.push_back(node); 
	++heapSize;
	int i;
	for (i = heapSize;i > 1 && heap[i / 2].key > node.key; i = i / 2)
		heap[i] = heap[i / 2];
	heap[i] = node;
}

bool PriorityQueue::empty()
{
	return heapSize == 0 ? true : false;
}

PQnode PriorityQueue::top()
{
	if (heapSize != 0)
		return heap[1];
	cout << "���ȶ���Ϊ��\n" << endl;
	return heap[0];
}

void PriorityQueue::pop()
{
	if (heapSize == 0)
	{
		cout << "����Ϊ�գ�����ʧ��\n" << endl;
		return;
	}

	/* �������һ��Ԫ�أ�ɾ�����һ��Ԫ�أ����Ѷ�Ԫ�ظ��ǣ����µ����ѣ��Ӷ�ʵ��ɾ���Ѷ�Ԫ�� */
	/* �ӶѶ���ʼ���µ���,iԪ���������Һ��ӵĽ�С���Ǹ�����,ֱ��lastNodeС��heap[i] */
	PQnode lastNode = heap[heapSize];
	heap.pop_back();
	--heapSize;
	if (heapSize == 0)
		return;
	int child;
	int i;
	for (i = 1;i <= heapSize / 2;i = child)
	{
		child = i * 2;
		if (child + 1 <= heapSize && heap[child + 1].key < heap[child].key)
			child = child + 1;
		if (lastNode.key > heap[child].key)
			heap[i] = heap[child];
		else
			break;
	}
	heap[i] = lastNode;
}
#endif // !PriorityQueue_H


