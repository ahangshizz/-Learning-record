#include "CircleLinkList.h"




//��дѭ�������API����
//�ص�����,���ڲ�֪��,�û�ʹ�õ�����,ʹ�ûص�����,���û����в���
//��Ϥһ�»ص�������ʹ��,����Ӧ��
//�ȽϺ����Ļص�
typedef int(*CompareNode)(CircleLinkNode*, CircleLinkNode*);
//��ӡ�����Ļص�����
typedef void(*PrintNode)(CircleLinkNode*);
//��ʼ������
CircleLinkList* Init_CircleLinkList() {
	CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	list->head.next = &(list->head);
	list->size = 0;
	return list;
}
//������
void Insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}
	//����λ�ò��ҽ��,����ǰһ�����
	//����ָ�����
	CircleLinkNode* Pcur = &(list->head);
	for (int i = 0; i < pos; ++i) {
		Pcur = Pcur->next;
	}
	//�����ݲ�������
	data->next = Pcur->next;
	Pcur->next = data;
	list->size++;
}
//��õ�һ�����
CircleLinkNode* Frist_CircleLinkList(CircleLinkList* list) {
	return list->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		return;
	}
	//����posɾ��Ԫ��
	CircleLinkNode* Pcur = list->head.next;
	CircleLinkNode* Ppre = Pcur;
	for (int i = 0; i < pos; ++i) {
		Ppre = Pcur;
		Pcur = Pcur->next;
	}
	Ppre->next = Pcur->next;
	list->size--;
}
//����ֵɾ�����
void RemoveByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	for (int i = 0; i < list->size; ++i) {
		if (compare(Pcur, data) == 0) {
			RemoveByPos_CircleLinkList(list, i);
			break;
		}
		Pcur = Pcur->next;
	}
}
//�������ĳ���
void Size_CircleLinkList(CircleLinkList* list) {
	printf("��ǰ����ĳ�����%d\n", list->size);
}
//����
void Find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	int i = 0;
	for (i = 0; i < list->size; ++i) {
		if (compare(data, Pcur) == 0) {
			printf("�ҵ���\n");
			printf("�����ҵ�λ��������ĵ�%dλ\n", i);
			break;
		}
	}
	if (i == list->size) {
		printf("����Ҫ���ҵĽ��û���ҵ�\n");
	}
}
//��ӡ���
void Print_CircleLinkList(CircleLinkList* list, PrintNode Print) {
	if (list == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	for (int i = 0; i < list->size; ++i) {
		if (Pcur == &(list->head)) {
			Pcur = Pcur->next;
		}
		Print(Pcur);
		Pcur = Pcur->next;
	}
	printf("-------------------------------\n");
}
//�ж��Ƿ�Ϊ��
void IsNULL_CircleLinkList(CircleLinkList* list) {
	if (list->size == 0) {
		printf("��ǰ�����ǿ�����\n");
	}
}
//�ͷ��ڴ�
void Free_CircleLinkList(CircleLinkList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
}