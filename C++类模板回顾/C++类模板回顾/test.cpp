#include <iostream>
using namespace std;

template <typename T>
void My_Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << "hello,����ģ��" << endl;
}

int main1() {
	{
		int a = 10;
		int b = 20;
		My_Swap(a, b);
		cout << "a=" << a << "b=" << b << endl;
	}
	{
		char a = 'a';
		char b = 'b';
		My_Swap(a, b);
		cout << "a=" << a << "b=" << b << endl;
	}
	system("pause");
	return 0;
}

//����ģ�屾��:���Ͳ�����

//���ͱ��,��д������,����ģ������ȥ�滻
template <typename T,typename T2>

void Choice_Sort(T arr[], T2 len) {
	T2 i, j;
	T2 tmp;
	for(i = 0; i < len; ++i) {
		for (j = i + 1; j < len; ++j) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
template <typename T,typename T2>

void Print_arr(T arr[], T2 len) {
	for (int i = 0; i < len; ++i) {
		cout << "arr[" << i << "]" << "=" << arr[i] << "     ";
	}
	cout << endl;
}
int main2() {
	{
		int arr[] = { 22,3,543,23,64,65,2,6 };
		int len = sizeof(arr) / sizeof(int);
		Choice_Sort<int,int >(arr, len);
		Print_arr<int, int>(arr, len);
	}
	{
		char buf[] = "dnoawndoiawndo";
		int len = strlen(buf);
		Choice_Sort<char, int>(buf, len);
		Print_arr<char, int>(buf, len);
	}
	system("pause");
	return 0;
}


