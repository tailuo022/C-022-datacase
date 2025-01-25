#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 

typedef struct Elemtype // ջ��Ԫ������
{
	int i;
}Elem;

typedef struct SqStack  // ջ�Ľṹ��
{
	Elem* top;
	Elem* base;
	int stacksize;
}SqStack;

void InitStack(SqStack* S) // ��ʼ��ջ
{
	S->base = (Elem*)malloc(MAXSIZE * sizeof(Elem));
	if (!S->base)
	{
		perror;
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return S;
}

void StackEmpty(SqStack* S) // �ж�ջ�Ƿ�Ϊ��
{
	if (S->top == S->base)
	{
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}
}

void DestoryStack(SqStack* S) // ����ջ
{
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;
}

void ClearStack(SqStack* S) // ���ջ
{
	S->top = S->base;
}

void Push(SqStack* S, Elem e) // ��ջ
{
	if (S->top - S->base >= S->stacksize)
	{
		printf("ջ��\n");
		return;
	}
	*S->top++ = e;
}

void Pop(SqStack* S, Elem* e) // ��ջ
{
	if (S->top == S->base)
	{
		printf("ջΪ��\n");
		return;
	}
	*e = *--S->top;
}

int StackLength(SqStack* S) // ��ջ��
{
	return S->top - S->base;
}

void GetTop(SqStack* S, Elem* e) // ȡջ��Ԫ��
{
	if (S->top == S->base)
	{
		printf("ջΪ��\n");
		return;
	}
	*e = *--S->top;
	S->top++;
}

int main() 
{
	SqStack S;
	InitStack(&S); // ��ʼ��ջ
	StackEmpty(&S); // �ж�ջ�Ƿ�Ϊ��
	// ջΪ��
	Elem e1 = { 0 };
	Elem e2 = { 1 };
	Elem e3 = { 2 };
	Elem e4;
	Elem e5;
	Push(&S, e1);
	Push(&S, e2);
	Push(&S, e3);
	printf("ջ��Ϊ%d\n", StackLength(&S));
	// ջ��Ϊ3
	GetTop(&S, &e4);
	printf("ջ��TopԪ��Ϊ%d\n", e4.i);
	// ջ��TopԪ��Ϊ2
	printf("ջ��Ϊ%d\n", StackLength(&S));
	// ջ��Ϊ3
	Pop(&S, &e5);
	printf("Popջ�Ľ��ΪԪ��%d\n", e5.i);
	// Popջ�Ľ��ΪԪ��2
	printf("ջ��Ϊ%d\n", StackLength(&S));
	// ջ��Ϊ2
	ClearStack(&S);
	StackEmpty(&S);
	printf("ջ��Ϊ%d\n", StackLength(&S));
	// ջΪ��
	// ջ��Ϊ0
	DestoryStack(&S);
	return 0;
}