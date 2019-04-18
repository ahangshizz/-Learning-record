#define _CRT_SECURE_NO_WARNINGS
#define Max_personinfo 300
#include <stdio.h>
#include <stdlib.h>
//��ϵ�˰���
typedef struct Personinfo {
	char Name[1024];
	char Phone[1024];
}Personinfo;
typedef struct Addressbook {
	Personinfo person[300];
	int size;
}Addressbook;
Addressbook g_addressbook;
void Nothing() {
	//�����ĺ���
}
void Addpersoninfo() {
	printf("�½���ϵ��\n");
	if (g_addressbook.size > Max_personinfo) {
		printf("������ϵ��ʧ��,ͨѶ¼����\n");
		return;
	}
	printf("����������\n");
	Personinfo* person_info = &g_addressbook.person[g_addressbook.size];
	scanf("%s", person_info->Name);
	printf("������绰\n");
	scanf("%s", person_info->Phone);
	++g_addressbook.size;
	printf("�½���ϵ�˳ɹ�\n");
}
void Delpersoninfo() {
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
void Findpersoninfo() {

}
void Modpersoninfo() {

}
void Printallpersoninfo() {
	for (int i = 0; i < g_addressbook.size; ++i) {
		printf("[%d]", i);
		printf("%s", g_addressbook.person[i].Name);
		printf("  ");
		printf("%s\n", g_addressbook.person[i].Phone);
	}
}
void Clearpersoninfo() {

}
void Sortpersoninfo() {

}
void Overapp() {
	printf("Goodbay!");
	exit(0);
}
void init() {
	g_addressbook.size = 0;
	for (int i = 0; i < Max_personinfo; ++i) {
		g_addressbook.person[i].Name[0] = '\0';
		g_addressbook.person[i].Phone[0] = '\0';
	}
}
void menu() {
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
typedef void(*Func)();
int main() {
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