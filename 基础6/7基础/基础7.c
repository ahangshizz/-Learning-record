#include <stdio.h>
#include <windows.h>
#include <string.h>
//int main()
//{    
//	char a[20];
//	again:
//	printf("��ļ��������������֮��ػ���������֮�����롱���������Զ�ȡ���ػ�\n");
//	system("shutdown -s -t 120");
//	scanf("%s", &a);
//	if (strcmp(a, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//struct student
//{
//	int age;
//	char add[50];
//	int tel;
//};
//int main()
//{
//	struct student skt;
//	struct student tmp;
//	tmp.add[50] = "welcome to bit";
//	tmp.age = 18;
//	tmp.tel = 183;
//	struct student *p;
//	p = &tmp;
//	strcpy(p->add[50], "welcome to bit");
//	p->age = 20;
//	p->tel = 177;
//	strcpy((*p).add[50],"61163");
//	p[0].age = 23;
//	return 0;
//}


//struct student
//{
//	int a;
//	char c[20];
//	int b;
//};
//int main()
//{
//	/*struct student s1 = { 12, "mike",20 };
//	struct student s2;
//	s2 = s1;
//	printf("%d,%s,%d", s1.a, s1.c, s1.b);*/
//	struct student *p;
//	p = (struct student*)malloc(sizeof(struct student));
//	if (p == NULL)
//	{
//		printf("����ʧ��");
//	}
//	else
//	{
//		p->a = 10;
//		p->b = 50;
//	}
//	printf("%d, %d", p->a, p->b);
//	free(p);
//	return 0;
//}
//
//struct skt
//{
//	char *p;
//};
//int main()
//{
//	struct skt tmp;
//	char buf[100];
//	tmp.p= &buf;
//	strcpy(tmp.p, "welcome to bie ");
//	//tmp.p = "welcome to bit";
//	printf("%s", tmp.p);
//	printf("buf=%s", buf);
//	return 0;           //�δ���      �Ƿ������ڴ�
//}

//int main()
//{
//	struct skt tmp;
//	
//	tmp.p = (char*)malloc(strlen("welcome to bit")+1);
//	if (tmp.p == NULL)
//	{
//		printf("����ʧ��");
//	}
//	else
//	{
//		strcpy(tmp.p, "welcome to bit");
//		printf("%s", tmp.p);
//	}
//	free(tmp.p);
//	return 0;
//}


//FILE *fp   //1.���ļ�fopen����   2.��д�ļ�   fgetc���� fputc����    fgets����  fputs����  3 �ж��ļ�����    4.�ر��ļ�   fclose����
//int main()
//{
//	int a;
//	printf("hehe\n");
//	//fclose(stdout);//�رձ�׼���
//	printf("hahaha\n");
//	perror("ahang");
//	fclose(stderr);//�رմ����ж�
//	perror("ahang\n");
//	printf("������a");
//	fclose(stdin);//�رձ�׼����
//	scanf("%d", &a);
//	printf("a=%d", a);
//	return 0;
//
//}

//int main()
//{
//	FILE *fp = NULL;
//	fp = fopen("./02.txt", "w");
//	if (fp == NULL)
//	{
//		perror(fopen);
//		return 0;
//	}
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

//int main()
//{
//	FILE *fp = NULL;
//	fp = fopen("02.txt", "w");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//	fputc('a', fp);
//	fputc('b', fp);
//	fputc('c', fp);
//	fputc('d', fp);
//	fputc('e', fp);
//	fputc('a', stdout);
//	fputc('b', stdout);
//	fputc('c', stdout);
//	fputc('d', stdout);
//	fputc('e', stdout);
//
//	
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

//void file()
//{
//	FILE *fp = fopen("03.txt", "r");
//	if (fp==NULL)
//	{
//		printf("��ʧ��");
//	}
	//char *p = "welcome to bit";
	//int i = 0;
	//int n = strlen(p);
	//for (i = 0; i < n; i++)
	//{
	//	fputc(p[i], fp);
	//}
//	char ch;
//	ch = fgetc(fp);
//	printf("%c", ch);
//	ch = fgetc(fp);
//	printf("%c", ch);
//	ch = fgetc(fp);
//	printf("%c", ch);
//	ch = fgetc(fp);
//	printf("%c", ch);
//	ch = fgetc(fp);
//	printf("%c", ch);
//	while (1)
//	{
//		ch = fgetc(fp);
//		if (ch == -1)
//		{
//			break;
//		}
//		printf("%c", ch);
//	}
//	fclose(fp);
//	fp = NULL;
//}
//int main()
//{
//	file();
//	return 0;
//}

//void fput()
//{
//	FILE *fp = fopen("04.txt", "w");
//	if (fp == NULL)
//	{
//		perror("����ʧ��");
//	}
//	fputc('a', fp);
//	fputc('b', fp);
//	fputc('c', fp);
//	fputc(-1, fp);
//	fputc('d', fp);
//	fputc(-1, fp);
//	fputc('e', fp);
//	fclose(fp);
//}
//void fget()
//{
//	FILE *fp = fopen("04.txt", "r");
//	if (fp==NULL)
//	{
//		perror("��ʧ��");
//		return 0;
//	}
//	char ch=0;
//	while (1)
//	{
//		if (feof(fp))//           feof�ж��ļ���β������ļ���β������
//		{
//			break;
//		}
//		ch = fgetc(fp);
//		printf("%c ", ch);
//	}
//	fclose(fp);
//}
//int main()
//{
//	//fput();
//	fget();
//	return 0;
//}
//void fget()
//{
//	FILE *fp = fopen("04.txt", "r");
//	while (1)
//	{
//		char ch = fgetc(fp);
//		if (feof(fp))
//		{
//			break;
//		}
//		printf("%d ", ch);
//	}
//	fclose(fp);
//	fp = NULL;
//}
//int main()
//{
//	fget();
//	return 0;
//}


void fput()
{
	FILE *fp = fopen("05.txt","w");
	fputs("welcome to bit\n",fp);
	fputs("woshinibaba erzi", fp);
	fclose(fp);
	fp = NULL;
}
void fget()
{
	FILE *fp = fopen("05.txt", "r");
	
		//char ch[100];
		//fgets(ch,sizeof(ch),fp);
		//printf("%s", ch);
		//fgets(ch, sizeof(ch), fp);
		//printf("%s", ch);
		//memset(ch, 0, sizeof(ch));
		//fgets(ch, sizeof(ch), fp);
		//printf("%s", ch);
		//fgets(ch, sizeof(ch), fp);
		//printf("%s", ch);
//	while (1)
//	{
//		if (feof(fp))
//		{
//			break;
//		}
//		char ch[100];
//		fgets(ch, sizeof(ch), fp);
//		printf("%s", ch);
//	}
//
//}
//int main()
//{
//	fget();
//	return 0;
//}