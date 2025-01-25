#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Elemtype // 数据元素类型
{
	int i;
}Elem;

typedef struct StackNode // 栈结点类型
{
	Elem data;
	struct StackNode* next;
}StackNode, *LinkStack;

void InitStack(LinkStack S) // 初始化栈
{
	S->next = NULL;
}

void DestoryStack(LinkStack* S) // 销毁栈
{
	StackNode* p;
	while ((*S)->next)
	{
		p = *S;
		*S = (*S)->next;
		free(p);
	}
}

void ClearStack(LinkStack* S) // 清空栈
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

void Push(LinkStack* S, Elem e)// 入栈
{
	StackNode* p;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;
	p->next = *S;
	*S = p;
}

void Pop(LinkStack* S, Elem* e) // 出栈
{
	StackNode* p;
	p = *S;
	*S = (*S)->next;
	*e = p->data;
	free(p);
}

void GetTop(LinkStack S, Elem* e) // 取栈顶元素
{
	*e = S->data;
}

int StackLength(LinkStack S) // 求栈长
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

void StackEmpty(LinkStack S) // 判断栈是否为空
{
	if (S->next == NULL)
	{
		printf("栈为空\n");
	}
	else
	{
		printf("栈不为空\n");
	}
}

int main()
{
	LinkStack S; // 定义一个栈
	S = (LinkStack)malloc(sizeof(LinkStack));
	InitStack(S); // 初始化栈
	StackEmpty(S); // 判断栈是否为空
	// 栈为空
	Elem e1 = { 0 };
	Elem e2 = { 1 };
	Elem e3 = { 2 };
	printf("栈长：%d\n", StackLength(S));    
	// 栈长：0
	Push(&S, e1);
	Push(&S, e2);
	Push(&S, e3);
	printf("栈长：%d\n", StackLength(S));
	// 栈长：3
	Elem e4;
	Pop(&S, &e4);
	printf("出栈元素：%d\n", e4.i);
	// 出栈元素：2
	printf("栈长：%d\n", StackLength(S));
	// 栈长：2
	Elem e5;
	GetTop(S, &e5);
	printf("栈顶元素：%d\n", e5.i);
	// 栈顶元素：1
	ClearStack(&S);
	printf("栈长：%d\n", StackLength(S));
	// 栈长：0
	DestoryStack(&S);
	return 0;
}