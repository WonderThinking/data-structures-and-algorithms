/* 哈希查找 Hash Search 
 * 哈希函数构造方法：1.直接定址法 H(key)=key  2.数字分析法(数字选择法)  3.平方取中法
 *					 4.折叠法                 5.除留余数法H(key)=key MOD n
 * 哈希冲突解决办法：1.开放地址法(闭散列法) 包括
 *						1.1 线性探测再散列 (1 2 3 4...)
 *						1.2 二次探测再散列 (1^2   -1^2   2^2   -2^2)
 *						1.3 伪随机探测再散列 (伪随机数序列)
 *					 2.链地址法(拉链法、开散列法) 
 *                   3.再散列（双重散列，多重散列）  
 *					 4.建立一个公共溢出区
 */

/* 哈希查找：哈希函数为除留余数法 处理冲突的方法为线性探查再散列 */
#include<iostream>
#include<vector>
using namespace std;

class HashTable
{
public:
	HashTable(int n);
	void insert(int val);	/* 插入元素 */
	void remove(int val);	/* 删除元素 */
	bool contains(int val);	/* 查找元素 */
private:
	vector<int> table;		/* 哈希表 */
	int len;				/* 哈希表长（在此为定长哈希表，暂不考虑扩容，只能插入len个元素）*/
	int nums;				/* 哈希表中已有的元素数量 */
};

/* 构造函数，根据元素数量开辟哈希表 */
HashTable::HashTable(int n)
{
	table.resize(n, 0x80000000); //初始化为int最小负数
	len = n;
	nums = 0;	
}

/* 插入元素 */
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

/* 删除元素 */
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

/* 查找元素 */
bool HashTable::contains(int val)
{
	int count = 1; // 计数防止找不到发生死循环
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