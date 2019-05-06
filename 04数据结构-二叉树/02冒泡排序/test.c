#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>
#define MAX 50000
long getsystemtime() {
	//ϵͳ����
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
void My_Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				My_Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void Print_Arr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	srand((unsigned int)time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	//printf("����ǰ\n");
	//Print_Arr(arr, MAX);
	//��ȡϵͳʱ��,�鿴ð�������Ч��
	long start_time = getsystemtime();
	BubbleSort(arr, MAX);
	long end_time = getsystemtime();
	printf("ð������%d��Ԫ������ʱ����%d", MAX, end_time - start_time);
	//printf("�����\n");
	//Print_Arr(arr, MAX);
	system("pause");
	return 0;
}