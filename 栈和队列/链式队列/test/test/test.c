#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	
#include <stdlib.h>

typedef struct QElem // ����Ԫ������
{
	int i;
}QElem;


typedef struct QNode // ���н������
{
	QElem data;
	struct QNode* next;
}QNode, *Queueptr;

typedef struct LinkQueue // ��������
{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

void InitQnode(LinkQueue* Q) // ��ʼ������
{
	Q->front = Q->rear = 
		(Queueptr)malloc(sizeof(QNode));
	if (!Q->front) return;
	Q->front->data.i = 999;
	Q->front->next = NULL;
}

int QnodeEmpty(LinkQueue* Q) // �ж϶����Ƿ�Ϊ��
{
	return Q->front == Q->rear;
}

void EnQnode(LinkQueue* Q, QElem e) // ���
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p) return;
	p->data = e;
	Q->rear->next = p;
	Q->rear = p;
	p->next = NULL;
}

void DeQnode(LinkQueue* Q, QElem* e) // ����
{
	if (QnodeEmpty(Q)) return;
	QNode* p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
}

void GetHeadQnode(LinkQueue* Q, QElem* e) // ��ȡ��ͷԪ��
{
	if (QnodeEmpty(Q)) return;
	*e = Q->front->next->data;
}

void GetBackQnode(LinkQueue* Q, QElem* e) // ��ȡ��βԪ��
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

void ClearQnode(LinkQueue* Q) // ��ն���
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

void DestroyQnode(LinkQueue* Q) // ���ٶ���
{
	ClearQnode(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
}

int main()
{
	LinkQueue Q;
	InitQnode(&Q); // ��ʼ������
	printf("%d\n", QnodeEmpty(&Q)); // �ж϶����Ƿ�Ϊ��
	// 1 
	printf("���г���Ϊ��%d\n", QnodeLength(&Q)); // ��ȡ���г���
	// ���г���Ϊ��0

	QElem e1 = { 0 };
	QElem e2 = { 1 };
	QElem e3 = { 2 };	
	EnQnode(&Q, e1); // ���
	EnQnode(&Q, e2);
	EnQnode(&Q, e3);
	printf("���г���Ϊ��%d\n", QnodeLength(&Q)); // ��ȡ���г���
	// ���г���Ϊ��3

	QElem e;
	GetHeadQnode(&Q, &e); // ��ȡ��ͷԪ��
	printf("��ͷԪ��Ϊ��%d\n", e.i);
	// ��ͷԪ��Ϊ��0
	GetBackQnode(&Q, &e); // ��ȡ��βԪ��
	printf("��βԪ��Ϊ��%d\n", e.i);
	// ��βԪ��Ϊ��2
	printf("���г���Ϊ��%d\n", QnodeLength(&Q)); // ��ȡ���г���
	// ���г���Ϊ��3

	QElem E1;
	QElem E2;
	DeQnode(&Q, &E1); // ����
	DeQnode(&Q, &E2);
	printf("���ӵ�Ԫ��Ϊ %d,%d\n", E1.i, E2.i); 
	// ���ӵ�Ԫ��Ϊ 0,1
	printf("���г���Ϊ��%d\n", QnodeLength(&Q)); // ��ȡ���г���
	// ���г���Ϊ��1
	GetHeadQnode(&Q, &e); // ��ȡ��ͷԪ��
	printf("��ͷԪ��Ϊ��%d\n", e.i);
	// ��ͷԪ��Ϊ��2
	GetBackQnode(&Q, &e); // ��ȡ��βԪ��
	printf("��βԪ��Ϊ��%d\n", e.i);
	// ��βԪ��Ϊ��2

	ClearQnode(&Q); // ��ն���
	printf("���г���Ϊ��%d\n", QnodeLength(&Q)); // ��ȡ���г���
	// ���г���Ϊ��0
	printf("%d\n", QnodeEmpty(&Q)); // �ж϶����Ƿ�Ϊ��
	// 1

	DestroyQnode(&Q); // ���ٶ���
	return 0;
}