/* 最小优先队列的C++实现(基于堆实现)
 * 在优先队列中,元素被赋予优先级.当访问元素时,最小优先队列中最低优先级的元素最先取出
 * 最小优先队列：在维护一个最小堆
 * 最大优先队列：在维护一个最大堆
 */

#include<iostream>
#include<vector>
#include"PQnode.h"
#include"PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue p;
	for (int i = 10; i <= 14; i = i + 2)
		p.push(PQnode(i, i * 2));
	for (int i = 6; i <= 8; i = i + 2)
		p.push(PQnode(i, i * 2));
	while (!p.empty())
	{
		cout << p.top().key << ' ' << endl;
		p.pop();
	}
	system("pause");
	return 0;
}
