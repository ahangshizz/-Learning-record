#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

void test01() {
	//��ʼ��
	LinkList* list = Init_LinkList();
	//�����½��
	for (int i = 0; i < 15; ++i) {
		Insert_LinkList(list, i, 2 * i);
	}
	//��ӡ���
	Printf_LinkList(list);
	//ɾ�����
	Remove_LinkList(list, 5);
	Printf_LinkList(list);
	//����
	Find_LinkList(list, 10);
	//�ͷ��ڴ�
	Free_LinkList(list);
}
int main() {

	test01();
	system("pause");
	return 0;
}