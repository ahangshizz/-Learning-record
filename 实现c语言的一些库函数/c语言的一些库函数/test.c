#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if 0
//���ڿ⺯��   strtok��ʹ�÷���;
int main() {
	char str[] = "welcome to beijing";
	char* p = strtok(str," ");
	while (p != NULL) {
		printf("%s\n", p);
		p=strtok(NULL, " ");
	}
	return 0;
}
#endif
#if 0
//ʵ��һ���⺯��   strcpy
void Mystrcpy(char* des, const char*src) {
	assert(src != NULL);
	//��Դ�ַ�����ָ��ָ�����ݸ�ֵ��Ŀ��ָ��,Ȼ��ָ����üӼ�,��ָ������ƶ�һλ
	while ((*des++ = *src++)!= '\0') {
		//do nothing 
	}
		*des = '\0';//����Ŀ��ָ��ָ������һ�����ݸ�ֵ0
}
int main() {
	char name[1024] = "welcome to beijing";
	char buf[1024] = { 0 };
	Mystrcpy(buf, name);
	printf("%s\n", buf);
	return 0;
}
#endif
