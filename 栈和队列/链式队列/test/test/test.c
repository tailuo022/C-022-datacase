#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	
#include <stdlib.h>

typedef struct QElem // 队列元素类型
{
	int i;
}QElem;


typedef struct QNode // 队列结点类型
{
	QElem data;
	struct QNode* next;
}QNode, *Queueptr;

typedef struct LinkQueue // 队列类型
{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

void InitQnode(LinkQueue* Q) // 初始化队列
{
	Q->front = Q->rear = 
		(Queueptr)malloc(sizeof(QNode));
	if (!Q->front) return;
	Q->front->data.i = 999;
	Q->front->next = NULL;
}

int QnodeEmpty(LinkQueue* Q) // 判断队列是否为空
{
	return Q->front == Q->rear;
}

void EnQnode(LinkQueue* Q, QElem e) // 入队
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p) return;
	p->data = e;
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
}

void DeQnode(LinkQueue* Q, QElem* e) // 出队
{
	if (QnodeEmpty(Q)) return;
	QNode* p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
}

void GetHeadQnode(LinkQueue* Q, QElem* e) // 获取队头元素
{
	if (QnodeEmpty(Q)) return;
	*e = Q->front->next->data;
}

void GetBackQnode(LinkQueue* Q, QElem* e) // 获取队尾元素
{
	if (QnodeEmpty(Q)) return;
	*e = Q->rear->data;
}

int QnodeLength(LinkQueue* Q)
{
	int count = 0;
	QNode* p = Q->front;
	while (Q->rear != p)
	{
		count++;
		p = p->next;
	}
	return count;
}

void ClearQnode(LinkQueue* Q) // 清空队列
{
	QNode* p = Q->front->next;
	QNode* q;
	Q->rear = Q->front;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

void DestroyQnode(LinkQueue* Q) // 销毁队列
{
	ClearQnode(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
}

int main()
{
	LinkQueue Q;
	InitQnode(&Q); // 初始化队列
	printf("%d\n", QnodeEmpty(&Q)); // 判断队列是否为空
	// 1 
	printf("队列长度为：%d\n", QnodeLength(&Q)); // 获取队列长度
	// 队列长度为：0

	QElem e1 = { 0 };
	QElem e2 = { 1 };
	QElem e3 = { 2 };	
	EnQnode(&Q, e1); // 入队
	EnQnode(&Q, e2);
	EnQnode(&Q, e3);
	printf("队列长度为：%d\n", QnodeLength(&Q)); // 获取队列长度
	// 队列长度为：3

	QElem e;
	GetHeadQnode(&Q, &e); // 获取队头元素
	printf("队头元素为：%d\n", e.i);
	// 队头元素为：0
	GetBackQnode(&Q, &e); // 获取队尾元素
	printf("队尾元素为：%d\n", e.i);
	// 队尾元素为：2
	printf("队列长度为：%d\n", QnodeLength(&Q)); // 获取队列长度
	// 队列长度为：3

	QElem E1;
	QElem E2;
	DeQnode(&Q, &E1); // 出队
	DeQnode(&Q, &E2);
	printf("出队的元素为 %d,%d\n", E1.i, E2.i); 
	// 出队的元素为 0,1
	printf("队列长度为：%d\n", QnodeLength(&Q)); // 获取队列长度
	// 队列长度为：1
	GetHeadQnode(&Q, &e); // 获取队头元素
	printf("队头元素为：%d\n", e.i);
	// 队头元素为：2
	GetBackQnode(&Q, &e); // 获取队尾元素
	printf("队尾元素为：%d\n", e.i);
	// 队尾元素为：2

	ClearQnode(&Q); // 清空队列
	printf("队列长度为：%d\n", QnodeLength(&Q)); // 获取队列长度
	// 队列长度为：0
	printf("%d\n", QnodeEmpty(&Q)); // 判断队列是否为空
	// 1

	DestroyQnode(&Q); // 销毁队列
	return 0;
}