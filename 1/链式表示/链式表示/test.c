#define  _CRT_SECURE_NO_WARNING

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType
{
	int i;
}Elem;

typedef struct Lnode
{
	Elem data;
	struct Lnode* next;
}Lnode, *Linklist;

Linklist InitList() // 初始化链表(头结点的元素初始化为 0 )
{
	Linklist L;
	L = (Linklist)malloc(sizeof(Lnode));
	L->data.i = 0;
	L->next = NULL;
	return L;
}

void ListEmpty(Linklist L) // 判断链表是否为空
{
	assert(L);
	if (L->next)
	{
		printf("链表不为空\n");
	}
	else
	{
		printf("链表为空\n");
	}
}

void HeadAddList(Linklist L, int n) // 头插法建立单链表
{
	assert(L);
	for (int i = 0; i < n; i++)
	{
		Lnode* s;
		s = (Lnode*)malloc(sizeof(Lnode));
		scanf_s("%d", &s->data.i);
		s->next = L->next;
		L->next = s;
	}
}

void TailAddList(Linklist L, int n) // 尾插法建立单链表
{
	assert(L);
	for (int i = 0; i < n; i++)
	{
		Lnode* s;
		s = (Lnode*)malloc(sizeof(Lnode));
		scanf_s("%d", &s->data.i);
		s->next = NULL;
		L->next = s;
		L = s;
	}
}

void ListLength(Linklist L) // 链表的长度
{
	assert(L);
	int count = 0;
	while (L->next)
	{
		L = L->next;
		count++;
	}
	printf("链表的长度为：%d\n", count);
}

void ListTraverse(Linklist L) // 遍历链表
{
	assert(L);
	while (L->next)
	{
		L = L->next;
		printf("%d ", L->data.i);
	}
	printf("\n");
}

void DestroyList(Linklist L) // 销毁链表
{
	assert(L);
	Lnode* s;
	while (L)
	{
		s = L;
		L = L->next;
		free(s);
	}
}

void ClearList(Linklist L) // 清空链表
{
	assert(L);
	Lnode* p, * q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

void GetElem(Linklist L, int i, Elem* e) // 获取链表中的第 i 个元素
{
	assert(L);
	Lnode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		++j;
		p = p->next;
	}
	if (!p || j > i)
	{
		printf("没有第%d个元素\n", i);
		return;
	}
	*e = p->data;
}

int LocateElemSite(Linklist L, Elem e) // 查找链表中的指定元素，返回元素位置
{
	assert(L);
	Lnode* p = L->next;
	int j = 1;
	while (p && (p->data.i != e.i))
	{
		++j;
		p = p->next;
	}
	if (p)
	{
		return j;
	}
	else
	{
		return 0;
	}
}

Lnode* LocateElemPtr(Linklist L, Elem e) // 查找链表中的指定元素，返回元素指针
{
	assert(L);
	Lnode* p = L->next;
	while (p && (p->data.i != e.i))
	{
		p = p->next;
	}
	return p;
}

int ListInsert(Linklist L, int i, Elem e) // 在第i个位置插入元素e
{
	assert(L);
	Lnode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
	{
		return 0;
	}
	Lnode* s;
	s = (Lnode*)malloc(sizeof(Lnode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return 1;
}



int ListDelete(Linklist L, int i, Elem* e) // 删除第i个元素
{
	assert(L);
	Lnode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
	{
		return 0;
	}
	Lnode* s;
	s = (Lnode*)malloc(sizeof(Lnode));
	s = p->next;
	p->next = p->next->next;
	*e = s->data;
	free(s);
	return 1;
}

int main()
{
	Linklist L;  // 定义链表
	L = InitList();// 初始化链表
	Lnode* p;// 定义结点
	p = L; // p 指向头结点
	ListEmpty(L); // 判断链表是否为空
	printf("建立链表\n"); // 1 3 5 7 9 2 4 6 8 10 
	printf("请输入链表的长度：");
	int n;
	scanf_s("%d", &n);
	printf("请输入链表的元素：");
	//HeadAddList(L, n); // 头插法建立单链表
	TailAddList(L, n); // 尾插法建立单链表
	ListLength(L); // 链表的长度
	printf("遍历链表：");
	ListTraverse(L); // 遍历链表

	printf("\n");
	Elem k;
	GetElem(L, 3, &k);
	Elem l;
	GetElem(L, 100, &l);
	printf("第三个元素为%d\n", k.i);

	printf("\n");
	if (LocateElemSite(L, k))
	{
		printf("元素%d的位置为：%d\n", k.i, LocateElemSite(L, k));
	}
	else
	{
		printf("没有元素%d\n", k.i);
	}
	Elem kk = { 99 };
	if (LocateElemSite(L, kk))
	{
		printf("元素%d的位置为：%d\n", kk.i, LocateElemSite(L, kk));
	}
	else
	{
		printf("没有元素%d\n", kk.i);
	}
	Lnode* ptr1 = LocateElemPtr(L, k);
	if (ptr1)
	{
		printf("元素%d的指针为：%p，内容为%d\n", k.i, ptr1, ptr1->data.i);
	}
	else
	{
		printf("没有元素%d\n", k.i);
	}
	Lnode* ptr2 = LocateElemPtr(L, kk);
	if (ptr2)
	{
		printf("元素%d的指针为：%p，内容为%d\n", kk.i, ptr2, ptr2->data.i);
	}
	else
	{
		printf("没有元素%d\n", kk.i);
	}

	printf("\n");
	if (ListInsert(L, 3, k))
	{
		printf("插入成功\n");
		ListLength(L); // 链表的长度
		printf("遍历链表：");
		ListTraverse(L);
	}
	else
	{
		printf("插入失败\n");
	}

	printf("\n");
	if (ListDelete(L, 3, &k))
	{
		printf("删除成功\n");
		ListLength(L); // 链表的长度
		printf("遍历链表：");
		ListTraverse(L);
	}
	else
	{
		printf("删除失败\n");
	}
	return 0;
}