//ָ������
//a �������׵�ַ
//a+i  ��i�е�ַ
//*��a+i����i����Ԫ�ص�ַ
//*��a+i��+j��i�е�j��Ԫ�صĵ�ַ
//*��*��a + i�� + j����i�е�j��Ԫ��ֵ

//#include <stdio.h>
//struct teacher
//{
//	char name[50];
//	int age;
//};
//struct teacher t1 = { "linda", 18 };
//struct teacher t2;
//int main()
//{
//	printf("%s %d", t1.name, t1.age);
//	struct teacher *p = NULL;
//	p = &t2;
//	strcpy(p->name, "liming");
//	printf("%s ", p->name);
//	return 0;
//}


//typedef struct teacher
//{
//	char name[50];
//	int age;
//}teacher;
//void copyt(teacher *t3, teacher *t2)
//{
//	*t3 = *t2;
//}
//int main()
//{
//	teacher t1 = { "lily", 22 };
//	teacher t2 = t1;
//	teacher t3;
//	memset(&t3, 0, sizeof(t3));
//	printf("%s %d\n", t2.name, t2.age);
//	copyt(&t3, &t2);
//	printf("%s %d", t3.name, t3.age);
//	return 0;
//}

//typedef struct teacher
//{
//	char name[50];
//	int age;
//}teacher;
////int main()
//{
//	//teacher t1[3] = { "a", 19, "b", 18, "c", 20 };
//	//int i = 0;
//	//for (i = 0; i < 3; i++)
//	//{
//	//	printf("%s %d\n", t1[i].name, t1[i].age);
//	//}
//	teacher *p = (teacher*)malloc(3 * sizeof(teacher));
//	if (p == NULL)
//	{
//		printf("����ʧ��");
//		return -1;
//	}
//	int i = 0;
//	char buf[50];
//	for (i = 0; i < 3; i++)
//	{
//		sprintf(buf, "name%d%d%d", i, i, i);
//		strcpy(p[i].name, buf);
//		p[i].age = 20 + i;
//	}
//	for (i = 0; i < 3; i++)
//	{
//		printf("��%d��:%s %d\n",i+1, p[i].name, p[i].age);
//	}
//
//	free(p);
//	if (p != NULL)
//	{
//		p = NULL;
//	}
//	return 0;
//}

//int main()
//{
//	teacher t;
//	memset(&t, 0, sizeof(t));
//	strcpy(t.name, "lily");
//	printf("%s", t.name);
//	return 0;
//}

//int main()
//{
//	teacher *p = NULL;
//	p = (teacher*)malloc(sizeof(teacher));
//	strcpy(p->name, "lily");
//	printf("%s", p->name);
//	if (p != NULL)
//	{
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//int main()
//{
//	teacher *p = NULL;
//	p = (teacher*)malloc(sizeof(teacher) * 3);
//	int i = 0;
//	char buf[50];
//	for (i = 0; i < 3; i++)
//	{
//		sprintf(buf, "name%d", i);
//		strcpy(p[i].name, buf);
//		printf("%s \n", p[i].name);
//	}
//	if (p != NULL)
//	{
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}

//typedef struct teacher
//{
//	char **sut;
//}teacher;
//int main()
//{
//	teacher **name;
//	name = (char **)malloc(sizeof(teacher) * 3);
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		name[i] = (char*)malloc(30);
//		strcpy(name[i], "lilei");
//	}
//	for (i = 0; i < 3; i++)
//	{
//		printf("%s ", name[i]);
//	}
//	for (i = 0; i < 3; i++)
//	{
//		if (name[i]!=NULL)
//		{
//			free(name[i]);
//			name[i] = NULL;
//		}
//	}
//	if (name != NULL)
//	{
//		free(name);
//		name = NULL;
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//typedef struct teacher
//{
//	char *name;
//	int age;
//}teacher;
//int main()
//{
//	teacher t1;
//	t1.name = (char*)malloc(30);//��name��̬����ռ�
//	strcpy(t1.name, "liming");//�����ֳ����������ݿ�����t1.name
//	t1.age = 22;
//	teacher t2 = t1;//�ṹ���ǳ����
//	printf("%s %d", t2.name, t2.age);
//	if (t1.name != NULL) //�ͷŷ����t1.name �Ķ����ռ�
//	{
//		free(t1.name);
//		t1.name = NULL;
//	}                  //C�����в��ܴ��ڶ����ͷţ��ᵼ�³�����������滭���ڴ�ͼ�����Կ���t1.name��t2.nameָ��ͬһ�ڴ�
//	//if (t2.name != NULL)         
//	//{
//	//	free(t2.name);
//	//	t2.name = NULL;
//	//}
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct teacher
//{
//	char *name;
//	int age;
//}teacher;
//int main()
//{
//	teacher t1;
//	t1.name = (char*)malloc(30);
//	strcpy(t1.name, "lily");
//	t1.age = 22;
//	teacher t2;
//	t2 = t1;
//	t2.name = (char*)malloc(30);
//	strcpy(t2.name, t1.name);
//	printf("%s %d", t2.name, t2.age);
//	if (t1.name != NULL)
//	{
//		free(t1.name);
//		t1.name = NULL;
//	}
//	if (t2.name != NULL)
//	{
//		free(t2.name);
//		t2.name = NULL;
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char buf[50];
//	FILE *fp = fopen("./01.txt", "r");
//	fgets(buf[50], fp);
//	fclose(fp);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//	//char buf[]="welcome to bit";
//	//FILE *p = NULL;
//	//p = fopen("./03.txt", "w");
//	//fputs(buf, p);
//	//char buf[50];
//	//FILE *fp = NULL;
//	//fp = fopen("./03.txt", "r");
//	//char *ret =fgets(&buf, 50, fp);
//	//printf("%s\n", buf);
//	//printf("ret=%s\n", ret);
//	//fclose(fp);
//	char buf[10];
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		buf[i] = fgetc(stdin);
//	}
//	printf("%s\n", buf);
//	system("pause");
//	return 0;
//}

//typedef struct skt
//{
//	char name[50];
//	int id;
//}skt;
//int main()
//{
//	skt s[3];
	//int i = 0;
	//char buf[50];
	//for (i = 0; i < 3; i++)
	//{
	//	sprintf(buf, "name%d%d%d\n", i, i, i);
	//	strcpy(s[i].name, buf);
	//	s[i].id = i + 61330;
	//}
	//FILE *fp = fopen("./02.txt", "w");
	//for (i = 0; i < 3; i++)
	//{
	//	fwrite(s, sizeof(s), 3, fp);
	//}
	//fclose(fp);
	//fp = NULL;

	//FILE *fp = fopen("./02.txt", "r");
	//fread(s, sizeof(s), 3, fp);
	//int i = 0;
	//for (i = 0; i < 3; i++)
	//{
	//	printf("%s %d\n", s[i].name, s[i].id);
	//}
	//fclose(fp);
	//fp = NULL;
//
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void my_fprintf(char *path)
{
	FILE *fp = NULL;
	fp = fopen("path", "w");
	fprintf(fp, "i am  pig=%d", 250);
	fclose(fp);
	fp = NULL;
}
void my_fscanf(char *path)
{
	int a = 0;
	FILE *fp = fopen("path", "r");
	fscanf(fp,"i am  pig=%d", &a);
	printf("a=%d", a);
	fclose(fp);
	fp = NULL;
}
int main()
{
	my_fprintf(".. / 05.txt");
	my_fscanf("../05.txt");
	system("pause");
	return 0;
}