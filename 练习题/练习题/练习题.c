#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//1.����Ļ���������ͼ����
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
int main1() {
	int i = 0;
	int n;
	int j = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j < i + 1; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	for (i = n; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			putchar('*');
		}
		putchar('\n');
	}
	putchar('\n');
	system("pause");
	return 0;
}
//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number����
��ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
*/

int main2() {
	int i = 0;
	for (i = 100; i <= 999; i++) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100;
		if ((pow(a , 3) + pow(b , 3) + pow(c , 3)) == i) {
			printf("%d  ", i);
		}
	}
	system("pause");
	return 0;
}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

int main3() {
	int n;
	int i;
	int sum=0;
	scanf("%d", &n);
	int tmp = n;
	for (i = 0; i < 5; i++) {
		sum = sum + n;
		n = n * 10 + tmp;//������ʱ�����������������
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}


//1.��ɲ�������Ϸ��

void nemu() {//����һ����Ϸ�˵�
	printf("*****************\n");
	printf("****1.��ʼ��Ϸ***\n");
	printf("****2.�˳���Ϸ***\n");
	printf("****3.�����Ļ***\n");
	printf("*****************\n");
}
void Game() {//����һ����Ϸ����
	int num = 0;
	int g_n = 0;
	srand((unsigned)time(NULL));//���������,���������
	num = rand() % 101;//����0-100�������
	while (1) {//��ѭ���н��бȶ�
		printf("��������µ�����: ");
		scanf("%d", &g_n);
		if (g_n < num) {
			printf("�����������̫С��\n");
		}
		else if (g_n > num) {
			printf("�����������̫����\n");
		}
		else if(g_n==num) {
			printf("��ϲ��¶���!");
			break;
		}
	}
}
int main4() {
	int num=0;
	do//do while���ѭ����Ϸ�˵�
	{
		nemu();
		printf("������ѡ��:  ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Game();
			break;
		case 2:
			return ;
		case 3:
			system("cls");
			break;
		default://�û��������벻��ȷ������,default�����б�Ҫ
			printf("���������������");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}





//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�


int mystr(int arr[20],int len,int a) {
	int i = 0;
	int L = 0;
	int R = len-1;
	while (L <= R) {
		if (arr[(L + R) / 2] > a) {
			R = (L + R) / 2 - 1;
		}
		else if (arr[(L + R) / 2] < a) {
			L = (L + R) / 2 + 1;
		}
		else if (arr[(L + R) / 2] == a) {
			return (L + R) / 2;
		}
		else {
			return -1;
		}

	}
	return -1;
}
int main5() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = mystr(arr, len,6);
	printf("%d\n", ret);
	system("pause");
	return 0;
}




//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

int main6() {
	int i = 0;
	for (i = 0; i < 3; i++) {
		char arr[10] = { 0 };
		printf("�������������: \n");
		scanf("%s", arr);
		if (strcmp(arr, "123456") != 0) {
			printf("���������������\n");
			continue;
		}
		else {
			printf("��������ɹ�!");
			break;
		}
	}
	if (i == 3) {
		printf("�����������,�����˳�\n");
	}
	system("pause");
	return 0;
}




//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������


//����ʧ��
int main7() {
	char buf[20];
	while (gets(buf) != EOF) {
		while (buf != '\0') {
			if (buf > 'a'&&buf < 'z') {
				puts(buf - 32);
			}
			else if (buf>'0'&&buf<'9') {
				continue;
			}
			else if (buf>'A'&&buf < 'Z') {
				puts(buf + 32);
			}
			buf + 1;
		}
	}
	system("pause");
	return 0;
}


//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���


void Print() {//��ӡ�˷��ھ���ĺ���
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%2d=%2d  ", j, i, i*j);
		}
		printf("\n");
	}
}
void change(int*a ,int*b) {//�������������ݺ���
	int c = *a;
	*a = *b;
	*b = c;
}
int Isyear(int year) {//�ж��ǲ�������ĺ���
	if (((year % 4 == 0) && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}
int main8() {
	int num = 0;
	scanf("%d", &num);
	int ret=Isyear(num);
	if (ret == 1) {
		printf("%d��������\n", num);
	}
	else {
		printf("%d�겻������\n", num);
	}
	system("pause");
	return 0;
}


//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

void init(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 4 * i + 1;
	}
}
void empty(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 0;
	}
}

void reverse(int arr[], int len) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		++left;
		--right;
	}
}
void printarr(int arr[],int len) {
	for (int i = 0; i < len; ++i) {
		printf("arr[%d]=%d  ", i, arr[i]);
	}
	printf("\n");
}
int main9() {
	int arrA[10] = { 0 };
	init(arrA, 10);
	printarr(arrA, 10);
	reverse(arrA, 10);
	printarr(arrA, 10);
	empty(arrA, 10);
	printarr(arrA, 10);
	system("pause");
	return 0;
}


void Isprime(int num) {
	int i = 0;
	for (i = 2; i < num; ++i) {
		if (num%i == 0) {
			printf("%d��������", num);
			break;
		}
	}
	if (i == num) {

	printf("%d������", num);
	}
}
int main10() {
	Isprime(9);
	system("pause");
	return 0;
}

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��

int mypow(int n, int k) {
	if (k == 1) {
		return n;
	}
	return n*mypow(n, k-1);
}
int main11() {
	int a = mypow(2, 4);
	printf("%d\n", a);
	system("pause");
	return 0;
}


//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
int main12() {
	int ret = DigitSum(123456);
	printf("%d", ret);
	system("pause");
	return 0;
}


//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen

int mystrlen(char* buf) {
	int count = 0;
	while (*buf != '\0') {
		count++;
		*buf++;
	}
	return count;
}
int main13() {
	char buf[] = "welcome to bit";
	int ret = mystrlen(buf);
	printf("%d\n",ret);
	system("pause");
	return 0;
}
//�ݹ�ķ���ʵ��strlen
int mystrlen2(char* buf) {
	if (*buf == '\0') {
		return 0;
	}
	return 1 + mystrlen2(buf + 1);
}
int main14() {
	char buf[] = "welcome to bit";
	int ret = mystrlen2(buf);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//�ݹ�ķ�ʽʵ��n�Ľ׳�
int jiecheng(int n) {
	if (n == 1) {
		return 1;
	}
	return n*jiecheng(n - 1);
}
int main15() {
	int ret = jiecheng(4);
	printf("%d", ret);
	system("pause");
	return 0;
}
//�ǵݹ�ķ�ʽʵ��n�Ľ׳�
int main16() {
	int n = 4;
	int tum = 1;
	for (int i = 1; i <= n; ++i) {
		tum = tum*i;
	}
	printf("%d", tum);
	system("pause");
	return 0;
}

void PRINT(int n) {
	if (n == 0) {
		return;
	}
	if (n < 10) {
		printf("%d\n", n);
	}
	if (n>10) {
	PRINT(n / 10);
	printf("%d\n", n % 10);
	}
}
int main17() {
	PRINT(1729);
	system("pause");
	return 0;
}

int main() { 
	int arr[]={-2,5,4,6,3,8}; 
	int i=0; int j=0; 
	int len=sizeof(arr)/sizeof(arr[0]); 
	for(i=0;i<len-1;i++) { 
		for(j=0;j<len-1-i;j++)  { 
			if(arr[j]>arr[j+1]) { 
			int tmp=arr[j]; 
			arr[j]=arr[j+1]; 
			arr[j+1]=tmp;
			} 
		}
	} 
	for(i=0;i<len;i++) { 
		printf("%d",arr[i]);
	} 
	return 0; 
}
