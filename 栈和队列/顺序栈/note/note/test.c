#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 

typedef struct Elemtype // 栈的元素类型
{
	int i;
}Elem;

typedef struct SqStack  // 栈的结构体
{
	Elem* top;
	Elem* base;
	int stacksize;
}SqStack;

void InitStack(SqStack* S) // 初始化栈
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

void StackEmpty(SqStack* S) // 判断栈是否为空
{
	if (S->top == S->base)
	{
		printf("栈为空\n");
	}
	else
	{
		printf("栈不为空\n");
	}
}

void DestoryStack(SqStack* S) // 销毁栈
{
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;
}

void ClearStack(SqStack* S) // 清空栈
{
	S->top = S->base;
}

void Push(SqStack* S, Elem e) // 入栈
{
	if (S->top - S->base >= S->stacksize)
	{
		printf("栈满\n");
		return;
	}
	*S->top++ = e;
}

void Pop(SqStack* S, Elem* e) // 出栈
{
	if (S->top == S->base)
	{
		printf("栈为空\n");
		return;
	}
	*e = *--S->top;
}

int StackLength(SqStack* S) // 求栈长
{
	return S->top - S->base;
}

void GetTop(SqStack* S, Elem* e) // 取栈顶元素
{
	if (S->top == S->base)
	{
		printf("栈为空\n");
		return;
	}
	*e = *--S->top;
	S->top++;
}

int main() 
{
	SqStack S;
	InitStack(&S); // 初始化栈
	StackEmpty(&S); // 判断栈是否为空
	// 栈为空
	Elem e1 = { 0 };
	Elem e2 = { 1 };
	Elem e3 = { 2 };
	Elem e4;
	Elem e5;
	Push(&S, e1);
	Push(&S, e2);
	Push(&S, e3);
	printf("栈长为%d\n", StackLength(&S));
	// 栈长为3
	GetTop(&S, &e4);
	printf("栈的Top元素为%d\n", e4.i);
	// 栈的Top元素为2
	printf("栈长为%d\n", StackLength(&S));
	// 栈长为3
	Pop(&S, &e5);
	printf("Pop栈的结果为元素%d\n", e5.i);
	// Pop栈的结果为元素2
	printf("栈长为%d\n", StackLength(&S));
	// 栈长为2
	ClearStack(&S);
	StackEmpty(&S);
	printf("栈长为%d\n", StackLength(&S));
	// 栈为空
	// 栈长为0
	DestoryStack(&S);
	return 0;
}