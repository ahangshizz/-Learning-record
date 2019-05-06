#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������ջ�Ľ��
typedef struct LinkNode {
	struct LinkNode* next;
}LinkNode;
//������ջ
typedef struct LinkStack {
	LinkNode head;
	int size;
}LinkStack;

//д��ջ��API

//��ʼ�� 
LinkStack* Init_LinkStack();
//��ջ
void Push_LinkStack(LinkStack* stack,LinkNode* data);
//��ջ
void Pop_LinkStack(LinkStack* stack);
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);
//����ջ��Ԫ�ظ���
int Size_LinkStack(LinkStack* stack);
//���ջ
void Clear_LinkStack(LinkStack* stack);
//����ջ
void Free_LinkStack(LinkStack* stack);