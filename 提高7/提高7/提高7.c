//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//typedef struct teacher {
//	int id;
//	struct teacher *next;
//}teacher;
////����ͷ�ڵ�
//teacher *SListCreat() {
//	teacher* head = NULL;//����һ��ͷ�ڵ㣬ͷ�ڵ���Ϊһ����־�����洢��Ч����
//	head = (teacher*)malloc(sizeof(teacher));
//	head->id = -1;
//	head->next = NULL;
//	teacher* Pcur = head;
//	teacher* Pnew = NULL;
//	int data;
//	while (1) {
//		printf("���������ݣ�");
//		scanf("%d", &data);
//		if (data == -1) {//����-1�˳�
//			break;
//		}
//		Pnew = (teacher*)malloc(sizeof(teacher));//�½ڵ㶯̬����ռ�
//		Pnew->id = data;//��Pnew�ĳ�Ա���и�ֵ
//		Pnew->next = NULL;
//		//��������ϵ
//		Pcur->next = Pnew;
//		//Pnew����һ���ڵ�ָ���
//		Pnew->next = NULL;
//		Pcur = Pnew;
//	}
//	return head;
//}
////����ı���
//int SListprint(teacher* head) {
//	if (head == NULL) {
//		return -1;
//	}
//	//ȡ��ͷ�ڵ��next
//	teacher* Pcur = head->next;
//	printf("head->");
//	while (Pcur != NULL) {
//		printf("%d->", Pcur->id);
//		Pcur = Pcur->next;//�ѵ�ǰ�ڵ�����ƶ�
//	}
//	printf("->NULL");
//	return 0;
//}
//int main() {
//	teacher* head = NULL;
//	head = SListCreat();//����ͷ�ڵ�
//	SListprint(head);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct node {
	int id;
	struct node* next;
}node;

node* SListcreat() {
	node*head = NULL;
	head = (node*)malloc(sizeof(node));
	if (head == NULL) {
		return -1;
	}
	head->id = -1;
	head->next = NULL;
	int data;
	node* Pnew = NULL;
	node* Pcrt = head;
	while (1) {
		printf("����������");
		scanf("%d", &data);
		if (data == -1) {
			break;
		}
		Pnew = (node*)malloc(sizeof(node));
		Pnew->id = data;
		Pnew->next = NULL;
		Pcrt->next = Pnew;
		Pnew->next = NULL;
		Pcrt = Pnew;
	}
	return head;
}
//����ı���
int SListprint(node* head) {
	if (head == NULL) {
		return -1;
	}
	node* Pcrt = head->next;
	printf("head->");
	while (Pcrt != NULL) {
		printf("%d->", Pcrt->id);
		Pcrt = Pcrt->next;
	}
	printf("->NULL");
	return 0;
}
//�������
int SListdestory(node* head) {
	int i = 0;
	node* tmp = NULL;
	while (head != NULL) {
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
		i++;
	}
	printf("%d\n",i);
	return 0;
}
int SListnodedel(node* head, int x) {
	node* Ppre = head;
	node* Pcur = head->next;
	int flag = 0;
	while (Pcur != NULL) {
		if (Pcur->id == x) {
			flag = 1;
			break;
		}
		Ppre = Pcur;
		Pcur = Pcur->next;
	}
	if (flag == 1) {
		Ppre->next = Pcur->next;
		free(Pcur);
		Pcur = NULL;
	}
	else {
		return -2;
	}
	return 0;
}
int SListnodeinsert(node* head, int x, int y) {
	node* Ppre = head;
	node* Pcur = head->next;
	while (Pcur!=NULL) {
		if (Pcur->id == x) {//�ҵ���ƥ��Ľڵ�
			break;
		}
		Ppre = Pcur;//����ָ���ָ��ͬʱ����ƶ�
		Pcur = Pcur->next;
	}
	//�������1.�ҵ�ƥ��Ľڵ�2.Pcurָ����NULL��û���ҵ��ڵ�
	//���½ڵ㶯̬����ռ䣬
	node* Pnew = (node*)malloc(sizeof(node));
	Pnew->id = y;
	Ppre->next = Pnew;
	Pnew->next = Pcur;
	return 0;
}
int main() {
	node* head = NULL;
	head = SListcreat();
	SListprint(head);
	printf("��5ǰ�����4\n");
	SListnodeinsert(head, 5, 4);
	SListprint(head);
	printf("ɾ��5֮��\n");
	SListnodedel(head,5);
	SListprint(head);
	SListdestory(head);
	head = NULL;
	system("pause");
	return 0;
}