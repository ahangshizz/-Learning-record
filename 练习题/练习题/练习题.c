#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#if 0
//1.����Ļ���������ͼ����
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
int main1() {
	int i = 0;
	int n;
	int j = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j < i + 1; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	for (i = n; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			putchar('*');
		}
		putchar('\n');
	}
	putchar('\n');
	system("pause");
	return 0;
}
//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number����
��ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
*/

int main2() {
	int i = 0;
	for (i = 100; i <= 999; i++) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100;
		if ((pow(a , 3) + pow(b , 3) + pow(c , 3)) == i) {
			printf("%d  ", i);
		}
	}
	system("pause");
	return 0;
}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

int main3() {
	int n;
	int i;
	int sum=0;
	scanf("%d", &n);
	int tmp = n;
	for (i = 0; i < 5; i++) {
		sum = sum + n;
		n = n * 10 + tmp;//������ʱ�����������������
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}


//1.��ɲ�������Ϸ��

void nemu() {//����һ����Ϸ�˵�
	printf("*****************\n");
	printf("****1.��ʼ��Ϸ***\n");
	printf("****2.�˳���Ϸ***\n");
	printf("****3.�����Ļ***\n");
	printf("*****************\n");
}
void Game() {//����һ����Ϸ����
	int num = 0;
	int g_n = 0;
	srand((unsigned)time(NULL));//���������,���������
	num = rand() % 101;//����0-100�������
	while (1) {//��ѭ���н��бȶ�
		printf("��������µ�����: ");
		scanf("%d", &g_n);
		if (g_n < num) {
			printf("�����������̫С��\n");
		}
		else if (g_n > num) {
			printf("�����������̫����\n");
		}
		else if(g_n==num) {
			printf("��ϲ��¶���!");
			break;
		}
	}
}
int main4() {
	int num=0;
	do//do while���ѭ����Ϸ�˵�
	{
		nemu();
		printf("������ѡ��:  ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Game();
			break;
		case 2:
			return ;
		case 3:
			system("cls");
			break;
		default://�û��������벻��ȷ������,default�����б�Ҫ
			printf("���������������");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}





//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�


int mystr(int arr[20],int len,int a) {
	int i = 0;
	int L = 0;
	int R = len-1;
	while (L <= R) {
		if (arr[(L + R) / 2] > a) {
			R = (L + R) / 2 - 1;
		}
		else if (arr[(L + R) / 2] < a) {
			L = (L + R) / 2 + 1;
		}
		else if (arr[(L + R) / 2] == a) {
			return (L + R) / 2;
		}
		else {
			return -1;
		}

	}
	return -1;
}
int main5() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = mystr(arr, len,6);
	printf("%d\n", ret);
	system("pause");
	return 0;
}




//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

int main6() {
	int i = 0;
	for (i = 0; i < 3; i++) {
		char arr[10] = { 0 };
		printf("�������������: \n");
		scanf("%s", arr);
		if (strcmp(arr, "123456") != 0) {
			printf("���������������\n");
			continue;
		}
		else {
			printf("��������ɹ�!");
			break;
		}
	}
	if (i == 3) {
		printf("�����������,�����˳�\n");
	}
	system("pause");
	return 0;
}




//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������


//����ʧ��
int main7() {
	char buf[20];
	while (gets(buf) != EOF) {
		while (buf != '\0') {
			if (buf > 'a'&&buf < 'z') {
				puts(buf - 32);
			}
			else if (buf>'0'&&buf<'9') {
				continue;
			}
			else if (buf>'A'&&buf < 'Z') {
				puts(buf + 32);
			}
			buf + 1;
		}
	}
	system("pause");
	return 0;
}


//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���


void Print() {//��ӡ�˷��ھ���ĺ���
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%2d=%2d  ", j, i, i*j);
		}
		printf("\n");
	}
}
void change(int*a ,int*b) {//�������������ݺ���
	int c = *a;
	*a = *b;
	*b = c;
}
int Isyear(int year) {//�ж��ǲ�������ĺ���
	if (((year % 4 == 0) && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}
int main8() {
	int num = 0;
	scanf("%d", &num);
	int ret=Isyear(num);
	if (ret == 1) {
		printf("%d��������\n", num);
	}
	else {
		printf("%d�겻������\n", num);
	}
	system("pause");
	return 0;
}


//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

void init(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 4 * i + 1;
	}
}
void empty(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 0;
	}
}

