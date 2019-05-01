#include "LinkList.h"


//��ʼ������
LinkList* InitList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->Pre = list->head;
	list->head->Next = list->head;
	list->size = 0;
	return list;
}
//β��
void ListPushBack(LinkList* list, int x) {
	if (list == NULL) {
		return;
	}
	//�����½��
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//����
	//��������ָ�����
	LinkNode* pCur = list->head->Pre;
	pNew->Pre = pCur;
	pNew->Next = list->head;
	pCur->Next = pNew;
	list->head->Pre = pNew;
	list->size++;
}
//βɾ
void ListPopBack(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//��������ָ��
	LinkNode* pCur = list->head->Pre;
	LinkNode* pPre = pCur->Pre;
	list->head->Pre = pPre;
	pPre->Next = list->head;
	free(pCur);
	list->size--;
}
//ͷ��
void ListPushFront(LinkList* list, int x) {
	if (list == NULL) {
		return;
	}
	//�����½��
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//��������ָ�����
	LinkNode* pCur = list->head->Next;
	pNew->Next = pCur;
	pNew->Pre = list->head;
	pCur->Pre = pNew;
	list->head->Next = pNew;
	list->size++;
}
//ͷɾ
void ListPopFront(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//����ָ��
	LinkNode* pCur = list->head->Next;
	LinkNode* pPre = pCur->Next;
	//ɾ��
	list->head->Next = pPre;
	pPre->Pre = list->head;
	list->size--;
}
//���Һ���
LinkNode* ListFind(LinkList* list, int x) {
	if (list == NULL) {
		return NULL;
	}
	if (list->size == 0) {
		return NULL;
	}
	LinkNode* pCur = list->head->Next;
	while (list->size) {
		if (pCur->value == x) {
			return pCur;
		}
		pCur = pCur->Next;
		--list->size;
	}
}
// ��pos��ǰ����в���
void ListInsert(LinkList* list,LinkNode* pos, int x) {
	if (pos == NULL) {
		return;
	}
	//�����½��
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//����ָ��
	LinkNode* pPre = pos->Pre;
	pNew->Next = pos;
	pNew->Pre = pPre;
	pPre->Next = pNew;
	pos->Pre = pNew;
	list->size++;
}
// ɾ��posλ�õĽڵ�
void ListErase(LinkList* list,LinkNode* pos) {
	if (list == NULL) {
		return;
	}
	if (pos == NULL) {
		return;
	}
	//��������ָ��
	LinkNode* pPre = pos->Pre;
	LinkNode* pNext = pos->Next;
	pPre->Next = pNext;
	pNext->Pre = pPre;
	free(pos);
	list->size--;
}
//��������
void ListRemove(LinkList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
}
//��ӡ����
void ListPrint(LinkList* list) {
	if (list == NULL) {
		return;
	}
	LinkNode* pCur = list->head->Next;
	while (pCur!= list->head) {
		printf("%d-->", pCur->value);
		pCur = pCur->Next;
	}
}