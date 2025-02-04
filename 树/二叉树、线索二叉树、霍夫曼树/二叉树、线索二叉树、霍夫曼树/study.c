#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSSIZE 100
#define MAXQSIZE 100

typedef char TElem, Elem; // 树节点的信息的数据类型

typedef struct BiNode { 
	TElem data;
	struct BiNode* lchild, * rchild;
}BiNode, *BiTree; //二叉树节点的定义

typedef struct TriNode {
	TElem data;
	struct TriNode* lchild, * rchild, * parent;
}TriNode, *TriTree; //三叉树节点的定义

typedef struct {
	BiNode* top;
	BiNode* base;
	int stackSize;
}Stack; //栈的定义

typedef struct {
	BiNode* base;
	int front;
	int rear;
}Queue; //队列的定义

void InitStack(Stack* S) {
	S->base = (BiNode*)malloc(sizeof(BiNode) * MAXSSIZE);
	if (!S) {
		printf("栈创建失败\n");
		return;
	}
    S->top = S->base;
	S->stackSize = MAXSSIZE;
} //栈的初始化

void Push(Stack* S, BiNode* T) {
	if (S->top - S->base == S->stackSize) {
		printf("栈满\n");
		return;
	}
	*S->top++ = *T;
} //入栈

void Pop(Stack* S, BiNode* T) {
	if (S->base == S->top) {
		printf("栈空\n");
		return;
	}
	*T = *--S->top;
} //出栈

int StackEmpty(Stack* S) {
	if (S->top == S->base) {
		return 1;
	}
	else {
		return 0;
	}
} //判断栈空

void InitQueue(Queue* Q) {
	Q->base = (BiNode*)malloc(sizeof(BiNode) * MAXQSIZE);
	if (!Q) {
		return;
	}
	Q->front = Q->rear = 0;
} //初始化队列

int QueueLength(Queue* Q) {
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
} //返回队列长度

void EnQueue(Queue* Q, BiNode T) {
	if (QueueLength(Q) == MAXQSIZE - 1) {
		return;
	}
	Q->base[Q->rear] = T;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
} //入队

void DeQueue(Queue* Q, BiNode* T) {
	if (Q->rear == Q->front) {
		return;
	}
	*T = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
} //出队

void InitBiTree(BiTree T) {
	if (!T) {
		return;
	}
	T->lchild = T->rchild = NULL;
} //初始化二叉树

BiNode* CreatBiTree(BiTree T) {
	if (!T) {
		return NULL;
	}
	char ch = 0;
	//printf("请输入节点信息，为负数时返回空指针:>");
	scanf("%c", &ch);
	if (ch != '#') {
		T->data = ch;
	}
	else {
		return NULL;
	}
	//printf("进入%d的左孩子\n", T->data);
	BiNode* p = (BiNode*)malloc(sizeof(BiNode));
	T->lchild = CreatBiTree(p);
	//printf("进入%d的右孩子\n", T->data);
	BiNode* q = (BiNode*)malloc(sizeof(BiNode));
	T->rchild = CreatBiTree(q);
	return T;
} //创建二叉树

void PreOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
} //先序遍历二叉树

void InOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->rchild);
} //中序遍历二叉树

void PostOrderTraverse(BiTree T) {
	if (T == NULL) {
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ", T->data);
} // 后序遍历二叉树

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
} //先序遍历非递归算法

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
} //中序遍历非递归算法

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
} //后序遍历非递归算法

BiTree copyBiTree(BiTree T) {
	if (T == NULL) {
		return NULL;
	}
	BiNode* CT = (BiNode*)malloc(sizeof(BiNode));
	CT->data = T->data;
	CT->lchild = copyBiTree(T->lchild);
	CT->rchild = copyBiTree(T->rchild);
	return CT;
} //复制二叉树

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
} //层次遍历二叉树

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
} //计算二叉树的深度

int nodeCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	return nodeCount(T->lchild) + nodeCount(T->rchild) + 1;
} //求二叉树的节点个数

int leafCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	if (T->lchild == NULL && T->rchild == NULL) {
		return 1;
	}
	return leafCount(T->lchild) + leafCount(T->rchild);
} //求二叉树的叶子个数

int main() {
	BiTree T;
	T = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(T);
	printf("输入数的结构，#表示空:>");
	//642##1##57##8##
	T = CreatBiTree(T);
	printf("\n--------先序遍历二叉树----------\n");
	PreOrderTraverse(T); 
	printf("\n--------中序遍历二叉树----------\n");
	InOrderTraverse(T);
	printf("\n--------后序遍历二叉树----------\n");
	PostOrderTraverse(T);
	printf("\n--------先序遍历非递归算法----------\n");
	PreOrderTraverseByStack(T);
	printf("\n--------中序遍历非递归算法----------\n");
	InOrderTraverseByStack(T);
	printf("\n--------后序遍历非递归算法----------\n");
	PostOrderTraverseByStack(T);
	printf("\n--------层次遍历二叉树----------\n");
	LevelTraverse(T);

	printf("\n\n--------复制二叉树----------\n");
	BiTree CT;
	CT = (BiTree)malloc(sizeof(BiNode));
	InitBiTree(CT);
	CT = copyBiTree(T);
	printf("\n--------先序遍历复制二叉树----------\n");
	PreOrderTraverse(CT);
	printf("\n--------中序遍历复制二叉树----------\n");
	InOrderTraverse(CT);
	printf("\n--------后序遍历复制二叉树----------\n");
	PostOrderTraverse(CT);
	printf("\n\n");

	int depth = DepthBiTree(T);
	printf("二叉树的深度为:%d\n", depth);
	int nodecount = nodeCount(T);
	printf("二叉树的节点个数为:%d\n", nodecount);
	int leafcount = leafCount(T);
	printf("二叉树的叶子个数为:%d\n", leafcount);

	return 0;
}
