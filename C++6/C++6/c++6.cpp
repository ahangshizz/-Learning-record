#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
using namespace std;
class sqr 
{
public:
	sqr(int a) {
		cout << "srq���캯��" << endl;
		this->a = a;
	}
	~sqr() {
		cout << "~sqr....." << endl;
	}
	int operator()(int a) {//����()���ŵ�����
		return a*a;
	}
	void* operator new(size_t size) {//new������������
		cout << "new������" << endl;
		return malloc(size);
	}
	void operator delete(void*op) {//delete������������
		if (op != NULL) {
			free(op);
			op = NULL;
		}
	}
private:
	int a;
};
int main01() {

	sqr s(10);
	int value = s(2);//�Ѷ��󵱳ɷº�������
	cout << s(2) << endl;
	sqr* A = new sqr(10);//��������캯��
	delete A;//���Զ���ȡ��������
	return 0;
}

class A {
public:
	A(int a) {
		cout << "�������캯��" << endl;
		this->a = a;
	}
	void func() {
		cout << "a=" << this->a << endl;
	}
	~A() {
		cout << "������������" << endl;
	}
private:
	int a;
};
int main02() {
	auto_ptr<int> ptr(new int);//����һ������ָ��,���ٿռ���Զ�����,���ͷ�ļ�<memory>
	*ptr = 10;
	auto_ptr<A> a(new A(10));
	a->func();
	return 0;
}



class mystring {
public:
	mystring() {
		this->len =0;
		this->str = NULL;
	}
	mystring(const char* str) {//mystring�Ĺ��캯��
		cout << "�����˹��캯��" << endl;
		this->len = strlen(str);
		this->str = new char[len+1];
		strcpy(this->str, str);
	}
	~mystring() {
		cout << "��������������" << endl;
		if (str != NULL) {
			delete str;
			str = NULL;
		}
	}
	char& operator[](int idex) {//����[]������
		return this->str[idex];
	}
	mystring(const mystring &another) {//mystring�Ŀ���
		this->len = another.len;
		this->str = new char[len + 1];
		strcpy(this->str, another.str);
	}
	mystring& operator=(mystring&another) {
		if (this == &another) {
			return *this;
		}
		if (this->str != NULL) {
			delete[] this->str;
			this->str = NULL;
			this->len = 0;
		}
		this->len = another.len;
		this->str = new char[len + 1];
		strcpy(this->str, another.str);
		return *this;
	}
	friend ostream&  operator<<(ostream&os, mystring&s);
	friend istream& operator>>(istream&is, mystring&s);
private:
	int len;
	char* str;
};
ostream&  operator<<(ostream&os, mystring&s) {
	os << s.str;
	return os;
}
istream& operator>>(istream&is, mystring&s) {
	if (s.str != NULL) {
		delete[] s.str;
		s.str = NULL;
		s.len = 0;
	}
	char tmp[4096];
	is >> tmp;
	s.len=strlen(tmp);
	s.str = new char[s.len + 1];
	strcpy(s.str, tmp);
	return is;
}
int main15() {
	mystring s1("abc");
	mystring s2(s1);
	mystring s4("abcd");
	cin >> s4;
	cout << s4;
	s1[1] = 'x';
	cout << s1 << endl;
	cout << s2 << endl;
	mystring s3 = s1;
	cout << s3 << endl;
	return 0;
}