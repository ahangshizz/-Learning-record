//#include <stdio.h>
//int main()
//{
//	const int b = 10;//const���εı��������Ա��޸�
//	b = 100;//err
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	char buf[] = "akjefbefbijewf";
//	//�������ҿ����������ͣ���const�����ĸ��ַ�
//	//������ε�ʱ*��˵��ָ��ָ����ڴ治�ܷ����ı䣬��ָ����ָ����ڴ�ֻ�ܶ���������д
//	//������ε���ָ�����p��˵��ָ���ָ���ܷ����ı䣬��ָ���ֵ�������޸�
//	const char *p = buf;
//	char const *p2 = buf;
//	const char * const p3 = buf;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//typedef struct  SKT
//{
//	int a;
//	int b;
//}SKT;
//void fun(SKT *p)
//{
//	//û��const���Σ�ָ����Ա䣬ָ����ָ����ڴ�Ҳ���Ըı䣻
//	//p->a = 10;//ok;
//	//p = NULL;//ok
//}
//void fun1(SKT const *p)
//{
//	//p = NULL;//ok
//	//p->=10;//err
//}
//void fun2(SKT *const p)
//{
//	//p = NULL;//err
//	//p->a = 10;//ok
//}
//void fun3(SKT const *const p)
//{
//	//const�������������Σ�ֻ�ܶ�ȡ
//}
//int main()
//{
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	const int a = 10;
//	//a = 20;//err    const���������ĸ�ֵ��ֱ�ӱ���
//	int *p = &a;
//	*p = 20;
//	printf("a=%d,*p=%d\n", a, *p);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//char getmem(char**p)
//{
//	char *tmp = (char*)malloc(100);
//	strcpy(tmp, "waaeeferg");
//	*p = tmp;
//	return 0;
//}
//int main()
//{
//	char *p = NULL;
//	int ret;
//	ret = getmem(&p);
//	printf("%s", p);
//	free(p);
//	p = NULL;
//	return 0;
//} 

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	char *p[] = { "111111", "222222", "aaaaaa", "bbbbbb" };
//	int i = 0;
//	int j = 0;
//	int n = sizeof(p) / sizeof(p[0]);
//	char *tmp = NULL;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (strcmp(p[j], p[i]) > 0)
//			{
//				tmp = p[i];
//				p[i] = p[j];
//				p[j] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%s", p[i]);
//	}
//	return 0;
//}

//1.
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d  ", i, j, i*j);
//		}printf("\n");
//	}
//	return 0;
//}
//
//2.
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			n++;
//			printf("%d ", i);
//		}
//
//	}printf("n=%d", n);
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0)&(i % 100 != 0) || (i % 400 == 0))
//		{
//			n++;
//		}
//	}printf("%d\n", n);
//	return 0;
//}

//#include <stdio.h>
//void myprintf(char **buf,int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%s\n", buf[i]);
//	}
//}
//void paixu(char **buf, int n)
//{
//	int i = 0;
//	int j = 0;
//	char *tmp=NULL;
//	for (i = 0; i < n-1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (strcmp(buf[j], buf[i]) > 0)
//			{
//				tmp = buf[i];
//				buf[i] = buf[j];
//				buf[j] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	char *tmp = NULL;
//	char *buf[] = { "111111", "222222", "333333", "aaaaaa" };
//	int n = sizeof(buf) / sizeof(buf[0]);
//	printf("����ǰ\n");
//	myprintf(&buf,n);
//	paixu(buf,n);
//	printf("�����\n");
//	myprintf(&buf, n);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void myprintf(char buf[][30],int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%s  ", buf[i]);
//	}
//}
//void paixu(char buf[][30] ,int len)
//{
//	int i = 0;
//	int j = 0;
//	char tmp[30];
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = i + 1; j < len; j++)
//		{
//			if (strcmp(buf[i], buf[j])>0)
//			{
//				strcpy(tmp, buf[i]);
//				strcpy(buf[i], buf[j]);
//				strcpy(buf[j], tmp);
//			}
//		}
//	}
//}
//int main()
//{
//	int num = 4;
//	char buf[][30] = { "222222","111111", "333333", "aaaaaa" };
//	int len = sizeof(buf) / sizeof(buf[0]);
//	printf("����ǰ\n");
//	myprintf(buf,len);
//	paixu(buf,len);
//	printf("�����\n");
//	myprintf(buf,len);
//	return 0;
//}

