//#include <iostream>
////�����ռ�
//using namespace std;
////namespace stdccA {
////
////	namespace stdccB {
////		struct teacher
////		{
////			int id;
////			char name[64];
////		};
////	}
////}
////int g_cc;//����bss�Σ���������ȫ��Ϊ0
////int g_cc = 20;//.c�ļ������ض���    .cpp�ļ��������ض���
////void test() {
////	bool flag = true;
////	flag = false;
////	flag = true;
////	cout << "flag=" << flag << endl;
////	cout << sizeof(flag) << endl;
////}
////void test2() {
////	int a = 10;
////	int b = 20;
////	(a < b ? a : b )= 50;
////	cout << "a=" << a << endl;
////}
////void test3() {
////	const int a = 10;
////	int* p = (int*)&a;
////	*p = 20;
////	cout << "a=" << a << endl;
////}
//int main(char argc, char**argv[]) {
//	/*int a = 0;*/
//	//cout << "hello world" << endl;
//	//cin >> a;
//	////cout << "a=" << a << endl;
//	//using stdccA::stdccB::teacher;
//	//teacher t1 = { 0 };
//	//stdccA::stdccB::teacher t2;
//	//test();
//	//test2();
//	/*test3();*/
//
//	int a = 10;
//	int &r = a;//�����Ѿ���������ʼ��
//	r = 50;
//	int &ret = r;
//	ret = 60;
//	cout << "a=" << a << endl;
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <string.h>
using namespace std;
//struct student {
//	int id;
//	char name[64];
//};
//void prints(struct student &t2) {
//	cout << t2.id <<endl<< t2.name << endl;
//}
//void prints2(struct student *t2) {
//	cout << t2->id << endl << t2->name << endl;
//}
//void prints3(struct student t1) {
//	cout << t1.id << endl << t1.name << endl;
//}
//struct typeA {
//	int &a;
//};
//struct typeB {
//	int* a;
//};
//int& test() {
//	int a = 0;
//	a = 10;
//	return a;
//}
//struct student {
//	int id;
//	char name[64];
//};
//int getmem(struct student *&tp) {
//	if (tp == NULL) {
//
//		return 0;
//	}
//	tp->id = 22;
//	strcpy(tp->name, "li5");
//	return 0;
//}
//void myfree(struct student *&tp) {
//	if (tp != NULL) {
//		free(tp);
//		tp == NULL;
////	}
//}
int main(void) {
	//student t1 = {20,"weihang"};
	//prints3(t1);
	//cout << "typeA" << sizeof(struct typeA) << endl;
	//cout << "typeB" << sizeof(struct typeB) << endl;
	//int& main_a = test();
	//cout << "main_a" << main_a << endl;
	//cout << "main_a" << main_a << endl;
	//student *tp=NULL;
	//tp = (struct student *)malloc(sizeof(student));
	//getmem(tp);
	//cout << tp->id << tp->name << endl;
	//myfree(tp);
//	const int a = 10;
//	const int &re = a;//����const���εı���������ǰ������const
//	int b = 20;
//	const int& er = b;  //��ȫϵ�����ߵ�const���Խ��ܰ�ȫϵ�����ߵı���
//	cout << "er=" << er << endl;
//	cout << "b" << b << endl;
//	b = 30;//b��ֵ����ͨ�������޸ģ����ǿ���ֱ��ͨ��b��������޸�
//	cout << "er=" << er << endl;
//	cout << "b" << b << endl;
//	system("pause");
//	return 0;
	cout << "��" << endl;
	return 0;
}