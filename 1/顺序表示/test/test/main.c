#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE 100

typedef struct ElemType // 定义变量类型
{
	int i;
}Elem;

typedef struct LNode // 定义顺序表
{
	Elem *elem;
	int length;
}Sqlist;

void InitList(Sqlist* L) // 初始化顺序表
{
	assert(L);
	L->elem = NULL;
	L->length = 0;
}

void DestroyList(Sqlist* L) // 销毁顺序表
{
	assert(L);
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
}

void ClearList(Sqlist* L) //清空顺序表
{
	assert(L);
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
}

void ListEmpty(Sqlist* L) // 判断顺序表是否为空
{
	assert(L);
	if (L->length == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		printf("顺序表不为空\n");
	}
}

void AddElem(Sqlist* L) // 添加元素
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("顺序表已满\n");
		return;
	}
	scanf_s("%d", &L->elem[L->length].i);
	L->length++;
}

int ListLength(Sqlist* L) // 返回顺序表的长度
{
	assert(L);
	return L->length;
}

Elem GetElem(Sqlist* L, int i) // 返回顺序表中第i个元素
{
	assert(L);
	return L->elem[i - 1];
}

int LocateElem(Sqlist* L, Elem e) // 返回顺序表第一个与e相等的元素的位序
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i].i == e.i)
		{
			return i + 1;
		}
	}
	return 0;
}

Elem PriorElem(Sqlist* L, Elem cur_e) // 返回cur_e的前驱
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i].i == cur_e.i)
		{
			return L->elem[i - 1];
		}
	}
}

Elem NextElem(Sqlist* L, Elem cur_e) // 返回cur_e的后继
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i].i == cur_e.i)
		{
			return L->elem[i + 1];
		}
	}
}

void ListInsert(Sqlist* L, int i, Elem e) // 在第i个位置插入元素e
{
	assert(L);
	if (i < 0 || i > L->length)
	{
		printf("插入位置不合法\n");
	}
	if (L->length == SIZE)
	{
		printf("顺序表已满\n");
	}
	for (int j = L->length; j >= i;j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i - 1] = e;
	L->length++;
}

void ListDelete(Sqlist* L, int i, Elem* e) // 删除第i个元素
{
	assert(L);
	if (i < 0 || i > L->length)
	{
		printf("删除的位置不合法\n");
		return;
	}
	*e = L->elem[i];
	for (int j = i - 1; j < L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
}

void ListTraverse(Sqlist* L) // 遍历顺序表
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->elem[i].i);
	}
	printf("\n");
}

void ListUnion(Sqlist* La, Sqlist* Lb) // 合并两个顺序表
{
	assert(La&&Lb);
	for (int i = 0; i < Lb->length; i++)
	{
		if (LocateElem(La, Lb->elem[i]) == 0)
		{
			La->elem[La->length] = Lb->elem[i];
			La->length++;
		}
	}
}

void ListMerge(Sqlist* La, Sqlist* Lb, Sqlist* Lc) // 合并两个有序表
 {
	assert(La&&Lb&&Lc);
	int i = 0, j = 0, k = 0;
 	while (i < La->length && j < Lb->length)
	{
		if (La->elem[i].i <= Lb->elem[j].i)
		{
			Lc->elem[k++] = La->elem[i++];
		}
		else
		{
			Lc->elem[k++] = Lb->elem[j++];
		}
	}
	while (i < La->length)
	{
		Lc->elem[k++] = La->elem[i++];
	}
	while (j < Lb->length)
	{
		Lc->elem[k++] = Lb->elem[j++];
	}
	Lc->length = La->length + Lb->length;
}

void ListReverse(Sqlist* L) // 逆置顺序表
{
	assert(L);
	Elem type;
	for (int i = 0; i < L->length / 2; i++)
	{
		type = L->elem[i];
		L->elem[i] = L->elem[L->length - i - 1];
		L->elem[L->length - i - 1] = type;
	}
}

