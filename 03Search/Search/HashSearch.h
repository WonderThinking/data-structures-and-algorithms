/* ��ϣ���� Hash Search 
 * ��ϣ�������췽����1.ֱ�Ӷ�ַ�� H(key)=key  2.���ַ�����(����ѡ��)  3.ƽ��ȡ�з�
 *					 4.�۵���                 5.����������H(key)=key MOD n
 * ��ϣ��ͻ����취��1.���ŵ�ַ��(��ɢ�з�) ����
 *						1.1 ����̽����ɢ�� (1 2 3 4...)
 *						1.2 ����̽����ɢ�� (1^2   -1^2   2^2   -2^2)
 *						1.3 α���̽����ɢ�� (α���������)
 *					 2.����ַ��(����������ɢ�з�) 
 *                   3.��ɢ�У�˫��ɢ�У�����ɢ�У�  
 *					 4.����һ�����������
 */

/* ��ϣ���ң���ϣ����Ϊ���������� �����ͻ�ķ���Ϊ����̽����ɢ�� */
#include<iostream>
#include<vector>
using namespace std;

class HashTable
{
public:
	HashTable(int n);
	void insert(int val);	/* ����Ԫ�� */
	void remove(int val);	/* ɾ��Ԫ�� */
	bool contains(int val);	/* ����Ԫ�� */
private:
	vector<int> table;		/* ��ϣ�� */
	int len;				/* ��ϣ�����ڴ�Ϊ������ϣ���ݲ��������ݣ�ֻ�ܲ���len��Ԫ�أ�*/
	int nums;				/* ��ϣ�������е�Ԫ������ */
};

/* ���캯��������Ԫ���������ٹ�ϣ�� */
HashTable::HashTable(int n)
{
	table.resize(n, 0x80000000); //��ʼ��Ϊint��С����
	len = n;
	nums = 0;	
}

/* ����Ԫ�� */
void HashTable::insert(int val)
{
	if (nums == len)
	{
		cout << "HashTable is full !\n" << endl;
		return;
	}
	int H = val % len;
	while (table[H] != 0x80000000)
	{
		++H;
		if (H == len)
			H = 0;
	}
	table[H] = val;
	++nums;
}

/* ɾ��Ԫ�� */
void HashTable::remove(int val)
{
	if (nums == 0)
	{
		cout << "HashTable is empty !" << endl;
		return;
	}
	int H = val % len;
	while (table[H] != val)
	{
		if (table[H] == 0x80000000)
		{
			cout << "Not Found " << endl;
			return;
		}
		++H;
		if (H == len)
			H -= len;
	}
	table[H] = 0x80000000;
	--nums;
}

/* ����Ԫ�� */
bool HashTable::contains(int val)
{
	int count = 1; // ������ֹ�Ҳ���������ѭ��
	int H = val % len;
	while (table[H] != val && count <= len)
	{
		if (table[H] == 0x80000000)
		{
			cout << "Not Found ";
			return false;
		}
		++H;
		++count;
		if (H == len)
			H -= len;
	}

	if(table[H] == val)
	{
		cout << "Found ";
		return true;
	}
	cout << "Not Found ";
	return false;
}