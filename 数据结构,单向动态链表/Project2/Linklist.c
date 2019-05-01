#include "Linklist.h"
//��ʼ��
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->Value =0;
	list->head->Next = NULL;
	list->size = 0;
	return list;
}
//��ָ��λ�ò�����
void Insert_LinkList(LinkList* list, int pos, int Value) {
	if (list == NULL) {
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}
	//�����½��
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	NewNode->Value = Value;
	NewNode->Next = NULL;
	//�ҽ��
	//����ָ�����
	LinkNode* Pcur = list->head;
	for (int i = 0; i < pos; ++i) {
		Pcur = Pcur->Next;
	}
	//������
	NewNode->Next = Pcur->Next;
	Pcur->Next = NewNode;
	++list->size;
}
//ɾ��ָ��λ�õĽ��
void Remove_LinkList(LinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		printf("�������λ�ò��Ϸ�\n");
	}
	//��������ָ��,��Ҫ��������ָ��
	LinkNode* Pcur=list->head;
	LinkNode* Ppre = Pcur;//����������һ������λ��
	for (int i = 0; i < pos; ++i) {
		Ppre = Pcur;
		Pcur = Pcur->Next;
	}
	Ppre->Next = Pcur->Next;
	free(Pcur);
	--list->size;
}
//�������ĳ���
void Size_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	printf("�������������%d�����", list->size - 1);
}
//��������λ��
void Find_LinkList(LinkList* list, int Value) {
	if (list == NULL) {
		return;
	}
	LinkNode* Pcur = list->head;
	Pcur = Pcur->Next;
	for (int i = 0; i < list->size; ++i) {
		if (Pcur->Value == Value) {
			printf("���ֵ�ڵ�%d�������\n", i);
			break;
		}
		Pcur = Pcur->Next;
	}
}
//��ӡ����
void Printf_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	LinkNode* Pcur = list->head;
	for (int i = 0; i < list->size; ++i) {
		Pcur = Pcur->Next;
		printf("%d--->", Pcur->Value);
	}
	printf("NULL\n");
}
//���ص�һ�����λ��
void* Frist_LinkList(LinkList* list) {
	return list->head->Next;
}
//�ͷ������ڴ�
void Free_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}

	//����ָ��
	LinkNode* Pcur = list->head;
	while (Pcur != NULL) {
		LinkNode* Ppre = Pcur->Next;
		free(Pcur);
		Pcur = Ppre;
	}
	free(list);
}