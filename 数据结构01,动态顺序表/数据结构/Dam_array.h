#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����һ���ṹ��
//�������capacity   ��Ч����  size   ָ��   
typedef struct Damarray {
	int* p_array;
	int capacity;//��������
	int size;//��ǰ��ЧԪ��
}Damarray;
//��ʼ��
Damarray* Init_array();
//����Ԫ��
void Pushback_array(Damarray* arr,int value);
//����λ��ɾ��
void RemoveBypos_array(Damarray* arr,int pos);
//����ֵɾ��
void RemoveByvalue_array(Damarray* arr, int value);
//����
void Find_array(Damarray* arr, int value);
//��ӡ����
void Printf_array(Damarray* arr);
//�ͷŶ�̬������ڴ�
void FreeSpace_array(Damarray* arr);
//�������
void Clear_array(Damarray* arr);
//��ö�̬���������
void Capacity_array(Damarray* arr);
//��ö�̬���鵱ǰԪ�ظ���
void Size_array(Damarray* arr);
//��ȡĳ��λ�õĵ�ǰԪ��
void At_array(Damarray* arr, int pos);