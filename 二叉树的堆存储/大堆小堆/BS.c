
#include "BS.h"

int Less(HPDataType Left, HPDataType Right) {
	return Left < Right;
}
int Greater(HPDataType Left, HPDataType Right) {
	return Left > Right;
}
//��������
void Swap(HPDataType* Left, HPDataType* Right) {
	//ʹ��ָ����в���,******��ֵ��ַ
	HPDataType temp = *Left;
	*Left = *Right;
	*Right = temp;
}
//��������
void adjustdown(HPDataType* array, int size, int parent,PCOM compare) {
	//���ݶѵ�����,������ȫ������,����������,�������ұ��,����Ϊi�Ľ��,
	//�����ӱ�ű�Ϊ2i,���Һ��ӱ�ű�Ϊ2i+1,��˫�ױ�ű�Ϊi/2(���ڵ����)
	int child = 2 * parent + 1;
	while (child < size) {
		//�ж϶ѵ����Һ��ӵĴ�С
		if (compare(array[child+1] , array[child]) && child + 1 < size) {

			child = child + 1;
		}
		//����С�ĺ��Ӻ͸��ڵ���бȽ�,���С�ڸ��ڵ�,���������ڵ�
		if (compare(array[child] , array[parent])) {
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			return;
		}
	}
}
//��������
void adjustup(HPDataType* array, int size, int child,PCOM compare) {
	int parent = ((child - 1) >> 1);
	while (parent >= 0) {
		if (compare(array[child] , array[parent])) {
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else {
			return;
		}
	}
}
//���ݺ���
void CheckCapacity(Heap* hp) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		//Ĭ�����ݱ���Ϊ2��,���ݵ��Ĳ���
		int newcapacity = hp->_capacity * 2;
		//����������
		HPDataType* newarray = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (newarray == NULL) {
			assert(newarray);
			return;
		}
		//�Ѿɶ�Ԫ��,ת�Ƶ��¶�
		for (int i = 0; i < hp->_size; ++i) {
			newarray[i] = hp->_array[i];
		}
		//�ͷžɶ�
		free(hp->_array);
		//ָ��ָ���¶�
		hp->_array = newarray;
		//�ı�ѵ�����
		hp->_capacity = newcapacity;
	}
}
// �������ʼ����
void InitHeap(Heap* hp, HPDataType* array, int size,PCOM compare) {
	assert(hp);
	//���ѵ����鿪�ٿռ�
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	//�������е�Ԫ��,ȫ��ת�Ƶ��ѵ�������
	hp->_capacity = size;
	for (int i = 0; i < size; ++i) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->compare = compare;

	//�����������е���,ʹ���Ϊһ����
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root) {
		adjustdown(hp->_array, size, root,hp->compare);
	}
}

// ��ʼ��һ���ն�
void InitEmptyHeap(Heap* hp, int capacity,PCOM compare) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_size = 0;
	hp->_capacity = capacity;
	hp->compare = compare;
}

// �ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, HPDataType data) {
	assert(hp);
	//�ж��Ƿ���Ҫ����
	CheckCapacity(hp);
	//����Ԫ��,Ĭ�϶�β����
	hp->_array[hp->_size] = data;
	hp->_size++;
	//��Ԫ�ؽ���λ�õ���
	adjustup(hp->_array, hp->_size, hp->_size - 1,hp->compare);
}

// ɾ���Ѷ�Ԫ��
void EraseHeap(Heap* hp) {
	assert(hp);
	//�ѶѶ�Ԫ�غͶѵ����һ��Ԫ�ؽ���λ��
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	//��ЧԪ�ؼ�һ,�����һ��Ԫ�ر�ȥ��
	hp->_size--;
	adjustdown(hp->_array, hp->_size, 0,hp->compare);
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