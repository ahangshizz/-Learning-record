#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����������
typedef struct LinkNode {
	struct LinkNode* Pre;
	struct LinkNode* Next;
	int value;
}LinkNode;

//��������
typedef struct LinkList {
	LinkNode* head;
	int size;
}LinkList;

//��ʼ������
LinkList* InitList();
//β��
void ListPushBack(LinkList* list,int x);
//βɾ
void ListPopBack(LinkList* list);
//ͷ��
void ListPushFront(LinkList* list, int x);
//ͷɾ
void ListPopFront(LinkList* list);
//���Һ���
LinkNode* ListFind(LinkList* list,int x);
// ��pos��ǰ����в���
void ListInsert(LinkList* list,LinkNode* pos, int x);
// ɾ��posλ�õĽڵ�
void ListErase(LinkList* list,LinkNode* pos);
//��������
void ListRemove(LinkList* list);
//��ӡ����
void ListPrint(LinkList* list);