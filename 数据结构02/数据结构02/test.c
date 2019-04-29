#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

typedef struct Person {
	//��һ��Ԫ�طŽ��,������ƫ����,�൱�ڹ��Ӱ����ݶ�����һ��
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;
void MyPrint(CircleLinkNode* data) {
	//ǿ������ת��,�ѽ������,ת��Ϊ�û�������
	Person* p = (Person*)data;
	printf("Name=%s Age:=%d Score=%d \n", p->name, p->age, p->score);
}
int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) {
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;
	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age&&p1->score == p2->score) {
		return 0; 
	}
}
int main() {
	//����ѭ������
	CircleLinkList* list = Init_CircleLinkList();

	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	p1.score = 93;
	p2.score = 97;
	p3.score = 96;
	p4.score = 95;
	p5.score = 94;
	//����������
	Insert_CircleLinkList(list, 0, &p1.node);
	Insert_CircleLinkList(list, 0, &p2.node);
	Insert_CircleLinkList(list, 0, &p3.node);
	Insert_CircleLinkList(list, 0, &p4.node);
	Insert_CircleLinkList(list, 0, &p5.node);
	//��ӡ����
	Print_CircleLinkList(list, MyPrint);
	//ɾ�����
	Person Del;
	strcpy(Del.name, "ddd");
	Del.age = 40;
	Del.score = 95;
	RemoveByValue_CircleLinkList(list, &Del.node, MyCompare);
	Print_CircleLinkList(list,MyPrint);
	//�ͷ��ڴ�
	Free_CircleLinkList(list); 
	system("pause");
	return 0;
}