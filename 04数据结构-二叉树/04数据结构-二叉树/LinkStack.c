#pragma once
#include "LinkStack.h"


//д��ջ��API

//��ʼ�� 
LinkStack* Init_LinkStack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->size = 0;
	stack->head.next = NULL;
	return stack;
}
//��ջ
void Push_LinkStack(LinkStack* stack,LinkNode* data) {
	if (stack == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}
//��ջ
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL) {
		return NULL;
	}
	if (stack->size == 0) {
		return NULL;
	}
	return stack->head.next;
}
//����ջ��Ԫ�ظ���
int Size_LinkStack(LinkStack* stack) {
	return stack->size;
}
//���ջ
void Clear_LinkStack(LinkStack* stack) {
	if (stack != NULL) {
		stack->head.next = NULL;
		stack->size = 0;
	}
}
//����ջ
void Free_LinkStack(LinkStack* stack) {
	if (stack != NULL) {
		free(stack);
	}
}