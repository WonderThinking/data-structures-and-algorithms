/* ��Ծ���C����ʵ�� SkipList
 * ʱ�临�Ӷ�O(logN)
 * ԭ����ܣ���ʡ��ѧԺ������:�㷨����_��Ծ�� http://open.163.com/movie/2010/12/7/S/M6UTT5U0I_M6V2TTJ7S.html
 * �ο����ͣ� http://www.cppblog.com/mysileng/archive/2013/04/06/199159.html
 * д�������׳���ĵط�������Ƚϵ��Ǽ�ֵkey
 */

#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define MAX_LEVEL  10 /* ����������� */

/* ����ڵ����� */
struct nodeStructure
{
	int key;
	int value;
	struct nodeStructure *forward[1];
};

/* ���� */
struct skipList
{
	int level;				/* ��ǰ���� */
	nodeStructure *header;  /* ͷ�ڵ� */
};

/* �����ڵ� */
nodeStructure* createNode(int level, int key, int value)
{
	nodeStructure *ns = (nodeStructure *)malloc(sizeof(nodeStructure) + level*sizeof(nodeStructure*));
	ns->key = key;
	ns->value = value;
	return ns;
}

/* ��ʼ������ */
skipList* createList()
{
	skipList *sl = (skipList*)malloc(sizeof(skipList));
	sl->level = 0;
	sl->header = createNode(MAX_LEVEL - 1, INT_MIN, INT_MIN);
	for (int i = 0;i < MAX_LEVEL;++i)
		sl->header->forward[i] = NULL;
	return sl;
}

/* ����������� */
int randomLevel()
{
	int k = 1; 
	while (rand() % 2 == 1)
		++k;
	k = (k < MAX_LEVEL) ? k : MAX_LEVEL;
	return k;
}

/* ����ڵ� */
bool insert(skipList *sl, int key, int value)
{
	nodeStructure *update[MAX_LEVEL];	/* ��¼Ҫ����ڵ���ÿһ��Ľڵ�λ�ã�down�ڵ� */
	nodeStructure *p = sl->header;		/* ǰһ��ָ��,left�ڵ� */
	nodeStructure *q = NULL;			/* ��һ��ָ��,right�ڵ� */

	/* ���������߲����²�����Ҫ�����λ�� */
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

	/* ���ܲ�����ͬ��key */
	if (q != NULL && q->key == key)
		return false;

	/* ����һ���������k */
	int k = randomLevel();
	if (k > (sl->level))
	{
		for (int i = sl->level;i < k;++i)
			update[i] = sl->header;
		sl->level = k;
	}

	/* �����ڵ� */
	q = createNode(k - 1, key, value);		/* ��blog��ͬ */

	/* �����½ڵ��ָ�룬����ͨ�������ڵ�һ�� */
	for (int i = 0;i < k;++i)
	{
		q->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = q;
	}
	return true;
}

/* ɾ���ڵ� */
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
		/* ���ɾ��������ͨ����ɾ��һ�� */
		for (int i = 0;i < sl->level;++i)
			if (update[i]->forward[i] == q)
				update[i]->forward[i] = q->forward[i];
		free(q); /* malloc�������Ҫfree�ͷţ�new�������delete�ͷ� */

		/* ���ɾ����������Ľڵ㣬��ô��Ҫ����ά��������� */
		for (int i = sl->level - 1;i >= 0;--i)
			if (sl->header->forward[i] == NULL)
				sl->level--;
		return true;
	}
	else
		return false;
}

/* ���ҽڵ� */
int search(skipList *sl, int key)
{
	nodeStructure *p = sl->header;
	nodeStructure *q = NULL;
	/* ����߲㿪ʼ�� */
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
	/* �������� */
	skipList *sl = createList();
	/* ���� */
	for (int i = 1;i <= 10;++i)
		insert(sl, i, i * 2);
	printf("�������������¼\n");
	printSL(sl);

	/* ���� */
	int key = 4;
	int i = search(sl, key);
	printf("���� key=%d, value=%d\n", key, i);

	/* ɾ�� */
	bool b = remove(sl, key);
	if (b)
		printf("key=%d �ļ�¼ɾ���ɹ�\n", key);
	printSL(sl);

	/* �ٲ��� */
	insert(sl, key, key * 2);
	printf("�����¼key=%d, value=%d\n", key, key * 2);
	printSL(sl);
	system("pause");
	return 0;
}