void ListSort(Sqlist* L) // 对顺序表进行排序
{
	assert(L);
	Elem type;
	for (int i = 0; i < L->length - 1; i++)
	{
		for (int j = 0; j < L->length - i - 1; j++)
		{
			if (L->elem[j].i > L->elem[j + 1].i)
			{
				type = L->elem[j];
				L->elem[j] = L->elem[j + 1];
				L->elem[j + 1] = type;
			}
		}
	}
}

void ListDeleteSame(Sqlist* L) // 删除顺序表中重复的元素 -> 保留一个
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		for (int j = i + 1; j < L->length; j++)
		{
			if (L->elem[i].i == L->elem[j].i)
			{
				for (int k = j; k < L->length - 1; k++)
				{
					L->elem[k] = L->elem[k + 1];
				}
				L->length--;
				j--;
			}
		}
	}
}

void ListDeleteSame2(Sqlist* L) // 删除顺序表中重复的元素 -> 不保留
{
	assert(L);
	int i, j;
	for (i = 0; i < L->length; i++)
	{
		for (j = i + 1; j < L->length; j++)
		{
			if (L->elem[i].i == L->elem[j].i)
			{
				break;
			}
		}
		if (j == L->length)
		{
			L->elem[L->length++] = L->elem[i];
		}
	}
}

void ListPushBack(Sqlist* L, Elem e) // 尾插
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("顺序表已满\n");
	}
	L->elem[L->length] = e;
	L->length++;
}

void ListPushFront(Sqlist* L, Elem e) // 头插
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("顺序表已满\n");
	}
	for (int i = L->length; i > 0; i--)
	{
		L->elem[i] = L->elem[i - 1];
	}
	L->elem[0] = e;
	L->length++;
}

int main()
{
	Sqlist L;
	InitList(&L);
	L.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	printf("请输入要添加的元素个数：");
	int n1 = 0;
	scanf_s("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		AddElem(&L);
	}

	ListEmpty(&L);
	ListTraverse(&L);
	printf("顺序表的长度为：%d\n", ListLength(&L));
	Elem i5 = GetElem(&L, 5);
	printf("返回第五个元素：%d\n", i5.i);
	Elem i = { 7 };
	printf("i(7)的位置：%d\n", LocateElem(&L, i));
	Elem i4 = PriorElem(&L, i5);
	printf("返回i5的前驱：%d\n", i4.i);
	Elem i6 = NextElem(&L, i5);
	printf("返回i5的后继：%d\n", i6.i);
	printf("在第三个位置插入 第五个元素 \n");
	ListInsert(&L, 3, i5);
	ListTraverse(&L);
	printf("顺序表的长度为：%d\n", ListLength(&L));
	printf("删除第三个元素\n");
	ListDelete(&L, 3, &i5);
	ListTraverse(&L);
	printf("顺序表的长度为：%d\n", ListLength(&L));
	printf("排序\n");
	ListSort(&L);
	ListTraverse(&L);
	printf("倒序\n");
	ListReverse(&L);
	ListTraverse(&L);
	printf("\n");

	Sqlist La;
	InitList(&La);
	La.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	printf("请输入要添加的元素个数：");
	int n2 = 0;
	scanf_s("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		AddElem(&La);
	}
	printf("合并两个顺序表\n");
	ListUnion(&L, &La);
	ListTraverse(&L);

	Sqlist Lb;
	InitList(&Lb);
	Lb.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	printf("请输入要添加的元素个数：");
	int n3 = 0;
	scanf_s("%d", &n3);
	for (int i = 0; i < n3; i++)
	{
		AddElem(&Lb);
	}

	Sqlist Lc;
	InitList(&Lc);
	Lc.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	ListSort(&Lb);
	ListSort(&La);
	printf("\n");
	printf("有序表的合并\n");
 	ListMerge(&La, &Lb, &Lc);
	ListTraverse(&Lc);

	printf("\nL表：");
	ListTraverse(&L);
	printf("头插法插入1：");
	Elem kk = { 1 };
	ListPushFront(&L, kk);
	ListTraverse(&L);
	printf("尾插法插入1：");
	Elem kkk = { 1 };
	ListPushBack(&L, kkk);
	ListTraverse(&L);

	return 0;
}