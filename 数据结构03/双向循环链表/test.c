#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
int main() {
	//��������
	LinkList* list = InitList();
	//��������
	int a, b, c, d, e;
	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;
	//����������
	ListPushBack(list, a);
	ListPushBack(list, b);
	ListPushBack(list, c);
	ListPushBack(list, d);
	ListPushBack(list, e);
	//��ӡ����
	ListPrint(list);
	printf("\n");
	//ͷ��
	int i = 100;
	ListPushFront(list, i);
	ListPrint(list);
	printf("\n");
	//ͷɾ
	ListPopFront(list);
	ListPrint(list);
	printf("\n");
	//βɾ
	ListPopBack(list);
	ListPrint(list);
	//��������
	ListRemove(list);
	system("pause");
	return 0;
}