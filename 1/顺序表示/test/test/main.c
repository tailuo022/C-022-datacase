#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 100

typedef struct ElemType // 定义变量类型
{
	int i;
}Elem;

typedef struct LNode // 定义顺序表
{
	Elem elem[SIZE];
	int length;
}Sqlist;

void InitList(Sqlist* L) // 初始化顺序表
{
	L->length = 0;
}

void DestroyList(Sqlist* L) // 销毁顺序表
{
	L->length = 0;
}

void ClearList(Sqlist* L) //清空顺序表
{
	L->length = 0;
}

void ListEmpty(Sqlist* L) // 判断顺序表是否为空
{
	if (L->length == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		printf("顺序表不为空\n");
	}
}

int ListLength(Sqlist* L) // 返回顺序表的长度
{
	return L->length;
}

Elem GetElem(Sqlist* L, int i) // 返回顺序表中第i个元素
{
	return L->elem[i];
}

int LocateElem(Sqlist* L, Elem e) // 返回顺序表第一个与e相等的元素的位序
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem[i].i == e.i)
		{
			return i;
		}
	}
	return 0;
}

Elem PriorElem(Sqlist* L, Elem cur_e) // 返回cur_e的前驱
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem->i == cur_e.i)
		{
			return L->elem[i - 1];
		}
	}
}

Elem NextElem(Sqlist* L, Elem cur_e) // 返回cur_e的后继
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem->i == cur_e.i)
		{
			return L->elem[i + 1];
		}
	}
}

void ListInsert(Sqlist* L, int i, Elem e) // 在第i个位置插入元素e
{
	if (i < 0 || i > L->length)
	{
		printf("插入位置不合法\n");
	}
	if (L->length == SIZE)
	{
		printf("顺序表已满\n");
	}
	for (int j = L->length; j > i;j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i] = e;
}

void ListDelete(Sqlist* L, int i, Elem* e) // 删除第i个元素
{
	if (i < 0 || i > L->length)
	{
		printf("删除的位置不合法\n");
	}
	*e = L->elem[i];
	for (int j = i; j < L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
}

void ListTraverse(Sqlist* L) // 遍历顺序表
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->elem[i].i);
	}
	printf("\n");
}

void ListUnion(Sqlist* La, Sqlist* Lb) // 合并两个顺序表
{
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
	int i = 0, j = 0, k = 0;
	while (i < La->length && j < Lb->length)
	{
		if (La->elem[i].i < Lb->elem[i].i)
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
		Lc->elem[k++] = La->elem[j++];
	}
}

void ListReverse(Sqlist* L) // 逆置顺序表
{
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

int main()
{
	 
	return 0;
}