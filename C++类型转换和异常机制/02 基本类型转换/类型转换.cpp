#include <iostream>
using namespace std;

class Animal{};
class Student{};
class Cat:public Animal{};
//static_cast
//���л������͵�ת��
void test01() {
	int a = 97;
	char b = static_cast<char>(a);
	cout << b << endl;
	//����ָ��������õ�ת��
	Animal* ani = NULL;
	Student peter;
	//ֻ��ת�����м̳й�ϵ��ת��
	//peter = static_cast<Student>(ani);
	Cat* cat = NULL;
	ani = static_cast<Animal*>(cat);
}
//dynamic_cast
//ֻ�ܽ��м̳м������ת��
//���ܽ�����ͨ������ת��
//ֻ�ܴ�����ת���ɸ���
void test02() {
	//int a = NULL;
	//char b = dynamic_cast<char>(a);
	Animal ani;
	Animal& aniobj = ani;
	//Cat cat = dynamic_cast<Cat>(aniobj);;
	Cat cat;
	aniobj = dynamic_cast<Animal&>(cat);
}
//const_cast
//ָ��,����,����ָ��
void test03() {
	int a = 10;
	const int& b = a;
	int& c = const_cast<int&>(b);
	c = 20;
}
int main() {

	test01();

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}