#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "cgd.h"
#define CGDNAME "my.ini"
void memu()
{
	printf("********************\n");
	printf("*1.�������ļ�      *\n");
	printf("*2.д�����ļ�      *\n");
	printf("*3.����            *\n");
	printf("*4.�˳�            *\n");
	printf("********************\n");
}

void Myread()
{
	int len = 0;
	int ret = 0;
	char key[256] = { 0 };
	char value[1024] = { 0 };
	printf("������key��ֵ:");
	scanf("%s", key);
	ret=ReadcgdFile(CGDNAME, key, value, &len);
	if (ret!=0)
	{
		printf("ReadcgdFile ����");
		return -1;
	}
	printf("key=%s\n", key);
	printf("value=%s\n", value);
	printf("len=%d\n", len);
}
void Mywrite()
{
	int ret = 0;
	char key[256] = { 0 };
	char value[1024] = { 0 };
	printf("������key��ֵ:");
	scanf("%s", key);
	printf("������value��ֵ:");
	scanf("%s", value);
	ret = WritecgdFile(CGDNAME, key, value, strlen(value));
	if (ret != 0)
	{
		printf("WritecgdFile ����");
		return -1;
	}
	printf("key=%s\n", key);
	printf("value=%s\n", value);
	printf("len=%d\n", strlen(value));
}
int main()
{
	int cmd;
	while (1)
	{
		memu();
		printf("cmd:");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			Myread();
			break;
		case 2:
			break;
		case 3:
			system("cls");
			break;
		case 4:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}