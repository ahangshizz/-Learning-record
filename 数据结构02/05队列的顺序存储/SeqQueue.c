#include "SeqQueue.h"

//��ʼ��
SeqQueue* InIt_SeqQueue() {
	SeqQueue* seq = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; ++i) {
		seq->data[i] = NULL;
	}
	seq->size = 0;
	return seq;
}
//���
void Push_SeqQueue(SeqQueue* seq,void* data) {
	if (seq == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (seq->size == 1024) {
		return;
	}
	seq->data[seq->size] = data;
	seq->size++;
}
//����
void Pop_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	if (seq->size == 0) {
		return;
	}
	//�ƶ�Ԫ��
	for (int i = 0; i < seq->size - 1; ++i) {
		seq->data[i] = seq->data[i + 1];
	}
	seq->size--;
}
//���ض����С
int Size_SeqQueue(SeqQueue* seq) {
	return seq->size;
}
//���ض�ͷԪ��;
void* Front_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return NULL;
	}
	return seq->data[0];
}
//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return NULL;
	}
	if (seq->size == 0) {
		return NULL;
	}
	return seq->data[seq->size - 1];
}
//��ն���
void Clear_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	//for (int i = 0; i < MAX_SIZE; ++i) {
	//	seq->data[i] = NULL;
	//}
	seq->size = 0;
}
//���ٶ���
void Free_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	free(seq);
	seq = NULL;
}