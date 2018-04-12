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
	PQnode nullNode(INT_MIN, INT_MIN);  /* 在0位置填充一个节点，使得堆的下标从1开始*/
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
	cout << "优先队列为空\n" << endl;
	return heap[0];
}

void PriorityQueue::pop()
{
	if (heapSize == 0)
	{
		cout << "队列为空，出队失败\n" << endl;
		return;
	}

	/* 保存最后一个元素，删除最后一个元素，将堆顶元素覆盖，重新调整堆，从而实现删除堆顶元素 */
	/* 从堆顶开始向下调整,i元素用其左右孩子的较小的那个覆盖,直到lastNode小于heap[i] */
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