void reverse(int arr[], int len) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		++left;
		--right;
	}
}
void printarr(int arr[],int len) {
	for (int i = 0; i < len; ++i) {
		printf("arr[%d]=%d  ", i, arr[i]);
	}
	printf("\n");
}
int main9() {
	int arrA[10] = { 0 };
	init(arrA, 10);
	printarr(arrA, 10);
	reverse(arrA, 10);
	printarr(arrA, 10);
	empty(arrA, 10);
	printarr(arrA, 10);
	system("pause");
	return 0;
}


void Isprime(int num) {
	int i = 0;
	for (i = 2; i < num; ++i) {
		if (num%i == 0) {
			printf("%d��������", num);
			break;
		}
	}
	if (i == num) {

	printf("%d������", num);
	}
}
int main10() {
	Isprime(9);
	system("pause");
	return 0;
}

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��

int mypow(int n, int k) {
	if (k == 1) {
		return n;
	}
	return n*mypow(n, k-1);
}
int main11() {
	int a = mypow(2, 4);
	printf("%d\n", a);
	system("pause");
	return 0;
}


//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
int main12() {
	int ret = DigitSum(123456);
	printf("%d", ret);
	system("pause");
	return 0;
}


//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen

int mystrlen(char* buf) {
	int count = 0;
	while (*buf != '\0') {
		count++;
		*buf++;
	}
	return count;
}
int main13() {
	char buf[] = "welcome to bit";
	int ret = mystrlen(buf);
	printf("%d\n",ret);
	system("pause");
	return 0;
}
//�ݹ�ķ���ʵ��strlen
int mystrlen2(char* buf) {
	if (*buf == '\0') {
		return 0;
	}
	return 1 + mystrlen2(buf + 1);
}
int main14() {
	char buf[] = "welcome to bit";
	int ret = mystrlen2(buf);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//�ݹ�ķ�ʽʵ��n�Ľ׳�
int jiecheng(int n) {
	if (n == 1) {
		return 1;
	}
	return n*jiecheng(n - 1);
}
int main15() {
	int ret = jiecheng(4);
	printf("%d", ret);
	system("pause");
	return 0;
}
//�ǵݹ�ķ�ʽʵ��n�Ľ׳�
int main16() {
	int n = 4;
	int tum = 1;
	for (int i = 1; i <= n; ++i) {
		tum = tum*i;
	}
	printf("%d", tum);
	system("pause");
	return 0;
}

void PRINT(int n) {
	if (n == 0) {
		return;
	}
	if (n < 10) {
		printf("%d\n", n);
	}
	if (n>10) {
	PRINT(n / 10);
	printf("%d\n", n % 10);
	}
}
int main17() {
	PRINT(1729);
	system("pause");
	return 0;
}

int main() { 
	int arr[]={-2,5,4,6,3,8}; 
	int i=0; int j=0; 
	int len=sizeof(arr)/sizeof(arr[0]); 
	for(i=0;i<len-1;i++) { 
		for(j=0;j<len-1-i;j++)  { 
			if(arr[j]>arr[j+1]) { 
			int tmp=arr[j]; 
			arr[j]=arr[j+1]; 
			arr[j+1]=tmp;
			} 
		}
	} 
	for(i=0;i<len;i++) { 
		printf("%d",arr[i]);
	} 
	return 0; 
}
#endif
#if 0
char IsBigletter(ch) {
	return ch + 32;
}
char IsSmallletter(ch) {
	return ch - 32;
}
int main() {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch >= 'a'&&ch <= 'z') {
			putchar(ch-32);
		}
		else if (ch>='A'&&ch <= 'Z') {
			
			putchar(ch+32);
		}
		else if (ch == '$') {
			break;
		}
		else if (ch>'0'&&ch < '9') {
			//do nothing
		}
		else {
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}
#endif
#if 0
//��ʹ��(a+b)/2,����������ƽ����

int Average(int a, int b) {
	if (a > b) {
		return (b)+((a - b) / 2);
	}
	else
	{
		return (a + (b - a) / 2);
	}

}
int main() {
	int a = 10;
	int b = 20;
	int ret=Average(a, b);
	printf("%d", ret);
	return 0;
}
#endif
#if 0
//�ַ����ķ�ת
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//	student a am i
//	i ma a tneduts
//	i am a student

void Flip(char*array,int len) {
	int left = 0;
	int right = len;
	while (left <= right) {
		char tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
}
int main() {
	char array[] = "tneduts a ma i";
	int len = strlen(array)-1;
	Flip(array, len);
	for (int i = 0; i <= len; ++i) {
		printf("%c", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; ++a) {
		for (b = 1; b <= 5; ++b) {
			for (c = 1; c <= 5; ++c) {
				for (d = 1; d <= 5; ++d) {
					for (e = 1; e <= 5; ++e) {
						if (b == 2 || a == 3) {
							if (b == 2 || e == 4) {
								if (c == 1 || d == 2) {
									if (c == 5 || d == 3) {
										if (e == 4 || a == 1) {
											if (a*b*c*d*e == 120) {
												printf("%d %d %d %d %d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
//��ӡ�������
int main() {
	int array[100][100] = { 1 };//Ӧ�ðѳ�ʼֵȫ����ֵΪ1,��ֵΪ0û������
	int i = 0;//i��ʾ����
	int j = 0;//j��ʾ�ڼ���Ԫ��
	int n = 0;
	while (1) {
		printf("������Ҫ��ӡ������");
		scanf("%d", &n);
		if (n < 0 || n>100) {//�ж��û�����ĺϷ���
			continue;
		}
		else {
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= i; ++j) {
					array[i][j] = array[i - 1][j - 1] + array[i - 1][j];//��ǰ��ά����Ԫ�ص�����һ�е�����Ԫ�����
					printf("%2d ", array[i][j]);
				}
				printf("\n");
			}
		}
		return 0;
	}
	return 0;
}
#endif

#if 0
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
int main() {
	int killer;
	for (killer = 'A'; killer <= 'D'; ++killer) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) {
			printf("%c\n", killer);
		}
	}
	system("pause");
	return 0;
}
#endif 
#if 0
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
unsigned int reverse_bit(unsigned int value) {
	int sum = 0;
	for (int i = 0; i < 32; ++i) {
		int ret = ((value >> i) & 1)*pow(2, 31 - i);
		sum += ret;
	}
	printf("%u\n", sum);
}
int main() {
	int value = 25;
	reverse_bit(value);
	return 0;
}
#endif	
#if 0
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

int main() {
	int array[] = { 3,4,5,1,1,5,4 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 1; i < len; ++i) {
		array[0] = array[0] ^ array[i];//���û�и�����
	}
	printf("%d\n", array[0]);
	return 0;
}
#endif	
#if 0
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
int main() {
	int buf[10] = { 0};//������ȫ����ʼ��Ϊ0
	int i = 0;
	int len = 9;//������±�
	for (i = 0; i < 10; ++i) {//ѭ����������
		scanf("%d", &buf[i]);
	}
	for (i = 0; i <= len; ++i) {//ѭ���������ص�
		if (buf[i] % 2 == 0) {
			int tmp = buf[len];
			buf[len] = buf[i];
			buf[i] = tmp;//��������
			len = len-1;//������ѭ����������,�ֿ��������±���ǰ�ƶ�һ.
			i = i - 1;//��Ϊ��֪��������Ԫ���Ƿ�Ϊż��,���԰����ѭ���ٽ���һ��
		}
	}
	for (i = 0; i < 10; ++i) {
		printf("%d ", buf[i]);
	}
	return 0;
}
#endif 
#if 0
//���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
int mystr(int arr[][3], int row, int col,int key) {
	int i = 0;
	int j = col-1;
	while (j>=0&&i<row) {
		if (key == arr[i][j]) {
			return 1;
		}
		else if (key > arr[i][j]) {
			++i;//���ҵ�Ԫ�ش������ֵ,����һ�в���
		}
		else {
			--j;//���С�������,���ά��������±��һ
		}
	}
	return 0;
}
int main() {
	int arr[][3] = { 1,2,3,
					 2,3,4,
					 3,4,5 };
	int ret=mystr(arr, 3, 3, 4);
	if (ret == 1) {
		printf("�ҵ���");
	}
	else if (ret == 0) {
		printf("û���ҵ�");
	}
	return 0;
}
#endif 

#if 0
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�

int main() {
	int money = 20;//��20��Ǯ
	int count = 0;//��¼����ˮ�ĸ���
	count = 20 / 1;
	int tmp = 0;//��ƿ����
	tmp = 20;
	while(1) {
		int num = tmp / 2;//��ƿ������ˮ
		count += num;//�ѿ�ƿ������ˮ�ӵ�����ˮ��������
		tmp = tmp/2+tmp%2;
		if (tmp == 1) {//�����ֻʣ��һ����ƿʱ,�˳�ѭ��
			break;
		}
	}
	printf("%d\n", count);
	return 0;
}
//������,20��Ǯ���Ժ�39ƿ��ˮ
#endif
#if 0
//3.ģ��ʵ��strcpy

void Mystrcpy(char best[], char src[]) {//��Ŀ���ַ�����Դ�ַ�����������
	if (src == NULL) {//���Դ�ַ���ΪNULLֱ�ӳ������
		return -1;
	}
	//������βλ���ʽת����ָ��,������ָ��ĵ���һ���ַ����и�ֵ,
	//�ڽ����ж��Ƿ�Ϊ��б��0,ָ����üӼ�ָ����һ��Ԫ��
	while ((*best++ = *src++) != '\0') {
		//do nothing;
	}
	*best = '\0';//����ָ�����һ��Ԫ�ظ�ֵ'\0';
}
int main() {
	char buf[] = "welcome to xian";
	char arr[64] = {0};
	Mystrcpy(arr, buf);
	printf("%s\n", arr);
	return 0;
}
#endif
#if 0
char* Mystrcat(char buf[], char arr[]) {
	char* ret = buf;//����һ����ʱָ��,�洢buf��ָ��
	while (*ret != '\0') {
		ret++;//��ָ��ָ��buf�����'\0';
	}
	while ((*ret++ = *arr++) != '\0') {//��'\0'��ʼ��buf���к���ƴ��
		;//do nothing
	}
	*ret = '\0';//������ֵ'\0'
	return (char*)ret;//������������ָ��
}
int main() {
	char buf[64] = "i am ";
	char arr[] = "cat";
	Mystrcat(buf, arr);
	printf("%s\n", buf);
	return 0;
}
//������i am cat
#endif
#if 0
//һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�

int main() {
	int arr[] = { 3,5,4,2,5,4,2,9 };
	int i = 0;//��һ��ѭ��
	int j = 0;//�ڲ�ѭ��
	int count=0;//����
	int len = sizeof(arr) / sizeof(int);
	for (i = 0; i < len; ++i) {//�������һ��Ԫ��������ÿ��Ԫ�ؽ��бȽ�
		for (j = 0; j < len; ++j) {
			if (arr[i] == arr[j]) {
			//������������,count���Լ�,һ��������һ����ѭ������,
			//count����1,������ֳ�������count��ѭ��ֵΪ2
				count++;
			}
		}
		if (count == 1) {//�ж�count,���Ϊ1���ӡ�����
			printf("%d ", arr[i]);
		}
		count = 0;//�ڲ�ѭ�����һ��Ҫ��count����
	}
	return 0;
}
#endif
//2.ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��
enum Sex {
	man,
	women
};
typedef struct Person {
	char name[1024];
};
int main() {


	return 0;
}