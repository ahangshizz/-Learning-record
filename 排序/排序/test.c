#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��������
void QuickSort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	//�ó���׼��(�ڿ�)
	int temp = arr[i];
	//���i>j���˳��ݹ�
	if (i < j) {
		//ѭ�������ڿ�����
		while(i<j) {
			//�����ߵ���������ָ����ǰ�ƶ�,ֱ��i=j������һ����С�ڻ�׼��
			while (i<j&&arr[j]>temp) {
				--j;
			}
			//(�ڿ�)
			//���ҵ�����������ڿӵ�λ��
			if (i < j) {
				arr[i] = arr[j];//(���)
				++i;
			}
			while (i < j&&arr[i] < temp) {//(�ڿ�)
				++i;
			}
			if (i < j) {
				arr[j] = arr[i];//(���)
				--j;
			}
		}
		//���˲�ѭ������,i==j,���԰ѻ�׼���������λ��
		arr[i] = temp;
		//��ʼ�������Ϊ������еݹ�����
		QuickSort(arr, 0, j - 1);
		QuickSort(arr, i + 1, end);
	}
	else {
		return;
	}
}

void Print_arr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ,",arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = { 4,2,5,8,7,1,4,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Print_arr(arr, len);
	QuickSort(arr, 0, len - 1);
	Print_arr(arr, len);
	system("pause");
	return 0;
}