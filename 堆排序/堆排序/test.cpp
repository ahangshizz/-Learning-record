#include <iostream>
using namespace std;



void Swap(int* arr,int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void AdJust(int* arr, int parent, int len) {
	//���ӵı�ŵ��ڸ��ױ�ŵĶ�����һ
	int child = 2 * parent + 1;
	while (child<len) {
		//���Ӻ��Һ��ӽ��бȽ�
		if (child + 1 < len&&arr[child + 1] > arr[child]) {
			//����Һ��Ӵ�,���ӱ�ŵ��Һ�������
			child = child + 1;
		}
		//������ӱȸ��״�
		if (arr[child] > arr[parent]) {
			//�����������
			Swap(arr,child,parent);
			//��Ϊ������ݴ��Һ��������,��Ҫ�Ժ�����������,
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
		
	}

}
void Print(int arr[],int  len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void HeapSort(int* arr, int len) {
	//�ѵ����һ����Ҷ�ӽ���㷨
	//��Ϊlen��Ԫ�ظ�������,���,������Ҫ���һ��1
	int root = ((len-1-1)>>1);
	//�����һ����Ҷ�ӽ����ǰһֱ����
	//�Ѷ��ų�һ�����
	for (root; root >= 0; --root) {
		AdJust(arr, root, len);
	}
	//��Ϊ����Ժ���Ҫ��������,�ѶѶ�Ԫ�غ����һ�������н���,Ȼ���ظ������ѵ�λ��
	//
	for (int i = len - 1; i > 0; --i) {
		Swap(arr, i, 0);
		AdJust(arr, 0, i);
	}
	return;
}

int main() {

	int array[] = { 4,2,8,5,0,9,3,1 };
	int len = sizeof(array) / sizeof(array[0]);
	Print(array, len);
	HeapSort(array, len);
	Print(array, len);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}



//��������
#if 0
void Print(int* arr,int  len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void Swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void AdJust(int arr[], int parent, int len) {
	int child = 2 * parent + 1;
	while (child < len) {
		if (child + 1 < len&&arr[child + 1] > arr[child]) {
			child = child + 1;
		}
		if (arr[parent] < arr[child]) {
			Swap(arr, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
	return;
}
void HeapSort(int arr[], int len) {
	//���ɶ�
	int root = ((len - 1 - 1) >> 1);
	for (; root >= 0; --root) {
		AdJust(arr, root, len);
	}
	for (int i = len - 1; i > 0; --i) {
		Swap(arr, i, 0);
		AdJust(arr, 0, i);
	}
}
int main() {
	int arr[] = { 4,6,3,8,1,0,2,5,9,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Print(arr, len);
	HeapSort(arr, len);
	Print(arr, len);
	system("pause");
	return 0;
}
#endif