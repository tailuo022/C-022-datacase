#define  _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define MAXQSIZE 6

typedef struct // ����Ԫ������
{
	int i;
}QElem;

typedef struct // ѭ������
{
	QElem* base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue* Q) // ��ʼ������
{
	Q->base = (QElem*)malloc(MAXQSIZE * sizeof(QElem));
	if (!Q->base) perror;
	Q->front = Q->rear = 0;
}

int QueueEmpty(SqQueue* Q) // �ж϶����Ƿ�Ϊ��
{
	if (Q->front == Q->rear) return 1;
	else return 0;
}

int QueueLength(SqQueue* Q) // ���ض��г���
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}
 
void QueueTraverse(SqQueue* Q) // ��������
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

void EnQueue(SqQueue* Q, QElem e) // ���
{
	if (QueueLength == (MAXQSIZE - 1)) return;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
}

void DeQueue(SqQueue* Q, QElem* e) // ����
{
	if (QueueEmpty(Q)) return;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
}

void GetHead(SqQueue* Q, QElem* e) // ��ȡ��ͷԪ��
{
	if (QueueEmpty(Q)) return;
	*e = Q->base[Q->front];
}

void ClearQueue(SqQueue* Q) // ��ն���
{
	Q->front = Q->rear = 0;
}

void DestroyQueue(SqQueue* Q) // ���ٶ���
{
	free(Q->base);
	Q->base = NULL;
	Q->front = Q->rear = 0;
}
int main()
{
	SqQueue Q;
	InitQueue(&Q); // ��ʼ������
	if (QueueEmpty(&Q)) // �ж϶����Ƿ�Ϊ��
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");
	// ����Ϊ��
	QElem e1 = { 0 };
	QElem e2 = { 1 };
	QElem e3 = { 2 };
	QElem e4 = { 3 };
	QElem e5 = { 4 };
	EnQueue(&Q, e1); // ���
	EnQueue(&Q, e2);
	EnQueue(&Q, e3);
	EnQueue(&Q, e4);
	EnQueue(&Q, e5);
	QueueTraverse(&Q); // ��������
	// 0 1 2 3 4
	if (QueueLength(&Q) == MAXQSIZE - 1) // ���ض��г���
		printf("��������\n");
	else
		printf("����δ��\n");
	// ��������

	QElem e11;
	GetHead(&Q, &e11); // ��ȡ��ͷԪ��
	printf("��ͷԪ��Ϊ��%d\n", e11.i);
	// ��ͷԪ��Ϊ��0
	if (QueueLength(&Q) == MAXQSIZE - 1) // ���ض��г���
		printf("��������\n");
	else
		printf("����δ��\n");
	// ��������

	QElem E1;
	QElem E2;
	DeQueue(&Q, &E1); // ����
	DeQueue(&Q, &E2);
	printf("����Ԫ��Ϊ��%d %d\n", E1.i, E2.i);
	// ����Ԫ��Ϊ��0 1
	printf("���г���Ϊ��%d\n", QueueLength(&Q)); // ���ض��г���
	// ���г���Ϊ��3
	QueueTraverse(&Q); // ��������
	// 2 3 4

	ClearQueue(&Q); // ��ն���
	if (QueueEmpty(&Q)) // �ж϶����Ƿ�Ϊ��
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");
	// ����Ϊ��
	printf("���г���Ϊ��%d\n", QueueLength(&Q)); // ���ض��г���
	// ���г���Ϊ��0
	DestroyQueue(&Q); // ���ٶ���

	return 0;
}