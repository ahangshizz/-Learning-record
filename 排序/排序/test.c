#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if 0
//快速排序
void QuickSort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	//拿出基准数(挖坑)
	int temp = arr[i];
	//如果i>j则退出递归
	if (i < j) {
		//循环进行挖坑填数
		while(i<j) {
			//如果后边的数大于则指针向前移动,直到i=j或者有一个数小于基准数
			while (i<j&&arr[j]>temp) {
				--j;
			}
			//(挖坑)
			//把找到的这个数放在坑的位置
			if (i < j) {
				arr[i] = arr[j];//(填坑)
				++i;
			}
			while (i < j&&arr[i] < temp) {//(挖坑)
				++i;
			}
			if (i < j) {
				arr[j] = arr[i];//(填坑)
				--j;
			}
		}
		//当此层循环结束,i==j,所以把基准数放在这个位置
		arr[i] = temp;
		//开始把数组分为两半进行递归排序
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
#endif

#if 0
void Print_arr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ,", arr[i]);
	}
	printf("\n");
}
void insertsort(int arr[], int size) {
	int j;
	for (int i = 1; i < size; ++i) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
		}
	}
}
void Bubblesort(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	int arr[5];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; ++i) {
		arr[i] = rand() % 10;
	}
	Print_arr(arr, 5);
/*	insertsort(arr, 5);*/
	Bubblesort(arr, 5);
	Print_arr(arr, 5);
	system("pause");
	return 0;
}
#endif
