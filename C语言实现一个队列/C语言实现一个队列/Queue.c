#include "Queue.h"

QNode* BuyQNode(QDataType data) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_pNext = NULL;
	return newNode;
}
//���еĳ�ʼ��
void QueueInit(Queue* q) {
	if (q == NULL) {
		return;
	}
	q->_front = NULL;
	q->_back = NULL;
	q->Q_size = 0;
}
//�����
void QueuePush(Queue* q, QDataType data) {
	if (q == NULL) {
		return;
	}
	QNode* newnode=BuyQNode(data);

	if(q->_front==NULL&&q->_back==NULL) {
		q->_front = newnode;
		q->_back = newnode;
	}
	q->_back->_pNext = newnode;
	q->_back = newnode;
	q->Q_size++;
}
//������
void QueuePop(Queue* q) {
	if (q == NULL) {
		return;
	}
	if (q->_front == NULL) {
		printf("����Ϊ��\n");
		return;
	}
	//�����һ��Ԫ��
	QNode* pCur = q->_front;
	//�Ѷ��е�ͷ�����ƶ�
	q->_front = q->_front->_pNext;
	//�ͷ��Ѿ������еĽ��
	free(pCur);
	--q->Q_size;
}
//���ض�ͷԪ��
QDataType QueueFront(Queue* q) {
	if (q == NULL) {
		return	0;
	}
	if (q->_front == NULL) {
		printf("����Ϊ��\n");
		return 0;
	}
	return q->_front->_data;
}
//���ض�βԪ��
QDataType QueueBack(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	return q->_back->_data;
}
//���ض�����ЧԪ�ظ���
int QueueSize(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	return q->Q_size;
}
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	if (q->_front == NULL) {
		return 0;
	}
	return 1;
}
//���ٶ���
void QueueDestroy(Queue* q) {
	if (q == NULL) {
		return;
	}
	for (int i = 0; i < q->Q_size; ++i) {
		QNode* pCur = q->_front;
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = NULL;
	}
}