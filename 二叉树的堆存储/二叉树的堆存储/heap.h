#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
}Heap;
//���ݺ���
void CheckCapacity(Heap* hp);
//��������
void Swap(HPDataType* Left, HPDataType* Right);
//��������
void adjustdown(HPDataType* array, int size, int parent);
//��������
void adjustup(HPDataType* array, int size, int child);
// �������ʼ����
void InitHeap(Heap* hp, HPDataType* array, int size);

// ��ʼ��һ���ն�
void InitEmptyHeap(Heap* hp, int capacity);

// �ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, HPDataType data);

// ɾ���Ѷ�Ԫ��
void EraseHeap(Heap* hp);

// ��ȡ������ЧԪ�ظ���
int HeapSize(Heap* hp);

// �����Ƿ�Ϊ�ն�
int HeapEmpty(Heap* hp);

// ��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp);

// ���ٶ�
void DestroyHeap(Heap* hp);