#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void memu()
{
	printf("********************\n");
	printf("*1.�������ļ�      *\n");
	printf("*2.д�����ļ�      *\n");
	printf("*3.����            *\n");
	printf("*4.�˳�            *\n");
	printf("********************\n");
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
	return 0;
}