#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSSIZE 100
#define MAXQSIZE 100

typedef char TElem, Elem; // ���ڵ����Ϣ����������

typedef struct BiNode { 
	TElem data;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree; //�������ڵ�Ķ���

typedef struct TriNode {
	TElem data;
	struct TriNode* lchild, * rchild, * parent;
}TriNode, *TriTree; //�������ڵ�Ķ���

typedef struct {
	BiNode* top;
	BiNode* base;
	int stackSize;
}Stack; //ջ�Ķ���

typedef struct {
	BiNode* base;
	int front;
	int rear;
}Queue; //���еĶ���

void InitStack(Stack* S) {
	S->base = (BiNode*)malloc(sizeof(BiNode) * MAXSSIZE);
	if (!S) {
		printf("ջ����ʧ��\n");
		return;
	}
    S->top = S->base;
	S->stackSize = MAXSSIZE;
} //ջ�ĳ�ʼ��

void Push(Stack* S, BiNode* T) {
	if (S->top - S->base == S->stackSize) {
		printf("ջ��\n");
		return;
	}
	*S->top++ = *T;
} //��ջ

void Pop(Stack* S, BiNode* T) {
	if (S->base == S->top) {
		printf("ջ��\n");
		return;
	}
	*T = *--S->top;
} //��ջ

int StackEmpty(Stack* S) {
	if (S->top == S->base) {
		return 1;
	}
	else {
		return 0;
	}
} //�ж�ջ��

void InitQueue(Queue* Q) {
	Q->base = (BiNode*)malloc(sizeof(BiNode) * MAXQSIZE);
	if (!Q) {
		return;
	}
	Q->front = Q->rear = 0;
} //��ʼ������

int QueueLength(Queue* Q) {
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
} //���ض��г���

void EnQueue(Queue* Q, BiNode T) {
	if (QueueLength(Q) == MAXQSIZE - 1) {
		return;
	}
	Q->base[Q->rear] = T;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
} //���

void DeQueue(Queue* Q, BiNode* T) {
	if (Q->rear == Q->front) {
		return;
	}
	*T = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
} //����

void InitBiTree(BiTree T) {
	if (!T) {
		return;
	}
	T->lchild = T->rchild = NULL;
} //��ʼ��������

BiNode* CreatBiTree(BiTree T) {
	if (!T) {
		return NULL;
	}
	char ch = 0;
	//printf("������ڵ���Ϣ��Ϊ����ʱ���ؿ�ָ��:>");
	scanf("%c", &ch);
	if (ch != '#') {
		T->data = ch;
	}
	else {
		return NULL;
	}
	//printf("����%d������\n", T->data);
	BiNode* p = (BiNode*)malloc(sizeof(BiNode));
	T->lchild = CreatBiTree(p);
	//printf("����%d���Һ���\n", T->data);
	BiNode* q = (BiNode*)malloc(sizeof(BiNode));
	T->rchild = CreatBiTree(q);
	return T;
} //����������

void PreOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
} //�������������

void InOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
} //�������������

void PostOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
} // �������������

void PreOrderTraverseByStack(BiTree T) {
	Stack S; InitStack(&S);
	BiNode* p = T;
	Push(&S, p);
	while (!StackEmpty(&S)) {
		BiNode* q = (BiNode*)malloc(sizeof(BiNode));
		Pop(&S, q);
		printf("%c ", q->data);
		if (q->rchild) {
			Push(&S, q->rchild);
		}
		if (q->lchild) {
			Push(&S, q->lchild);
		}
	}
} //��������ǵݹ��㷨

void InOrderTraverseByStack(BiTree T) {
	if (!T) {
		return;
	}
	Stack S;InitStack(&S);
	BiNode* p = T;
	while (p || !StackEmpty(&S)) {
		if (p) {
			Push(&S, p);
			p = p->lchild;
		}
		else {
			BiNode* q = (BiNode*)malloc(sizeof(BiNode));
			Pop(&S, q);
			printf("%c ", q->data);
			p = q->rchild;
		}
	}
} //��������ǵݹ��㷨

