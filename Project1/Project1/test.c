#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
//malloc  ��̬�����ڴ�ռ�
int main() {
	char buf[20] = "welcome to xian";
	char* name;
	name = (char*)malloc(sizeof(char) * 20);
	strcpy(name, buf);
	printf("%s\n", name);
	free(name);
	if (name != NULL) {
		name = NULL;
	}
	return 0;
}
#endif
#if 0
//calloc��̬�����ڴ�ռ�

int main() {
	int* p;
	p = (int*)calloc(10, 4);
	for (int i = 0; i < 10; ++i) {
		p[i] = 2 * i + 1;
		printf("p[%d]=%d\n", i, p[i]);
	}
	free(p);
	if (p != NULL) {
		p = NULL;
	}
	return 0;
}
#endif

//realloc���¹涨������ڴ�

int main() {
	char*p = (char*)malloc(sizeof(char) * 2);
	strcpy(p, "p");
	//realloc�����е�ָ�������malloc,calloc,realloc�ķ���ֵ
	//���realloc������ڴ��С���ھ�ָ���С,�����·������ڴ�,
	//�ɵ�ָ���Զ��ͷ�,��ΪҰָ��,��������Ұָ�����ڷǷ�����
	char* p2=realloc(p, sizeof(char) * 30);
	//�����ж�һ��,�������ʧ��ֱ�ӷ���
	if (p2 == NULL) {
		printf("��̬�ڴ����ʧ��\n");
		return -1;
	}
	strcpy(p2, "welcome to xian!");
	printf("%s\n", p2);
	//free(p);//����������ָ��,���ڷǷ�����
	//p = NULL;
	free(p2);
	p2 = NULL;
	return 0;
}