//#include <stdio.h>
//int main()
//{
//	char buf[100] = { 0 };
//	char tmp[100] = { 0 };
//	char str[10];
//	scanf("%s", buf);
//	printf("buf=%s", buf);
//	scanf("%s", tmp);          //�����е��ַ����뻺�������Կո�ָ�����һ��ֻȡһ��
//	printf("tmp=%s", tmp);
//	scanf("%s", str);    //scanf����Խ����
//	printf("str=%s", str);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	/*char buf[100];
//	gets(buf);
//	return 0;*/
//	char buf[10];
//	fgets(buf, sizeof(buf), stdin);//��ȫ������    �м���ʽд�����С    Ϊ\0����һ��λ��
//	printf("buf=%s\n", buf);
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//int main()
//{
//	//char buf[] = "hellomike";
//	char buf[] = "\0hello";
//	int ret = 0;
//	ret = strlen(buf);
//	printf("%d\n", sizeof(buf));//sizeof���������ͳ��ȣ�����\0������ǰ������
//	printf("%d\n", ret);//stelen   ����\0ֱ�ӽ������ԣ�
//	return 0;
//}
//int main()    //�ַ�����copy
//{
//	char buf[] = "wel\0come to bit";
//	char tmp[100];
//	///char a = tmp;
//	//strcpy(a, buf);       //strcpy����\0�Զ�ֹͣ��������strlenһ��
//
//	strncpy(tmp, buf,8);
//	//printf("%s\n", a);
//	printf("%s\n", tmp);  //��ӡ��ʱ������\0�Զ�����
//	return  0;

//int main()
//{
//	char a[100] = " hello ";
//	char b[] = " bit ";
//    strncat(a, b,strlen(" bi"));
//	printf("%s\n", a);
//	return 0;
//}
//int main()
//{
//	char a[] = "nosnoewinoi";
//	char *p = strstr(a, "won");
//	if (p == NULL)
//	{
//		printf("��ѯʧ��\n");
//	}
//	else
//	{
//		printf("%s\n", p);
//	}
//	return 0;
//}
//void fun()
//{
//	printf("hahaha\n");
//	exit(0);
//}
//int main()
//{
//	printf("heheheh\n");
//	while (1)
//	{
//		fun();
//	}
//	return 0;
//}

//�Զ���һ������ʵ��strlen�Ĺ���
//char my_strlen(char tmp[])
//{
//	int i = 0;
//	while (tmp[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	char a[] = "hello bit";
//	int ret = 0;
//	ret = my_strlen(a);
//	printf("%d\n", ret);//������9
//	return 0;
//}
//����һ������  ʵ��strcpy�Ĺ���
//void my_strcpy(char *b, char *a)
//{
//	while (*a != '\0')
//	{
//		*b = *a;
//		*a++;
//		*b++;
//	}*b = *a;
//}
//int main()
//{
//	char ret[] = "welcome to bit";
//	char tmp[100];
//	my_strcpy(tmp,ret);
//	printf("tmp=%s\n", tmp);
//	return 0;
//}
//int main()
//{
//	int *p=0;
//	*p = 100;
//	return 0;
//}
//int main()
//{
//	printf("%d ", sizeof(char));
//	printf("%d ", sizeof(short));
//	printf("%d ", sizeof(int));
//	printf("%d ", sizeof(long));
//	printf("%d ", sizeof(float));
//	printf("%d ", sizeof(double));//   �������һ��ָ������  ��32λ��������ȫ��Ϊ4�ֽڣ���64��������ȫ����Ϊ8�ֽڡ�����
//	return 0;
//}
//int main()
//{
//	void *p = NULL;//���Զ����κ����͵ı�������������ָ�롣
//	int a = 10;
//	p = &a;
//	printf("*P=%d ",*( int *)p);
//	return 0;
//}
int main()
{
	int a;
	int *p = &a;
	printf("p=%p   p+1=%p ", p, p + 1);
	char b;
	char *q = &b;
	printf("q=%p  q+1=%p  ", q, q + 1);
	return 0;
}