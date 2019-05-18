#include "Stack.h"
void StackInit(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	ps->_capacity = 3;
	ps->_size = 0;
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* ps->_capacity);
	if (ps->_array == NULL) {
		assert(ps->_array);
	}
	for (int i = 0; i < ps->_capacity; ++i) {
		ps->_array[i] = 0;
	}
}
//ѹջ
void StackPush(Stack* ps, SDataType data) {
	if (ps == NULL) {
		return;
	}
	if (ps->_size == ps->_capacity) {
		//��������
		ps->_capacity = 2 * ps->_capacity;
		//�����¿ռ�
		SDataType* newspace = (SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
		//��������
		for (int i = 0; i < ps->_size; ++i) {
			newspace[i] = ps->_array[i];
		}
		//�ͷžɿռ�
		free(ps->_array);
		//ָ��ָ���¿ռ�
		ps->_array = newspace;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//��ջ
void StackPop(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	if (ps->_size == 0) {
		printf("ջ�ѿ�\n");
		return;
	}
	ps->_size--;
}
//����ջ��Ԫ��
SDataType StackTop(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	if (ps->_size == 0) {
		printf("ջ����Ԫ��\n");
		return 0;
	}
	return ps->_array[ps->_size - 1];
}
//����ջ����ЧԪ�ظ���
int StackSize(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	return ps->_size;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	if (ps->_size == 0) {
		return 0;
	}
	return 1;
}
//����ջ
void StackDestroy(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	free(ps->_array);
	ps->_array = NULL;
}