void PostOrderTraverseByStack(BiTree T) {
	Stack S1; InitStack(&S1);
	Stack S2; InitStack(&S2);
	BiNode* p = T;
	Push(&S1, p);
	while (!StackEmpty(&S1)) {
		BiNode* q = (BiNode*)malloc(sizeof(BiNode));
		Pop(&S1, q);
		Push(&S2, q);
		if (q->lchild) {
			Push(&S1, q->lchild);
		}
		if (q->rchild) {
			Push(&S1, q->rchild);
		}
	}
	while (!StackEmpty(&S2)) {
		BiNode* q = (BiNode*)malloc(sizeof(BiNode));
		Pop(&S2, q);
		printf("%c ", q->data);
	}
} //��������ǵݹ��㷨

BiTree copyBiTree(BiTree T) {
	if (T == NULL) {
		return NULL;
	}
	BiNode* CT = (BiNode*)malloc(sizeof(BiNode));
	CT->data = T->data;
	CT->lchild = copyBiTree(T->lchild);
	CT->rchild = copyBiTree(T->rchild);
	return CT;
} //���ƶ�����

void LevelTraverse(BiTree T) {
	Queue Q; InitQueue(&Q);
	BiNode* p = T;
	EnQueue(&Q, *p);
	while (QueueLength(&Q) != 0) {
		BiNode* q = (BiNode*)malloc(sizeof(BiNode));
		DeQueue(&Q, q);
		printf("%c ", q->data);
		if (q->lchild) {
			EnQueue(&Q, *q->lchild);
		}
		if (q->rchild) {
			EnQueue(&Q, *q->rchild);
		}
	}
} //��α���������

int DepthBiTree(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	int m = DepthBiTree(T->lchild);
	int n = DepthBiTree(T->rchild);
	if (m > n) {
		return m + 1;
	}
	else {
		return n + 1;
	}
} //��������������

int nodeCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	return nodeCount(T->lchild) + nodeCount(T->rchild) + 1;
} //��������Ľڵ����

int leafCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	if (T->lchild == NULL && T->rchild == NULL) {
		return 1;
	}
	return leafCount(T->lchild) + leafCount(T->rchild);
} //���������Ҷ�Ӹ���

int main() {
	BiTree T;
	T = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(T);
	printf("�������Ľṹ��#��ʾ��:>");
	//642##1##57##8##
	T = CreatBiTree(T);
	printf("\n--------�������������----------\n");
	PreOrderTraverse(T); 
	printf("\n--------�������������----------\n");
	InOrderTraverse(T);
	printf("\n--------�������������----------\n");
	PostOrderTraverse(T);
	printf("\n--------��������ǵݹ��㷨----------\n");
	PreOrderTraverseByStack(T);
	printf("\n--------��������ǵݹ��㷨----------\n");
	InOrderTraverseByStack(T);
	printf("\n--------��������ǵݹ��㷨----------\n");
	PostOrderTraverseByStack(T);
	printf("\n--------��α���������----------\n");
	LevelTraverse(T);

	printf("\n\n--------���ƶ�����----------\n");
	BiTree CT;
	CT = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(CT);
	CT = copyBiTree(T);
	printf("\n--------����������ƶ�����----------\n");
	PreOrderTraverse(CT);
	printf("\n--------����������ƶ�����----------\n");
	InOrderTraverse(CT);
	printf("\n--------����������ƶ�����----------\n");
	PostOrderTraverse(CT);
	printf("\n\n");

	int depth = DepthBiTree(T);
	printf("�����������Ϊ:%d\n", depth);
	int nodecount = nodeCount(T);
	printf("�������Ľڵ����Ϊ:%d\n", nodecount);
	int leafcount = leafCount(T);
	printf("��������Ҷ�Ӹ���Ϊ:%d\n", leafcount);

	return 0;
}
