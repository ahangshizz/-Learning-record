#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
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

int main() {
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