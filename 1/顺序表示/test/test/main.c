#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 100

typedef struct ElemType // �����������
{
	int i;
}Elem;

typedef struct LNode // ����˳���
{
	Elem elem[SIZE];
	int length;
}Sqlist;

void InitList(Sqlist* L) // ��ʼ��˳���
{
	L->length = 0;
}

void DestroyList(Sqlist* L) // ����˳���
{
	L->length = 0;
}

void ClearList(Sqlist* L) //���˳���
{
	L->length = 0;
}

void ListEmpty(Sqlist* L) // �ж�˳����Ƿ�Ϊ��
{
	if (L->length == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		printf("˳���Ϊ��\n");
	}
}

int ListLength(Sqlist* L) // ����˳���ĳ���
{
	return L->length;
}

Elem GetElem(Sqlist* L, int i) // ����˳����е�i��Ԫ��
{
	return L->elem[i];
}

int LocateElem(Sqlist* L, Elem e) // ����˳����һ����e��ȵ�Ԫ�ص�λ��
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

Elem PriorElem(Sqlist* L, Elem cur_e) // ����cur_e��ǰ��
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem->i == cur_e.i)
		{
			return L->elem[i - 1];
		}
	}
}

Elem NextElem(Sqlist* L, Elem cur_e) // ����cur_e�ĺ��
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->elem->i == cur_e.i)
		{
			return L->elem[i + 1];
		}
	}
}

void ListInsert(Sqlist* L, int i, Elem e) // �ڵ�i��λ�ò���Ԫ��e
{
	if (i < 0 || i > L->length)
	{
		printf("����λ�ò��Ϸ�\n");
	}
	if (L->length == SIZE)
	{
		printf("˳�������\n");
	}
	for (int j = L->length; j > i;j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i] = e;
}

void ListDelete(Sqlist* L, int i, Elem* e) // ɾ����i��Ԫ��
{
	if (i < 0 || i > L->length)
	{
		printf("ɾ����λ�ò��Ϸ�\n");
	}
	*e = L->elem[i];
	for (int j = i; j < L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
}

void ListTraverse(Sqlist* L) // ����˳���
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->elem[i].i);
	}
	printf("\n");
}

void ListUnion(Sqlist* La, Sqlist* Lb) // �ϲ�����˳���
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

void ListMerge(Sqlist* La, Sqlist* Lb, Sqlist* Lc) // �ϲ����������
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

void ListReverse(Sqlist* L) // ����˳���
{
	Elem type;
	for (int i = 0; i < L->length / 2; i++)
	{
		type = L->elem[i];
		L->elem[i] = L->elem[L->length - i - 1];
		L->elem[L->length - i - 1] = type;
	}
}

void ListSort(Sqlist* L) // ��˳����������
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

void ListDeleteSame(Sqlist* L) // ɾ��˳������ظ���Ԫ�� -> ����һ��
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

void ListDeleteSame2(Sqlist* L) // ɾ��˳������ظ���Ԫ�� -> ������
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