/* ��С���ȶ��е�C++ʵ��(���ڶ�ʵ��)
 * �����ȶ�����,Ԫ�ر��������ȼ�.������Ԫ��ʱ,��С���ȶ�����������ȼ���Ԫ������ȡ��
 * ��С���ȶ��У���ά��һ����С��
 * ������ȶ��У���ά��һ������
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
