#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLENGTH 100

typedef struct Elemyype
{
	int i;
}Elem;

typedef struct Lnode
{
	Elem data[MAXLENGTH];
	int length;
}SqList;

// #1 - P19
bool GetMinList(SqList* L, Elem* e)
{
	if (L->length == 0) {
		printf("链表为空\n");
		return false;
	}
	*e = L->data[0];
	int pos = 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i].i < e->i) {
			*e = L->data[i];
			pos = i;
		}
	}
	L->data[pos] = L->data[L->length - 1];
	L->length--;
	return true;
}

// #2 - P19
void Reverse(SqList* L)
{
	Elem e; 
	for (int i = 0; i < L->length / 2; i++) {
		e = L->data[i];
		L->data[i] = L->data[L->length - i - 1];
		L->data[L->length - i - 1] = e;
	}
}

// #3 - P19
void del_x(SqList* L)
{
	Elem x;
	int count = 0;
	for (int i = 0; i < L->length; i++) {
		if ('x' != L->data[i].i) {
			L->data[count++] = x;
		}
	}
	L->length = count;
}

// #4 - P19
bool del_s_t(SqList* L)
{
	if (0 == L->length || s >= t) {
		return false;
	}
	int count = 0;
	for (int i = 0; i < L->length; i++) {
		if (s <= L->data[i] && L->data[i] <= t) {
			count++;
		}
		else {
		L->data[i - count] = L->data[i];
		}
	}
	L->length = L->length - count;
	return true;
}

// #5 - P19
bool del_re(SqList* L)
{
	if (L->length == 0) {
		return false;
	}
	int count = 0;
	Elem e;
	e = L->data[0];
	for (int i = 1; i < L->length; i++) {
		if (L->data[i] != e) {
			L->data[count] = e;
			e = L->data[i];
			count++;
		}
	}
	L->data[++count] = e;
	L->length = count;
	return true;
}
bool answer(SqList* L)
{
	if (L->length == 0) {
		return false;
	}
	int i, j;
	for (i = 0, j = 1; j < L->length; j++)
		if (L->data[i] != L->data[j])
			L->data[++i] = L->data[j];
	L->length = i + 1;
	return true;
}

// #6 - P19
SqList* Combine(SqList* La, SqList* Lb)
{
	if ((La->length + Lb->length) > MAXLENGTH) {
		return NULL;
	}
	int i = 0, j = 0, k = 0;
	SqList* Lc;
	Lc->length = La->length + Lb->length;
	while (i < La->length && j < Lb->length) {
		if (La->data[i] <= Lb->data[j]) {
			Lc->data[k++] = La->data[i++];
		}
		else {
			Lc->data[k++] = Lb->data[j++];
		}
	}
	while (i < La->length) {
		Lc->data[k++] = La->data[i++];
	}
	while (j < Lb->length) {
		Lc->data[k++] = Lb->data[j++];
	}
	return Lc;
}

// #7 - P19
void Reverse(int arr[], int left, int right, int size)
{
	if (left >= right || right >= size) {
		return;
	}
	int mid = (left + right) / 2;
	for (int i = 0; i <= mid - left; i++) {
		int data = arr[left + i];
		arr[left + i] = arr[right - i];
		arr[right - i] = data;
	}
}
void Change(int arr[], int m, int n, int size)
{
	Reverse(A, 0, n + m - 1, size);
	Reverse(A, 0, n - 1, size);
	Reverse(A, n, n + m - 1, size);
}

// #8 - P19
void SearchExchange(int arr[], Elem x)
{
	int left = 0, right = sizeof(arr) - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == x) break;
		else if (arr[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	if (arr[mid] == 'x' && mid != sizeof(arr) - 1) {
		int i = arr[mid];
		arr[mid] = arr[mid + 1];
		arr[mid + 1] = i;
	}
	if (left > right) {
		for (int i = n - 1; arr[i] > 'x'; i--)
			arr[i + 1] = arr[i];
		arr[++i] = 'x';
	}
}

// #9 - P19
void PutSame(int a[], int b[], int c[], int n)
{
	int i = 0, j = 0, k = 0; //
	while (i < n && j < n && k < n) { //
		if (a[i] == b[j] && b[j] == c[k]) {
			printf("%d\n", a[i]);
			i++; j++; k++;
		}
		else {
			int maxnum = max(a[i], max(b[j]), c[k]));
			if (a[i] < maxnum) i++;
			if (b[j] < maxnum) j++;
			if (c[k] < maxnum) k++;
		}
	}
}

// #10 - P19
void Reverse_1(int arr[], int left, int right)
{
	int sz;
	for (int i = 0; i < (right - left + 1) / 2; i++) {
		sz = arr[left + i];
		arr[left + i] = arr[right - i];
		arr[right - i] = sz;
	}
}
void Converse(int arr[], int n, int p)
{
	Reverse_1(arr[], 0, p - 1);
	Reverse_1(arr[], p, n - 1);
	Reverse_1(arr[], 0, n - 1);
}

// #11 - P19
int MidSearch(int a[], int b[], int n)
{
	int s1, d1, m1, s2, d2, m2;
	s1 = 0; d1 = n - 1;
	s2 = 0; d2 = n - 1;
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (a[m1] == b[m2])
			return a[m1];
		if (a[m1] < b[m2]) {
			if ((d1 - s1 + 1) % 2 != 0) {// 元素个数为奇数
				s1 = m1;
				d2 = m2;
			}
			else {
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else {
			if ((d1 - s1 + 1) % 2 != 0) {
				d1 = m1;
				s2 = m2;
			}
			else {
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return a[s1] < b[s2] ? a[s1] : b[s2];
}

// #12 - P20
int Majority(int arr[], int n)
{
	int c, count = 1;
	c = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] == c)
			count++;
		else
			if (count > 0)
				count--;
			else {
				c = arr[i];
				count = 1;
			}
	}
	if (count > 0)
		for (int i = count = 0; i < n; i++)
			if (arr[i] == c)
				count++;
	if (count > (n / 2)) return c;
	else return -1;
}

// #13 - P20
int FindMissMin(int arr[], int n)
{
	int* B;
	int i = 0;
	B = (int*)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n);
	for (i = 0; i < n; i++)
		if (1 <= arr[i] && arr[i] <= n)
			B[arr[i] - 1] = 1;
	for (i = 0; i < n; i++)
		if (0 == B[i]) break;
	return i + 1;
}

// #14 - P20
#define INT_MAX 0x7fffffff
int abs_(int a) // 绝对值
{
	if (a > 0) return a;
	else return -a;
}
bool xls_min(int a, int b, int c) // a是否为三个数的最小值
{
	if (a <= b && a <= c) return true;
	else return false;
}
int FindMinofTrip(int a[], int n, int b[], int m, int c[], int p)
{
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < n && j < m && k < p && D_min > 0) {
		D = abs_(a[i] - b[j]) + abs_(b[j] - c[k]) + abs_(c[k] - a[i]);
		if (D < D_min) D_min = D;
		if (xls_min(a[i], b[j], c[k])) i++;
		else if (xls_min(b[j], c[k], a[i])) j++;
		else  k++;
	}
	return D_min;
}











