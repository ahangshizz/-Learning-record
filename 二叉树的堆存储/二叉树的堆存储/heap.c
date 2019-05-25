
#include "heap.h"


//��������
void Swap(HPDataType* Left, HPDataType* Right) {
	HPDataType temp = *Left;
	*Left = *Right;
	*Right = temp;
}
//��������
void adjustdown(HPDataType* array, int size, int parent) {
	int child = 2*parent + 1;
	while (child < size) {
		if (array[child] > array[child + 1]&&child+1<size) {
			child = child + 1;
		}
		if (array[child] < array[parent]) {
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			return;
		}
	}
	return;
}
//��������
void adjustup(HPDataType* array, int size, int child) {
	int parent = ((child - 1) >> 1);
	while (parent >= 0) {
		if (array[child] < array[parent]) {
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else {
			return;
		}
	}
	return;
}
//���ݺ���
void CheckCapacity(Heap* hp) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		int newcapacity = hp->_capacity * 2;
		HPDataType* newarray = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (newarray == NULL) {
			assert(newarray);
			return;
		}
		for (int i = 0; i < hp->_size; ++i) {
			newarray[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = newarray;
		hp->_capacity = newcapacity;
	}
}
// �������ʼ����
void InitHeap(Heap* hp, HPDataType* array, int size) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_capacity = size;
	for (int i = 0; i < size; ++i) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;


	//�����������е���,ʹ���Ϊһ����
	int root = (size - 2) >> 1;
	for (; root >= 0; --root) {
		adjustdown(hp->_array, size, root);
	}
}

// ��ʼ��һ���ն�
void InitEmptyHeap(Heap* hp, int capacity) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_size = 0;
	hp->_capacity = capacity;
}

// �ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, HPDataType data) {
	assert(hp);
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	adjustup(hp->_array, hp->_size, hp->_size - 1);
}

// ɾ���Ѷ�Ԫ��
void EraseHeap(Heap* hp) {
	assert(hp);
	Swap(hp->_array[0], hp->_array[hp->_size - 1]);
	hp->_size--;
	adjustdown(hp->_array, hp->_size, 0);
}

// ��ȡ������ЧԪ�ظ���
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

// �����Ƿ�Ϊ�ն�
int HeapEmpty(Heap* hp) {
	assert(hp);
	return 0 == hp->_size;
}

// ��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->_array[0];
}

// ���ٶ�
void DestroyHeap(Heap* hp) {
	if (hp == NULL) {
		return;
	}
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}