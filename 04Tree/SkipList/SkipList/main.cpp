/* 跳跃表的C语言实现 SkipList
 * 时间复杂度O(logN)
 * 原理介绍：麻省理工学院公开课:算法导论_跳跃表 http://open.163.com/movie/2010/12/7/S/M6UTT5U0I_M6V2TTJ7S.html
 * 参考博客： http://www.cppblog.com/mysileng/archive/2013/04/06/199159.html
 * 写程序容易出错的地方：参与比较的是键值key
 */

#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define MAX_LEVEL  10 /* 跳表的最大层数 */

/* 定义节点类型 */
struct nodeStructure
{
	int key;
	int value;
	struct nodeStructure *forward[1];
};

/* 跳表 */
struct skipList
{
	int level;				/* 当前层数 */
	nodeStructure *header;  /* 头节点 */
};

/* 创建节点 */
nodeStructure* createNode(int level, int key, int value)
{
	nodeStructure *ns = (nodeStructure *)malloc(sizeof(nodeStructure) + level*sizeof(nodeStructure*));
	ns->key = key;
	ns->value = value;
	return ns;
}

/* 初始化跳表 */
skipList* createList()
{
	skipList *sl = (skipList*)malloc(sizeof(skipList));
	sl->level = 0;
	sl->header = createNode(MAX_LEVEL - 1, INT_MIN, INT_MIN);
	for (int i = 0;i < MAX_LEVEL;++i)
		sl->header->forward[i] = NULL;
	return sl;
}

/* 随机产生层数 */
int randomLevel()
{
	int k = 1; 
	while (rand() % 2 == 1)
		++k;
	k = (k < MAX_LEVEL) ? k : MAX_LEVEL;
	return k;
}

/* 插入节点 */
bool insert(skipList *sl, int key, int value)
{
	nodeStructure *update[MAX_LEVEL];	/* 记录要插入节点在每一层的节点位置，down节点 */
	nodeStructure *p = sl->header;		/* 前一个指针,left节点 */
	nodeStructure *q = NULL;			/* 后一个指针,right节点 */

	/* 从跳表的最高层向下查找需要插入的位置 */
	for (int i = sl->level - 1;i >= 0;--i)
	{
		q = p->forward[i];
		while (q != NULL && q->key < key)
		{
			p = q;
			q = q->forward[i];
		}
		update[i] = p;
	}

	/* 不能插入相同的key */
	if (q != NULL && q->key == key)
		return false;

	/* 产生一个随机层数k */
	int k = randomLevel();
	if (k > (sl->level))
	{
		for (int i = sl->level;i < k;++i)
			update[i] = sl->header;
		sl->level = k;
	}

	/* 创建节点 */
	q = createNode(k - 1, key, value);		/* 与blog不同 */

	/* 逐层更新节点的指针，和普通链表插入节点一样 */
	for (int i = 0;i < k;++i)
	{
		q->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = q;
	}
	return true;
}

/* 删除节点 */
bool remove(skipList *sl, int key)
{
	nodeStructure *update[MAX_LEVEL];
	nodeStructure *p = sl->header;
	nodeStructure *q = NULL;
	for (int i = sl->level - 1;i >= 0;--i)
	{
		q = p->forward[i];
		while (q != NULL && q->key < key)
		{
			p = q;
			q = q->forward[i];
		}
		update[i] = p;
	}

	if (q != NULL && q->key == key)
	{
		/* 逐层删除，和普通链表删除一样 */
		for (int i = 0;i < sl->level;++i)
			if (update[i]->forward[i] == q)
				update[i]->forward[i] = q->forward[i];
		free(q); /* malloc申请的需要free释放，new申请的用delete释放 */

		/* 如果删除的是最大层的节点，那么需要重新维护跳表层数 */
		for (int i = sl->level - 1;i >= 0;--i)
			if (sl->header->forward[i] == NULL)
				sl->level--;
		return true;
	}
	else
		return false;
}

/* 查找节点 */
int search(skipList *sl, int key)
{
	nodeStructure *p = sl->header;
	nodeStructure *q = NULL;
	/* 从最高层开始搜 */
	for (int i = sl->level - 1;i >= 0;--i)
	{
		q = p->forward[i];
		while (q != NULL && q->key < key)
		{
			p = q;
			q = q->forward[i];
		}
		if (q->key == key)
			return q->value;
	}
	return NULL;
}

void printSL(skipList *sl)
{
	nodeStructure *p;
	nodeStructure *q;
	for (int i = sl->level - 1;i >= 0;--i)
	{
		p = sl->header;
		q = p->forward[i];
		while (q != NULL)
		{
			printf("%d->", q->value);
			p = q;
			q = q->forward[i];
		}
		printf("\n");
	}
	printf("\n");
}


int main()
{
	/* 创建跳表 */
	skipList *sl = createList();
	/* 插入 */
	for (int i = 1;i <= 10;++i)
		insert(sl, i, i * 2);
	printf("创建跳表、插入记录\n");
	printSL(sl);

	/* 查找 */
	int key = 4;
	int i = search(sl, key);
	printf("查找 key=%d, value=%d\n", key, i);

	/* 删除 */
	bool b = remove(sl, key);
	if (b)
		printf("key=%d 的记录删除成功\n", key);
	printSL(sl);

	/* 再插入 */
	insert(sl, key, key * 2);
	printf("插入记录key=%d, value=%d\n", key, key * 2);
	printSL(sl);
	system("pause");
	return 0;
}
