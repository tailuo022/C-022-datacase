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

Linklist InitList() // ��ʼ������(ͷ����Ԫ�س�ʼ��Ϊ 0 )
{
	Linklist L;
	L = (Linklist)malloc(sizeof(Lnode));
	L->data.i = 0;
	L->next = NULL;
	return L;
}

void ListEmpty(Linklist L) // �ж������Ƿ�Ϊ��
{
	assert(L);
	if (L->next)
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ��\n");
	}
}

void HeadAddList(Linklist L, int n) // ͷ�巨����������
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

void TailAddList(Linklist L, int n) // β�巨����������
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

void ListLength(Linklist L) // ����ĳ���
{
	assert(L);
	int count = 0;
	while (L->next)
	{
		L = L->next;
		count++;
	}
	printf("����ĳ���Ϊ��%d\n", count);
}

void ListTraverse(Linklist L) // ��������
{
	assert(L);
	while (L->next)
	{
		L = L->next;
		printf("%d ", L->data.i);
	}
	printf("\n");
}

void DestroyList(Linklist L) // ��������
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

void ClearList(Linklist L) // �������
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

void GetElem(Linklist L, int i, Elem* e) // ��ȡ�����еĵ� i ��Ԫ��
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
		printf("û�е�%d��Ԫ��\n", i);
		return;
	}
	*e = p->data;
}

int LocateElemSite(Linklist L, Elem e) // ���������е�ָ��Ԫ�أ�����Ԫ��λ��
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

Lnode* LocateElemPtr(Linklist L, Elem e) // ���������е�ָ��Ԫ�أ�����Ԫ��ָ��
{
	assert(L);
	Lnode* p = L->next;
	while (p && (p->data.i != e.i))
	{
		p = p->next;
	}
	return p;
}

int ListInsert(Linklist L, int i, Elem e) // �ڵ�i��λ�ò���Ԫ��e
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



int ListDelete(Linklist L, int i, Elem* e) // ɾ����i��Ԫ��
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
	Linklist L;  // ��������
	L = InitList();// ��ʼ������
	Lnode* p;// ������
	p = L; // p ָ��ͷ���
	ListEmpty(L); // �ж������Ƿ�Ϊ��
	printf("��������\n"); // 1 3 5 7 9 2 4 6 8 10 
	printf("����������ĳ��ȣ�");
	int n;
	scanf_s("%d", &n);
	printf("�����������Ԫ�أ�");
	//HeadAddList(L, n); // ͷ�巨����������
	TailAddList(L, n); // β�巨����������
	ListLength(L); // ����ĳ���
	printf("��������");
	ListTraverse(L); // ��������

	printf("\n");
	Elem k;
	GetElem(L, 3, &k);
	Elem l;
	GetElem(L, 100, &l);
	printf("������Ԫ��Ϊ%d\n", k.i);

	printf("\n");
	if (LocateElemSite(L, k))
	{
		printf("Ԫ��%d��λ��Ϊ��%d\n", k.i, LocateElemSite(L, k));
	}
	else
	{
		printf("û��Ԫ��%d\n", k.i);
	}
	Elem kk = { 99 };
	if (LocateElemSite(L, kk))
	{
		printf("Ԫ��%d��λ��Ϊ��%d\n", kk.i, LocateElemSite(L, kk));
	}
	else
	{
		printf("û��Ԫ��%d\n", kk.i);
	}
	Lnode* ptr1 = LocateElemPtr(L, k);
	if (ptr1)
	{
		printf("Ԫ��%d��ָ��Ϊ��%p������Ϊ%d\n", k.i, ptr1, ptr1->data.i);
	}
	else
	{
		printf("û��Ԫ��%d\n", k.i);
	}
	Lnode* ptr2 = LocateElemPtr(L, kk);
	if (ptr2)
	{
		printf("Ԫ��%d��ָ��Ϊ��%p������Ϊ%d\n", kk.i, ptr2, ptr2->data.i);
	}
	else
	{
		printf("û��Ԫ��%d\n", kk.i);
	}

	printf("\n");
	if (ListInsert(L, 3, k))
	{
		printf("����ɹ�\n");
		ListLength(L); // ����ĳ���
		printf("��������");
		ListTraverse(L);
	}
	else
	{
		printf("����ʧ��\n");
	}

	printf("\n");
	if (ListDelete(L, 3, &k))
	{
		printf("ɾ���ɹ�\n");
		ListLength(L); // ����ĳ���
		printf("��������");
		ListTraverse(L);
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
	return 0;
}