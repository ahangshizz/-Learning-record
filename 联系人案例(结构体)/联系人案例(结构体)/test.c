#define _CRT_SECURE_NO_WARNINGS
#define Max_personinfo 1000//���������ϵ����Ϊ1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ϵ�˰���
typedef struct Personinfo {//����һ���ṹ��,�ṹ���ԱΪ����,�绰
	char Name[1024];
	char Phone[1024];
}Personinfo;
typedef struct Addressbook {//����ṹ��������һ���ṹ�������,��һ����������
	Personinfo person[Max_personinfo];
	int size;
}Addressbook;
Addressbook g_addressbook;//ȫ�ֱ���,�ѽṹ��ʵ�廯
void Nothing() {
	//�����ĺ���
}
void Addpersoninfo() {//�����ϵ�˺���
	printf("�½���ϵ��\n");
	if (g_addressbook.size > Max_personinfo) {
		printf("������ϵ��ʧ��,ͨѶ¼����\n");
		return;
	}
	printf("����������\n");
	//��һ��ָ�뱣������,�������д����
	Personinfo* person_info = &g_addressbook.person[g_addressbook.size];
	scanf("%s", person_info->Name);
	printf("������绰\n");
	scanf("%s", person_info->Phone);
	++g_addressbook.size;
	printf("�½���ϵ�˳ɹ�\n");
}
void Delpersoninfo() {//ɾ����ϵ�˺���
	printf("ɾ����ϵ��\n");
	if (g_addressbook.size <= 0) {
		printf("ɾ��ʧ��,ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ�������\n");
	int id;
	scanf("%d", &id);
	if (id<0 || id>g_addressbook.size) {
		printf("ɾ��ʧ��,�������\n");
		return;
	}
	g_addressbook.person[id]=g_addressbook.person[g_addressbook.size-1];
	--g_addressbook.size;
	printf("ɾ����ϵ�˳ɹ�\n");
}
void Findpersoninfo() {//������ϵ�˺���
	printf("������ϵ��\n");
	char name[1024] = { 0 };
	printf("������Ҫ������ϵ�˵�����\n");
	scanf("%s", name);
	for(int i=0;i<g_addressbook.size;++i) {
		Personinfo* info = &g_addressbook.person[i];
		if (strcmp(name, info->Name)==0) {
			printf("[%d] %s %s\n", i, info->Name, info->Phone);
		}
	}
	printf("������ϵ�˳ɹ�\n");

}
void Modpersoninfo() {//�޸���ϵ�˺���
	printf("�޸���ϵ��\n");
	if (g_addressbook.size <= 0) {
		printf("ͨѶ¼Ϊ��,����ʧ��\n");
	}
	printf("������Ҫ������ϵ�˵����:\n");
	int id;
	scanf("%d", &id);
	Personinfo* info = &g_addressbook.person[id];
	char name[1024] = { 0 };
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", name);
	if (name != NULL) {
		strcpy(info->Name, name);
	}
	char phone[1024] = { 0 };
	printf("������Ҫ�޸ĵĵ绰\n");
	scanf("%s", phone);
	if (phone != NULL) {
		strcpy(info->Phone, phone);
	}
	printf("�޸���ϵ�˳ɹ�\n");
}
void Printallpersoninfo() {//��ӡ��ϵ�˺���
	for (int i = 0; i < g_addressbook.size; ++i) {
		printf("[%d]", i);
		printf("%s", g_addressbook.person[i].Name);
		printf("  ");
		printf("%s\n", g_addressbook.person[i].Phone);
	}
}
void Clearpersoninfo() {//�����ϵ�˺���
	printf("���������ϵ��\n");
	printf("��ȷ��Ҫ���������ϵ����? Y\\N \n");
	char choice[1024] = {0};
	scanf("%s", choice);
	if (strcmp(choice,'Y')==0) {
		g_addressbook.size = 0;
	}
	else {
		printf("���������ϵ��ȡ��\n");
		return;
	}
	printf("���������ϵ�˳ɹ�\n");
}
void Sortpersoninfo() {//��������ĸ������ϵ��
	int i, j;
	for (i = 0; i < g_addressbook.size - 1; ++i) {
		for (j = 0; j < g_addressbook.size - i - 1; ++j) {
			if (strcmp(g_addressbook.person[j].Name, g_addressbook.person[j + 1].Name) > 0) {
				char tmp[1024] = { 0 };
				//�ַ���֮��ĸ�ֵ��Ҫ�õ�strcpy
				strcpy(tmp,g_addressbook.person[j].Name);
				strcpy(g_addressbook.person[j].Name, g_addressbook.person[j + 1].Name);
				strcpy(g_addressbook.person[j + 1].Name, tmp);
			}
		}
	}
}
void Overapp() {//��������ĺ���
	printf("Goodbay!");
	exit(0);
}
void init() {//��ʼ��ͨѶ¼����
	g_addressbook.size = 0;
	for (int i = 0; i < Max_personinfo; ++i) {
		g_addressbook.person[i].Name[0] = '\0';
		g_addressbook.person[i].Phone[0] = '\0';
	}
}
void menu() {//�˵�����
	printf("===================\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ӡ��ϵ��\n");
	printf("6.�����ϵ��\n");
	printf("7.������ϵ��\n");
	printf("8.�˳�\n");
	printf("===================\n");
}
typedef void(*Func)();//����һ������ָ��
int main() {
	//�Ѻ�����ת�Ʊ��װ����
	Func arr[] = {
		Nothing,
		Addpersoninfo,
		Delpersoninfo,
		Findpersoninfo,
		Modpersoninfo,
		Printallpersoninfo,
		Clearpersoninfo,
		Sortpersoninfo,
		Overapp
	};
	init();
	while (1) {
		menu();
		int choice;
		printf("���������ѡ��:");
		scanf("%d", &choice);
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("�������ѡ������,����������\n");
			continue;
		}
		arr[choice]();
	}
	return 0;
}