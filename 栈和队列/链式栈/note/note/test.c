#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Elemtype // ����Ԫ������
{
	int i;
}Elem;

typedef struct StackNode // ջ�������
{
	Elem data;
	struct StackNode* next;
}StackNode, *LinkStack;

void InitStack(LinkStack S) // ��ʼ��ջ
{
	S->next = NULL;
}

void DestoryStack(LinkStack* S) // ����ջ
{
	StackNode* p;
	while ((*S)->next)
	{
		p = *S;
		*S = (*S)->next;
		free(p);
	}
}

void ClearStack(LinkStack* S) // ���ջ
{
	StackNode* p, * q;
	p = (*S)->next;
	while (p->next)
	{
		q = p;
		p = p->next;
		free(q);
	}
	(*S)->next = NULL;
}

void Push(LinkStack* S, Elem e)// ��ջ
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;
	p->next = *S;
	*S = p;
}

void Pop(LinkStack* S, Elem* e) // ��ջ
{
	StackNode* p;
	p = *S;
	*S = (*S)->next;
	*e = p->data;
	free(p);
}

void GetTop(LinkStack S, Elem* e) // ȡջ��Ԫ��
{
	*e = S->data;
}

int StackLength(LinkStack S) // ��ջ��
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p = S;
	int count = 0;
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return count;
}

void StackEmpty(LinkStack S) // �ж�ջ�Ƿ�Ϊ��
{
	if (S->next == NULL)
	{
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}
}

int main()
{
	LinkStack S; // ����һ��ջ
	S = (LinkStack)malloc(sizeof(LinkStack));
	InitStack(S); // ��ʼ��ջ
	StackEmpty(S); // �ж�ջ�Ƿ�Ϊ��
	// ջΪ��
	Elem e1 = { 0 };
	Elem e2 = { 1 };
	Elem e3 = { 2 };
	printf("ջ����%d\n", StackLength(S));    
	// ջ����0
	Push(&S, e1);
	Push(&S, e2);
	Push(&S, e3);
	printf("ջ����%d\n", StackLength(S));
	// ջ����3
	Elem e4;
	Pop(&S, &e4);
	printf("��ջԪ�أ�%d\n", e4.i);
	// ��ջԪ�أ�2
	printf("ջ����%d\n", StackLength(S));
	// ջ����2
	Elem e5;
	GetTop(S, &e5);
	printf("ջ��Ԫ�أ�%d\n", e5.i);
	// ջ��Ԫ�أ�1
	ClearStack(&S);
	printf("ջ����%d\n", StackLength(S));
	// ջ����0
	DestoryStack(&S);
	return 0;
}