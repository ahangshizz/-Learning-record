#include <iostream>
using namespace std;

class A {
public:
	int value;
public:
	A(int n) :value(n) {};
	
	/*����ֱ�ӱ���
	ԭ�����ڵ�ʵ�δ��ݸ�ʵ��ʱ��Ҫ����ֵ����,�����ͻ���������ֹ�ĸ��ƿ���
	A(A other) {
		this->value = other.value;
	}
	*/
};



class Student {
private:
	char* name;
public:
	Student(char* str) :name(str) {};
	Student(const Student& s) {};
	Student& operator=(const Student& s) {
		if (this == &s) {
			return *this;
		}
		delete[] name;
		name = new char[strlen(s.name)+1];
		strcpy(name, s.name);
		return *this;
	}
};