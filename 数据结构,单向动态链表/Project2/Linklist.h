#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkNode {
	struct LinkNode* Next;
	int Value;
}LinkNode;
typedef struct LinkList {
	struct LinkNode* head;
	int size;
}LinkList;
//��ʼ������
LinkList* Init_LinkList();
//��ָ��λ�ò�����
void Insert_LinkList(LinkList* list, int pos,int Value);
//ɾ��ָ��λ�õĽ��
void Remove_LinkList(LinkList* list, int pos);
//�������ĳ���
void Size_LinkList(LinkList* list);
//��������λ��
void Find_LinkList(LinkList* list, int Value);
//��ӡ����
void Printf_LinkList(LinkList* list);
//���ص�һ�����λ��
void* Frist_LinkList(LinkList* list);
//�ͷ������ڴ�
void Free_LinkList(LinkList* list);