#include "Dam_array.h"

Damarray* Init_array() {
	//�����ڴ�,�ȸ��ṹ������
	Damarray* myarray = (Damarray*)malloc(sizeof(Damarray));
	myarray->size = 0;
	myarray->capacity = 20;
	//��������������ڴ�
	myarray->p_array = (int*)malloc(sizeof(int)*myarray->capacity);
	return myarray;
}
//����Ԫ��
void Pushback_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//�ж������Ƿ�����
	if (arr->size == arr->capacity) {
		//�Ĳ���ս��
		//��һ������һ����������ڴ�,�µ��ڴ�ռ��Ǿ��ڴ�ռ������
		int* newspace = (int*)malloc(sizeof(int)*arr->capacity * 2);
		//�ڶ����Ѿ��ڴ������,ȫ�����������ڴ�ռ�
		memcpy(newspace, arr->p_array, arr->capacity * sizeof(int));
		//�������ͷž��ڴ�
		free(arr->p_array);
		//���Ĳ���������
		arr->capacity = 2 * arr->capacity;
		arr->p_array = newspace;
	}
	//����Ԫ��
	arr->p_array[arr->size] = value;
	++arr->size;
}
//����λ��ɾ��
void RemoveBypos_array(Damarray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	if (pos<0 || pos>=arr->size) {
		printf("�������λ���ǲ��Ϸ�λ��,����������\n");
		return;
	}
	//ɾ��Ԫ��
	arr->p_array[pos] = arr->p_array[arr->size-1];
	--arr->size;
}
//����ֵɾ��
void RemoveByvalue_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//�ҵ�ֵ��λ��
	int pos = 0;
	for (int i = 0; i < arr->size; ++i) {
		if (arr->p_array[i] == value) {
			pos = i;
			break;
		}
	}
	RemoveBypos_array(arr, pos);
}
//����
void Find_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	int i;
	for (i = 0; i < arr->size; ++i) {
		if (arr->p_array[i] == value) {
			printf("�ҵ���!!\n");
			printf("%d�ǵ�%d��Ԫ��\n", value, i+1);
			break;
		}
	}
	if (arr->size == i) {
		printf("û���ҵ�Ҫ�ҵ�Ԫ��\n");
	}
}
//��ӡ����
void Printf_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < arr->size; ++i) {
		printf("%d ", arr->p_array[i]);
		printf("\n");
	}
}
//�ͷŶ�̬������ڴ�
void FreeSpace_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	if (arr->p_array != NULL) {
		free(arr->p_array);
		arr->p_array = NULL;
	}
	free(arr);
	arr = NULL;
}
//�������
void Clear_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	//����size�����ֵ,��size��Ϊ0,��Ȼ���������
	arr->size = 0;
}
//��ö�̬���������
void Capacity_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	printf("��ǰ��̬�����������%d \n", arr->capacity);
}
//��ö�̬���鵱ǰԪ�ظ���
void Size_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	printf("��ǰ��̬�������ЧԪ�ظ�����%d�� \n", arr->size);
}
//��ȡĳ��λ�õĵ�ǰԪ��
void At_array(Damarray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	printf("%p \n", arr->p_array[pos]);
}