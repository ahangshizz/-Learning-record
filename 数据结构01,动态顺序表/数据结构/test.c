#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dam_array.h"

//����д�õĶ�̬����

void test01() {
	//��ʼ������
	Damarray* myarray = Init_array();
	//����Ԫ��
	for (int i = 0; i < 10; ++i) {
		Pushback_array(myarray, 2 * i);
	}
	//��ӡ����
	Printf_array(myarray);
	//��ӡ����
	Capacity_array(myarray);
	//��ȡ��ǰ��ЧԪ�ظ���
	Size_array(myarray);
	//ɾ��
	RemoveBypos_array(myarray, 5);
	Printf_array(myarray);
	//����Ԫ��
	Find_array(myarray, 6);
	Find_array(myarray, 7);
	//�ͷ�
	FreeSpace_array(myarray);
}
int main() {

	test01();
	system("pause");
	return 0;
}