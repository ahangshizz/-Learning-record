//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };//û��typedef��һ���������
//	int b[100] = { 1, 2, 3, 4 };//û�и�ֵ�Ķ�Ϊ0
//	int i = 0;
//	int n = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < n; i++)
//	{
//		//printf("%d ", a[i]);
//		printf("%d ", *(a + i));              //a[i]==*(a+i)
//	}
//	printf("a:%d,a+1:%d", a, a + 1);
//	printf("&a:%d,&a+1:%d", &a, &a + 1);
//
//	typedef int A[8];//��typedef��������һ����������
//	A n;//�ȼ���int b[8];
//	int j = 0;
//	for (j = 0; j < 8; j++)
//	{
//		n[j] = j++;
//	}
//	for (j = 0; j < 8; j++)
//	{
//		printf("%d ", n[j]);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	typedef int A[8];
//	A b;
//	int i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		b[i] = i + 1;
//	}
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}

#include <stdio.h>
#include <windows.h>
int main01()
{
	//ָ��������һ�����飬ֻ�������е�ÿһ��Ԫ�ض���ָ�룻
	char *a[] = { "aaaaa", "bbbbb", "ccccc" };

	return 0;
}

int main02()
{
	//����ָ������һ��ָ�룬ָ��һ������
	//�ȶ����������ͣ��������Ͷ���ָ�����
	//����ָ����ָ������һά����ģ�����ָ��ĳһ��Ԫ��
	int a[10] = { 0 };
	int i = 0;
	typedef int A[10];
	A *p = NULL;//p����һ������ָ�����ͱ�����
	//p = a;//a����������Ԫ�ص�ַ
	p = &a;//&a���������׵�ַ��ָ��һ��
	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*p)[i]);
	}
	system("pause");
	return 0;
}

int main03()
{
	int a[10] = { 0 };
	int i = 0;
	typedef (*P)[10];
	P p;
	p = &a;
	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{

		printf("%d ", (*p)[i]);
	}
	return 0;
}


int main04()
{
	int a[3][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}
	};
	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int a3[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", a3[i][j]);
		}printf("\n");
	}
	printf("a3:%d,a3+1:%d\n", a3, a3 + 1);//��ά����������������0�е��׵�ַ���������ڵ�0����Ԫ�ص�ַ����Ȼֵһ��������������ͬ����
	printf("&a3:%d,&a3+1:%d\n", &a3, &a3 + 1);
	printf("%d,%d\n", *(a3 + 0), *(a3 + 1));
	printf("%d,%d\n", a3[0], a3[0]+1);//*��a3+i��==a3��i����
	return 0;
}
//void printA(int*a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}printf("\n");
//}
//int main04()
//{
//	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	printA((int*)a, sizeof(a) / sizeof(int));
//	return 0;
//}

//int main()
//{
//	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	int(*p)[4];
//	p = a;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		for (j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



void printarry(int(*a)[4])//����ָ��   ���β�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	printarry(a);
	return 0;
}