#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _size; // ��ʾջ����ЧԪ�صĸ��� ����ջ��λ��
}Stack;

//ʵ��ջ��API����
//��ʼ��һ��ջ
void StackInit(Stack* ps);
//ѹջ
void StackPush(Stack* ps, SDataType data);
//��ջ
void StackPop(Stack* ps);
//����ջ��Ԫ��
SDataType StackTop(Stack* ps);
//����ջ����ЧԪ�ظ���
int StackSize(Stack* ps);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);