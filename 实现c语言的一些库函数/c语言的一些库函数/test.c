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
#if 0 
//ģ��ʵ��strcat
void Mystrcat(char* des, const char* src) {
	assert(src != NULL);
	while (*des!='\0') {
		des++;//�ҵ�Ŀ���ַ�����'\0',�����￪ʼƴ��
	}
	while (*des++ = *src++) {//��Դ�ַ�����ֵ��Ŀ���ļ�,Ȼ��ָ�������
		;//��ʼƴ��
	}
	*des = '\0';//��Ŀ���ļ���ĩβ��ֵ'\0'
}
int main() {
	char array[64] = "i am a";
	char array2[] = " pig";
	Mystrcat(array, array2);
	printf("%s\n", array);
	return 0;
}
#endif
#if 0
//ģ��ʵ��strstr
const char* Mystrstr(const char* des,const char* str) {//const����ָ��ָ�����ݲ��ܱ��ı�
	assert(des != NULL);
	assert(str != NULL);//����,���Ŀ���ļ���Դ�ļ�ΪNULLֱ�ӳ������
	const char* red = des;
	const char* blk = str;
	while (*red) {
		const char* tmp = red;//����һ����ʱ���������Ѿ���⵽��λ��
		while (*blk == *tmp) {
			blk++;
			tmp++;
		}
		if (*blk == '\0') {//�����ɫָ��ָ��'\0'���Ѿ��ҵ�Ҫ���� ���ַ���
			return red;//���ҿ�ʼʱ��ָ��
		}
		blk = str;//�ú�ɫָ�뻹ԭ����Ԫ��λ��
		red++;//��ʼ����һ��Ԫ�ز���
	}
	return NULL;
}
int main() {
	char buf[] = "hello";
	char str[] = "he";
	const char*ret = Mystrstr(buf, str);
	printf("%s\n", ret);
	return 0;
}
#endif
#if 0
//ģ��ʵ��strchr
const char* Mystrchr(const char*dst, const char str) {
	assert(dst != NULL);
	while (*dst!='\0') {//ѭ��������ָ�벻ָ���ַ�����β
		if (*dst == str) {//������,���ؿ�ʼ���ҵ�λ��
			return dst;
		}
		dst++;//ѭ�������Ӽ�
	}
	return NULL;
}
int main() {
	char buf[] = "hello world";
	char*p = Mystrchr(buf, 'o');
	printf("%s", p);
	return 0;
}
#endif
#if 0
//ģ��ʵ��strcmp
int Mystrcmp(const char* arr1, const char* arr2) {
	while ((*arr1!='\0')&&(*arr2!='\0')) {
		if (*arr1 > *arr2) {
			return 1;
		}
		else if (*arr1 < *arr2) {
			return -1;
		}
		else {
			++arr1;
			++arr2;
		}
	}
	if ((*arr1 == '\0')&&(*arr2!='\0')) {
		return -1;
	}
	else if ((*arr2 == '\0') && (*arr1 != '\0')) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	char arr1[] = "xelcome";
	char arr2[] = "welcome";
	int ret = Mystrcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}
#endif
#if 0
//ʵ��memcpy
//�����һ���ַ���ʼ��ǰ����,���Խ���ڴ��ص��Ĳ�������
void* Mymemcpy(void* dest, const void* src, size_t count) {
	assert(dest != NULL);
	assert(src != NULL);
	char* p = (char*)dest+(count-1);//ָ��ǿ��ת����char*����,������ƶ������һ��Ԫ��
	const char*p1 = (char*)src+(count-1);//ָ��ǿ��ת����char*����,������ƶ������һ��Ԫ��
	while (count--) {
		*p = *p1;
		--p;//�Ӻ���ǰ����
		--p1;
	}
	return dest;//����ֵΪĿ���ַ���
}
int main() {
	char buf1[] = "welcome";
	char buf2[64] = { 0 };
	Mymemcpy(buf2, buf1, 4);
	printf("%s\n", buf2);
	return 0;
}
#endif
