#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Elemtype // ������
{
	int i;
}Elem;

typedef struct Lnode // ����ѭ������
{
	Elem data;
	struct Lnode* next;

}Lnode, * Linklist;

Linklist InitList() // ��ʼ������ѭ������
{
	Linklist L;
	L = (Linklist)malloc(sizeof(Linklist));
	if (L == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return NULL;
	}
	L->data.i = 999;
	L->next = NULL;
	return L;
}

typedef struct DulNode // ˫��ѭ������
{
	Elem data;
	struct DulNode* prior, * next;
}DulNode, *DulLinklist;

DulLinklist InitDulList() // ��ʼ��˫��ѭ������
{
	DulLinklist L;
	L = (DulLinklist)malloc(sizeof(DulLinklist));
	if (L == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return NULL;
	}
	L->data.i = 999;
	L->next = L;
	L->prior = L;
	return L;
}

void InsertDulList(DulLinklist L, int i, Elem e) // ˫��ѭ������Ĳ���
{
	assert(L);
	DulNode* p;
	p = (DulNode*)malloc(sizeof(DulNode));
	p->data = e;
	for (int j = 1; j < i - 1; j++)
	{
		L = L->next;
	}
	p->next = L->next;
	L->next->prior = p;
	L->next = p;
	p->prior = L;
}

void DeleteDullList(DulLinklist L, int i, Elem* e) // ˫��ѭ�������ɾ��
{
	assert(L);
	DulNode* p;
	p = (DulNode*)malloc(sizeof(DulNode));
	for (int j = 1; j < i - 1; j++)
	{
		L = L->next;
	}
	p = L->next;
	L->next = p->next;
	p->next->prior = L;
	*e = p->data;
	free(p);
}

void GetDulList(DulLinklist L, int i, Elem* e) // ����˫��ѭ�������е�i��λ�õ�Ԫ��
{
	assert(L);
	for (int j = 1; j < i - 1; j++)
	{
		L = L->next;
	}
	*e = L->next->data;
}

void ChangeDulList(DulLinklist L, int i, Elem e) // �޸�˫��ѭ�������е�i��λ�õ�Ԫ��
{
	assert(L);
	for (int j = 1; j < i - 1; j++)
	{
		L = L->next;
	}
	L->next->data = e;
}

int main()
{
	// ����ѭ������
	Linklist L;
	L = InitList();
	Lnode* p = L;
	for (int i = 0; i < 10; i++) // β�巨
	{
		Lnode* q = (Lnode*)malloc(sizeof(Lnode));
		q->data.i = i;
		q->next = p->next;
		p->next = q;
		p = q;
	}
	Lnode* q = p; // ��β��㸳ֵ��q
	q->next = L; // β���ָ��ͷ���
	p = L; // ��ͷ��㸳ֵ��p
	L = L->next; // ͷ���ָ���һ�����
	printf("%d\n", q->next->next->data.i);
	// 0 
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", p->data.i);
		p = p->next;
	}
	// 999 0 1 2 3 4 5 6 7 8 9 
	printf("\n\n");


	// ˫��ѭ������
	DulLinklist LL;
	LL = InitDulList();
	DulNode* pp = LL;
	for (int i = 0; i < 10; i++) // β�巨
	{
		DulNode* qq = (DulNode*)malloc(sizeof(DulNode));
		qq->data.i = i;
		qq->next = pp->next;
		pp->next = qq;
		qq->prior = pp;
		pp = qq;
	}
	DulNode* qq = pp; // ��β��㸳ֵ��q
	qq->next = LL; // β���ָ��ͷ���
	LL->prior = qq; // ͷ���ָ��β���
	pp = LL; // ��ͷ��㸳ֵ��p
	LL = LL->next; // ͷ���ָ���һ�����
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", pp->data.i);
		pp = pp->next;
	}
	// 999 0 1 2 3 4 5 6 7 8 9 
	printf("\n");
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", qq->data.i);
		qq = qq->prior;
	}
	// 9 8 7 6 5 4 3 2 1 0 999



	printf("\n\n");
	Elem e1 = { 22 };
	InsertDulList(LL, 5, e1);
	for (int i = 0; i <= 11; i++)
	{
		printf("%d ", pp->data.i);
		pp = pp->next;
	}
	// 999 0 1 2 3 22 4 5 6 7 8 9 
	printf("\n");
	Elem e2;
	DeleteDullList(LL, 5, &e2);
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", pp->data.i);
		pp = pp->next;
	}
	printf("\n%d\n", e2.i);
	// 999 0 1 2 3 4 5 6 7 8 9
	// 22
	Elem e3;
	GetDulList(LL, 5, &e3);
	printf("%d\n", e3.i);
	// 4
	Elem e4 = { 999 };
	ChangeDulList(LL, 5, e4);
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", pp->data.i);
		pp = pp->next;
	}
	// 999 0 1 2 3 999 5 6 7 8 9
	return 0;
}