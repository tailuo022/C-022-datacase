#define  _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define MAXQSIZE 6

typedef struct // 队列元素类型
{
	int i;
}QElem;

typedef struct // 循环队列
{
	QElem* base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue* Q) // 初始化队列
{
	Q->base = (QElem*)malloc(MAXQSIZE * sizeof(QElem));
	if (!Q->base) perror;
	Q->front = Q->rear = 0;
}

int QueueEmpty(SqQueue* Q) // 判断队列是否为空
{
	if (Q->front == Q->rear) return 1;
	else return 0;
}

int QueueLength(SqQueue* Q) // 返回队列长度
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}
 
void QueueTraverse(SqQueue* Q) // 遍历队列
{
	if (QueueEmpty(Q)) return;
	int i = Q->front;
	while (i != Q->rear)
	{
		printf("%d ", Q->base[i].i);
		i = (i + 1) % MAXQSIZE;
	}
	printf("\n");
}

void EnQueue(SqQueue* Q, QElem e) // 入队
{
	if (QueueLength == (MAXQSIZE - 1)) return;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
}

void DeQueue(SqQueue* Q, QElem* e) // 出队
{
	if (QueueEmpty(Q)) return;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
}

void GetHead(SqQueue* Q, QElem* e) // 获取队头元素
{
	if (QueueEmpty(Q)) return;
	*e = Q->base[Q->front];
}

void ClearQueue(SqQueue* Q) // 清空队列
{
	Q->front = Q->rear = 0;
}

void DestroyQueue(SqQueue* Q) // 销毁队列
{
	free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0;
}
int main()
{
	SqQueue Q;
	InitQueue(&Q); // 初始化队列
	if (QueueEmpty(&Q)) // 判断队列是否为空
		printf("队列为空\n");
	else
		printf("队列不为空\n");
	// 队列为空
	QElem e1 = { 0 };
	QElem e2 = { 1 };
	QElem e3 = { 2 };
	QElem e4 = { 3 };
	QElem e5 = { 4 };
	EnQueue(&Q, e1); // 入队
	EnQueue(&Q, e2);
	EnQueue(&Q, e3);
	EnQueue(&Q, e4);
	EnQueue(&Q, e5);
	QueueTraverse(&Q); // 遍历队列
	// 0 1 2 3 4
	if (QueueLength(&Q) == MAXQSIZE - 1) // 返回队列长度
		printf("队列已满\n");
	else
		printf("队列未满\n");
	// 队列已满

	QElem e11;
	GetHead(&Q, &e11); // 获取队头元素
	printf("队头元素为：%d\n", e11.i);
	// 队头元素为：0
	if (QueueLength(&Q) == MAXQSIZE - 1) // 返回队列长度
		printf("队列已满\n");
	else
		printf("队列未满\n");
	// 队列已满

	QElem E1;
	QElem E2;
	DeQueue(&Q, &E1); // 出队
	DeQueue(&Q, &E2);
	printf("出队元素为：%d %d\n", E1.i, E2.i);
	// 出队元素为：0 1
	printf("队列长度为：%d\n", QueueLength(&Q)); // 返回队列长度
	// 队列长度为：3
	QueueTraverse(&Q); // 遍历队列
	// 2 3 4

	ClearQueue(&Q); // 清空队列
	if (QueueEmpty(&Q)) // 判断队列是否为空
		printf("队列为空\n");
	else
		printf("队列不为空\n");
	// 队列为空
	printf("队列长度为：%d\n", QueueLength(&Q)); // 返回队列长度
	// 队列长度为：0
	DestroyQueue(&Q); // 销毁队列

	return 0;
}