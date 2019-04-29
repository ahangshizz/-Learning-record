#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024
typedef struct SeqQueue {
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//��ʼ��
SeqQueue* InIt_SeqQueue();
//���
void Push_SeqQueue(SeqQueue* seq,void* data);
//����
void Pop_SeqQueue(SeqQueue* seq);
//���ض����С
int Size_SeqQueue(SeqQueue* seq);
//���ض�ͷԪ��;
void* Front_SeqQueue(SeqQueue* seq);
//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* seq);
//��ն���
void Clear_SeqQueue(SeqQueue* seq);
//���ٶ���
void Free_SeqQueue(SeqQueue* seq); 