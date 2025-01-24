#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE 100

typedef struct ElemType // �����������
{
	int i;
}Elem;

typedef struct LNode // ����˳���
{
	Elem *elem;
	int length;
}Sqlist;

void InitList(Sqlist* L) // ��ʼ��˳���
{
	assert(L);
	L->elem = NULL;
	L->length = 0;
}

void DestroyList(Sqlist* L) // ����˳���
{
	assert(L);
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
}

void ClearList(Sqlist* L) //���˳���
{
	assert(L);
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
}

void ListEmpty(Sqlist* L) // �ж�˳����Ƿ�Ϊ��
{
	assert(L);
	if (L->length == 0)
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		printf("˳���Ϊ��\n");
	}
}

void AddElem(Sqlist* L) // ���Ԫ��
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("˳�������\n");
		return;
	}
	scanf_s("%d", &L->elem[L->length].i);
	L->length++;
}

int ListLength(Sqlist* L) // ����˳���ĳ���
{
	assert(L);
	return L->length;
}

Elem GetElem(Sqlist* L, int i) // ����˳����е�i��Ԫ��
{
	assert(L);
	return L->elem[i - 1];
}

int LocateElem(Sqlist* L, Elem e) // ����˳����һ����e��ȵ�Ԫ�ص�λ��
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

Elem PriorElem(Sqlist* L, Elem cur_e) // ����cur_e��ǰ��
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

Elem NextElem(Sqlist* L, Elem cur_e) // ����cur_e�ĺ��
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

void ListInsert(Sqlist* L, int i, Elem e) // �ڵ�i��λ�ò���Ԫ��e
{
	assert(L);
	if (i < 0 || i > L->length)
	{
		printf("����λ�ò��Ϸ�\n");
	}
	if (L->length == SIZE)
	{
		printf("˳�������\n");
	}
	for (int j = L->length; j >= i;j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i - 1] = e;
	L->length++;
}

void ListDelete(Sqlist* L, int i, Elem* e) // ɾ����i��Ԫ��
{
	assert(L);
	if (i < 0 || i > L->length)
	{
		printf("ɾ����λ�ò��Ϸ�\n");
		return;
	}
	*e = L->elem[i];
	for (int j = i - 1; j < L->length; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
}

void ListTraverse(Sqlist* L) // ����˳���
{
	assert(L);
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->elem[i].i);
	}
	printf("\n");
}

void ListUnion(Sqlist* La, Sqlist* Lb) // �ϲ�����˳���
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

void ListMerge(Sqlist* La, Sqlist* Lb, Sqlist* Lc) // �ϲ����������
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

void ListReverse(Sqlist* L) // ����˳���
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

void ListSort(Sqlist* L) // ��˳����������
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

void ListDeleteSame(Sqlist* L) // ɾ��˳������ظ���Ԫ�� -> ����һ��
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

void ListDeleteSame2(Sqlist* L) // ɾ��˳������ظ���Ԫ�� -> ������
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

void ListPushBack(Sqlist* L, Elem e) // β��
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("˳�������\n");
	}
	L->elem[L->length] = e;
	L->length++;
}

void ListPushFront(Sqlist* L, Elem e) // ͷ��
{
	assert(L);
	if (L->length == SIZE)
	{
		printf("˳�������\n");
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
	printf("������Ҫ��ӵ�Ԫ�ظ�����");
	int n1 = 0;
	scanf_s("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		AddElem(&L);
	}

	ListEmpty(&L);
	ListTraverse(&L);
	printf("˳���ĳ���Ϊ��%d\n", ListLength(&L));
	Elem i5 = GetElem(&L, 5);
	printf("���ص����Ԫ�أ�%d\n", i5.i);
	Elem i = { 7 };
	printf("i(7)��λ�ã�%d\n", LocateElem(&L, i));
	Elem i4 = PriorElem(&L, i5);
	printf("����i5��ǰ����%d\n", i4.i);
	Elem i6 = NextElem(&L, i5);
	printf("����i5�ĺ�̣�%d\n", i6.i);
	printf("�ڵ�����λ�ò��� �����Ԫ�� \n");
	ListInsert(&L, 3, i5);
	ListTraverse(&L);
	printf("˳���ĳ���Ϊ��%d\n", ListLength(&L));
	printf("ɾ��������Ԫ��\n");
	ListDelete(&L, 3, &i5);
	ListTraverse(&L);
	printf("˳���ĳ���Ϊ��%d\n", ListLength(&L));
	printf("����\n");
	ListSort(&L);
	ListTraverse(&L);
	printf("����\n");
	ListReverse(&L);
	ListTraverse(&L);
	printf("\n");

	Sqlist La;
	InitList(&La);
	La.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	printf("������Ҫ��ӵ�Ԫ�ظ�����");
	int n2 = 0;
	scanf_s("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		AddElem(&La);
	}
	printf("�ϲ�����˳���\n");
	ListUnion(&L, &La);
	ListTraverse(&L);

	Sqlist Lb;
	InitList(&Lb);
	Lb.elem = (Elem*)malloc(SIZE * sizeof(Elem));
	printf("������Ҫ��ӵ�Ԫ�ظ�����");
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
	printf("�����ĺϲ�\n");
 	ListMerge(&La, &Lb, &Lc);
	ListTraverse(&Lc);

	printf("\nL��");
	ListTraverse(&L);
	printf("ͷ�巨����1��");
	Elem kk = { 1 };
	ListPushFront(&L, kk);
	ListTraverse(&L);
	printf("β�巨����1��");
	Elem kkk = { 1 };
	ListPushBack(&L, kkk);
	ListTraverse(&L);

	return 0;
}