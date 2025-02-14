#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ElemType
{
	int i;
}Elem;

typedef struct LNode
{
	Elem data;
	struct LNode* next;
}LNode, *LinkList;

typedef struct DNode
{
	Elem data;
	struct DNode* prior, * next;
	int freq;
}DNode, *DLinkList;


// #1 - P42
void del_x(LinkList L, Elem e)
{
	LNode* p = L->next, *r = L, *q;
	while (p)
	{
		if (p->data.i != e.i) {
			r->next = p;
			r = p;
			p = p->next;
		}
		else {
			q = p;
			p = p->next;
			free(q);
		}
	}
	r->next = NULL;
}

// #2 - P42
LinkList del_min(LinkList L)
{
	LNode* pre = L, * p = pre->next;
	LNode* minpre = pre, * minp = p;
	while (p) {
		if (p->data.i < minp->data.i) {
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next;
	free(minp);
	return L;
}

// #3 - P42
LinkList Reverse_1(LinkList L)
{
	LNode* p, * r;
	p = L->next;
	L->next = NULL;
	while (p) {
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}

// #4 - P42
void RangeDelete(LinkList L, int min, int max)
{
	LNode* p = L->next, * pre = L;
	while (p) {
		if (min < L->data.i && L->data.i < max) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}

// #6 - P42
LinkList DisCreat_2(LinkList A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode* p = A->next, * q;
	LNode* ra = A;
	while (p) {
		ra->next = p;
		ra = p;
		p = p->next;
		if (p) {
			q = p->next;
			p->next = B->next;
			B->next = p;
			p = q;
		}
	}
	ra->next = NULL;
	return B;
}

// #7 - P43
LinkList Del_Same(LinkList L)
{
	LNode* p = L->next, * q;
	if (!p) {
		return NULL;
	}
	while (p->next) {
		q = p->next;
		if (p->data.i == q->data.i) {
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
	return L;
}

// #8 - P43
LinkList Get_Common(LinkList La, LinkList Lb)
{
	LNode* p = La->next, * q = Lb->next, * r, * s;
	LinkList Lc = (LinkList)malloc(sizeof(LNode));
	r = Lc;
	while (p != NULL && q != NULL) {
		if (p->data.i < q->data.i) {
			p = p->next;
		}
		else if (q->data.i < p->data.i) {
			q = q->next;
		}
		else {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
	return Lc;
}

// #9 - P43
LinkList Union(LinkList La, LinkList Lb)
{
	LNode* pa = La->next, * pb = Lb->next;
	LNode* r, * pc = La;
	while (pa && pb) {
		if (pa->data.i == pb->data.i) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			r = pb;
			pb = pb->next;
			free(r);
		}
		else if (pa->data.i < pb->data.i) {
			r = pa;
			pa = pa->next;
			free(r);
		}
		else {
			r = pb;
			pb = pb->next;
			free(r);
		}
	}
	while (pa) {
		r = pa;
		pa = pa->next;
		free(pa);
	}
	while (pb) {
		r = pb;
		pb = pb->next;
		free(r);
	}
	pc->next = NULL;
	free(Lb);
	return La;
}

// #10 - P43
int Pattern(LinkList La, LinkList Lb)
{
	LNode* pa = La;
	LNode* pb = Lb;
	LNode* p = pa;
	while (pa && pb) {
		if (pa->data.i == pb->data.i) {
			pa = pa->next;
			pb = pb->next;
		}
		else {
			p = p->next;
			pa = p;
			pb = Lb;
		}
	}
	if (pb == NULL) {
		return 1;
	}
	else {
		return -1;
	}
}

// #11 - P43
int Symmetry(DLinkList L)
{
	DNode* p = L->next, * q = L->prior;
	if (p != q && p->next != q) {
		if (p->data.i == q->data.i) {
			p = p->next;
			q = q->prior;
		}
		else {
			return -1;
		}
	}
	return 1;
}

// #12 - P43
LinkList Link(LinkList h1, LinkList h2)
{
	LNode* p, * q;
	p = h1;
	while (p->next != h1) {
		p = p->next;
	}
	q = h2;
	while (q->next != h2) {
		q = q->next;
	}
	p->next = h2;
	q->next = h1;
	return h1;
}

// #13 - P43
DLinkList Locate(DLinkList L, Elem x)
{
	DNode* p = L->next, * q;
	while (p && p->data.i != x.i) {
		p = p->next;
	}
	if (!p) return NULL;
	else {
		p->freq++;
		if (p->prior == L || p->prior->freq > p->freq) {
			return p;
		}
		if (p->next != NULL) p->next->prior = p->prior; // �Ե�
			p->prior->next = p->next;
			q = p->prior;
		while (q != L && q->freq <= p->freq)
			q = q->prior;
		p->next = q->next;
		if (q->next != NULL) q->next->prior = p;
		p->prior = q;
		q->next = p;
	}
	return p;
}

// #14 - P43
LNode* Converse(LNode* L, int k)
{
	int n = 1;
	LNode* p = L;
	while (p->next) {
		p = p->next;
		n++;
	}
	p->next = L;
	for (int i = 1; i <= n - k; i++) {
		p = p->next;
	}
	L = p->next;
	p->next = NULL;
	return L;
}

// #15 - P43
LNode* FindLoopStart(LNode* head)
{
	LNode* fast = head, * slow = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) break;
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	LNode* p1 = head, * p2 = slow;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

// #16 - P43
int PairSum(LinkList L) {
	LNode* fast = L->next, * slow = L;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	LNode** newhead = NULL, * p = slow->next, * tmp;
	while (p != NULL) {
		tmp = p->next;
		p->next = newhead;
		newhead = p;
		p = tmp;
	}
	slow->next = NULL;
	int max = 0; p = L;
	LNode* q = newhead;
	while (q != NULL) {
		if (p->data.i + q->data.i > max)
			max = p->data.i + q->data.i;
		p = p->next;
		q = q->next;
	}
	return max;
}

// #17 -P43
LNode* Search_k(LinkList L, int k) {
	LNode* p = L->next, * q = p;
	int count = 0;
	while (p != NULL) {
		if (count < k) count++;
		else q = q->next;
		p = p->next;
	}
	if (count < k) return 0;
	else {
		printf("%d", q->data.i);
		return 1;
	}
}

// #18 - P44
typedef struct SNode{
	char data;
struct SNode* next;
}SNode;
int Listlen(SNode* head) {
	int len = 0;
	while (head->next != NULL) {
		len++;
		head = head->next;
	}
	return len;
}
SNode* Find_List(SNode* str1, SNode* str2) {
	int m, n;
	SNode* p, * q;
	m = Listlen(str1);
	n = Listlen(str2);
	for (p = str1; m > n; m--) {
		p = p->next;
	}
	for (q = str2; n > m; n--) {
		q = q->next;
	}
	while (p->next != NULL && q->next != p->next) {
		p = p->next;
		q = q->next;
	}
	return p->next;
}

// #19 - P44
typedef struct node {
	int data;
	struct node* link;
}NODE, *PNODE;
void func(PNODE h, int n) {
	PNODE p = h, r;
	int* q, m;
	q = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++)	*(q + i) = 0;
	while (p->link != NULL) {
		m = p->link->data > 0 ? p->link->data : -p->link->data;
		if (*(q + m) == 0) {
			*(q + m) = 1;
			p = p->link;
		}
		else {
			r = p->link;
			p->link = r->link;
			free(r);
		}
	}
	free(q);
}

// #20 - P44
typedef struct node {
	int data;
	struct node* next;
}NODE;
void change_list(NODE* h) {
	NODE* p, * q, * r, * s;
	p = q = h;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL) q = q->next;
	}
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	s = h->next;
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next;
		q = r;
	}
}

