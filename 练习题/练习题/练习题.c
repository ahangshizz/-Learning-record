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
int main() {
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