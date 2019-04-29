#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ҵ����ķ�ʽ,ʵ��ѭ������
//����Ľ��
typedef struct CircleLinkNode {
	struct CircleLinkNode* next;
}CircleLinkNode;

typedef struct CircleLinkList {
	//ʹ��ָ��Ļ���Ҫ��head�����ڴ�,ֱ��дʵ���  ��������ڴ�ʱ,head�ᱻ�����ڴ�
	CircleLinkNode head;
	int size;
}CircleLinkList;

//��дѭ�������API����
//�ص�����,���ڲ�֪��,�û�ʹ�õ�����,ʹ�ûص�����,���û����в���
//��Ϥһ�»ص�������ʹ��,����Ӧ��
//�ȽϺ����Ļص�
typedef int(*CompareNode)(CircleLinkNode*, CircleLinkNode*);
//��ӡ�����Ļص�����
typedef void(*PrintNode)(CircleLinkNode*);
//��ʼ������
CircleLinkList* Init_CircleLinkList();
//������
void Insert_CircleLinkList(CircleLinkList* list,int pos,CircleLinkNode* data);
//��õ�һ�����
CircleLinkNode* Frist_CircleLinkList(CircleLinkList* list);
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* list, int pos);
//����ֵɾ�����
void RemoveByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare);
//�������ĳ���
void Size_CircleLinkList(CircleLinkList* list);
//����
void Find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare);
//��ӡ���
void Print_CircleLinkList(CircleLinkList* list, PrintNode Print);
//�ж��Ƿ�Ϊ��
void IsNULL_CircleLinkList(CircleLinkList* list);
//�ͷ��ڴ�
void Free_CircleLinkList(CircleLinkList* list);