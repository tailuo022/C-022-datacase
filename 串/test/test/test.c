#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCH 255
typedef struct {
	char ch[MAXCH + 1];
	int length;
}SString;

void InitSString(SString* str) {
	str->length = 0;
}

void AddSString(SString* str) {
	int i = 1;
	if (str->length == MAXCH) {
		printf("串满\n");
		return;
	}
	while (str->ch[i - 1] != '\n' && str->length != MAXCH) {
		scanf("%c", &str->ch[str->length + 1]);
		i++;
		if (str->ch[i - 1] != '\n') { 
			str->length++; 
		}
	}
	if (str->length == MAXCH) {
		str->ch[MAXCH] = '\0';
	}
	else {
		str->ch[str->length + 1] = '\0';
	}
}

int SStringEmpty(SString* str) {
	if (str->length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int SStringLength(SString* str) {
	return str->length;
}

void SStringTraverse(SString* str) {
	if (str->length == 0) {
		printf("串中没有元素\n");
		return;
	}
	for (int i = 1; i <= str->length; i++) {
		printf("%c ", str->ch[i]);
	}
	printf("\n");
}

int StrCompare(SString* str, char* p) {
	int i = 1, j = 0;
	while (str->ch[i] != '\0' && p[j] != '\0') {
		if (str->ch[i] != p[j]) {
			return str->ch[i] - p[j];
		}
		else {
			j++;
			i++;
		}
	}
	while (p[j] == '\0' && str->ch[i] != '\0') {
		return 1;
	}
	while (str->ch[i] == '\0' && p[j] != '\0') {
		return -1;
	}
	return 0;
}

SString StrConcat(SString* str, SString* p) {
	if (str->length + p->length >= MAXCH) {
		printf("内存不足\n");
		return *str;
	}
	SString T;
	InitSString(&T);
	int i = 0;
	for (i = 1; i <= str->length; i++) {
		T.ch[i] = str->ch[i];
		T.length++;
	}
	for (int j = 1; j <= p->ch[j]; j++) {
		T.ch[i++] = p->ch[j];
		T.length++;
	}
	T.ch[i] = '\0';
	return T;
}

void StrCopy(SString* T, SString* S) {
	T->length = S->length;
	int i = 0;
	for (i = 1; i <= S->length; i++) {
		T->ch[i] = S->ch[i];
	}
	T->ch[i] = '\0';
}

void SubStr(SString* Sub, SString* S, int pos, int len) {
	if (pos + len >= MAXCH) {
		printf("位置错误\n");
	}
	int i = 0;
	Sub->length = len;
	for (i = 1; i <= len; i++) {
		Sub->ch[i] = S->ch[pos + i - 1];
	}
}

void ClearStr(SString* str) {
	str->ch[1] = '\0';
	str->length = 0;
}

void StrInsert(SString* S, int pos, SString* T) {
	if (S->length + T->length >= MAXCH) {
		printf("内存不足\n");
		return;
	}
	if (pos > S->length) {
		printf("插入位置不合法\n");
	}
	int i = 0;
	int j = S->length;
	for (i = T->length + S->length; i >= pos + T->length; i--) {
		S->ch[i] = S->ch[j];
		j--;
	}
	i = 1;
	for (j = pos; i <= T->length; i++) {
		S->ch[j++] = T->ch[i];
	}
	S->length = S->length + T->length;
	S->ch[S->length + 1] = '\0';
}

void StrDelete(SString* S, int pos, int len) {
	if (pos + len > S->length + 1) {
		printf("删除对象越界\n");
		return;
	}
	if (pos > S->length || pos < 0) {
		printf("删除位置不合法\n");
		return;
	}
	int i = 0;
	int j = pos + len;
	for (i = pos; j <= S->length; ) {
		S->ch[i++] = S->ch[j++];
	}
	S->length = S->length - len;
	S->ch[S->length + 1] = '\0';
}

int Index_BF(SString* S, char* p, int pos) {
	int i = pos;
	int j = 0;
	int sum_p = strlen(p);
	while (i <= S->length && j < sum_p) {
		if (S->ch[i] == p[j]) {
			i++; j++;
		}
		else {
			i = i - j + 1; j = 0;
		}
	}
	if (j >= sum_p) return i - sum_p;
	else return 0;
}

char* get_next(char* next, char* p, int len) {
	next[1] = 0;
	int i = 1;
	int j = 0;
	while (i < len) {
		if (j == 0 || p[i] == p[j]) {
			i++; j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}

int Index_KMP(SString* S, char* p, int pos, char* next) {
	int i = pos;
	int j = 1;
	int len_p = strlen(p);

	while (i <= S->length && j <= len_p) {
		if (S->ch[i] == p[j]) {
			i++; j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= len_p) return i - len_p + 1;
	else return 0;
}

int main() {
	SString S;
	InitSString(&S);
	AddSString(&S);
	if (SStringEmpty(&S)) {
		printf("串为空\n");
	}
	else {
		printf("串不为空\n");
	}
	printf("串的长度为%d\n", S.length);
	SStringTraverse(&S);
	//串不为空
	//串的长度为7
	//1 2 3 4 5 6 7

	char* p1 = "123456";
	if (StrCompare(&S, p1) > 0) {
		printf("S > p1\n");
	}
	else if (StrCompare(&S, p1) < 0) {
		printf("S < p1\n");
	}
	else {
		printf("S = p1\n");
	}
	//S > p1
	char* p2 = "1234567";
	if (StrCompare(&S, p2) > 0) {
		printf("S > p2\n");
	}
	else if (StrCompare(&S, p2) < 0) {
		printf("S < p2\n");
	}
	else {
		printf("S = p2\n");
	}
	//S = p2
	char* p3 = "12345678";
	if (StrCompare(&S, p3) > 0) {
		printf("S > p3n");
	}
	else if (StrCompare(&S, p3) < 0) {
		printf("S < p3\n");
	}
	else {
		printf("S = p3\n");
	}
	//S < p3

	//SString S2, S3;
	//InitSString(&S2);
	//InitSString(&S3);
	//AddSString(&S2);
	//AddSString(&S3);
	//SString S1;
	//S1 = StrConcat(&S2, &S3);
	//SStringTraverse(&S1);
	////123456
	////123456
	////1 2 3 4 5 6 1 2 3 4 5 6

	SString T;
	StrCopy(&T, &S);
	SStringTraverse(&T);
	//1 2 3 4 5 6 7
	SString Sub;
	InitSString(&Sub);
	SubStr(&Sub, &S, 3, 3);
	SStringTraverse(&Sub);
	//3 4 5
	ClearStr(&Sub);
	SStringTraverse(&Sub);
	//串中没有元素
	StrInsert(&S, 3, &T);
	SStringTraverse(&S);
	//1 2 1 2 3 4 5 6 7 3 4 5 6 7

	StrDelete(&S, 3, 3231);
	StrDelete(&S, 99, 23);
	StrDelete(&S, -1, 4);
	//删除对象越界
	//删除对象越界
	//删除位置不合法
	StrDelete(&S, 3, 4);
	SStringTraverse(&S);
	//1 2 5 6 7 3 4 5 6 7
	StrDelete(&S, 3, 3);
	SStringTraverse(&S);
	//1 2 3 4 5 6 7

	char* ch1 = "457";
	char* ch2 = "456";
	int result1 = Index_BF(&S, ch1, 1);
	int result2 = Index_BF(&S, ch2, 1);
	printf("%d %d\n", result1, result2);
	//0 4
	char* ch3 = "56";
	char* ch4 = "56";
	int result3 = Index_BF(&S, ch3, 3);
	int result4 = Index_BF(&S, ch3, 6);
	printf("%d %d\n", result3, result4);
	//5 0

	printf("\n\n\n");
	SString SS;
	InitSString(&SS);
	AddSString(&SS);
	SStringTraverse(&SS);
	char* pp = "011223344";
	printf("%s\n", pp);
	int len_pp = strlen(pp);
	char* next = (char*)malloc(sizeof(char) * len_pp);
	next = get_next(next, pp, len_pp);
	int result = Index_KMP(&SS, pp, 1, next);
	printf("%d\n", result);
	//input:111111111111223344 -> output:11

	return 0;
}