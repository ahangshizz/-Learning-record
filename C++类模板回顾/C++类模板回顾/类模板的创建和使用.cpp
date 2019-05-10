#include <iostream>
using namespace std;

template <typename T>
class A {
public:
	A(T a) {
		this->a = a;
	}
	void Print() {
		cout << "a=" << a << endl;
	}
private:
	T a;
};
//��ģ��ļ̳�
//��ģ����������ͨ��
class B :public A<int> {
public:
	B(int a, int b) :A<int>(a) {
		this->b = b;
	}
	void Print() {
		cout << "b:" << b << endl;
	}
public:
	int b;
};
//ģ��������ģ����
template <typename T>
class C :public A<T> {
public:
	C(T a, T c) :A<T>(a) {
		this->c = c;
	}
	void PrintC() {
		cout << "c:" << c << endl;
	}
protected:
	T c;
};
//��ģ�������������������c++������,����������,��Ȼ��������֪����������ڴ�
void UseA(A<int> &a) {
	cout << "����ʹ��ģ����ĺ���" << endl;
}
int main() {

	//ģ����ĵ���
	A<int> a1(11), a2(22), a3(33);
	a1.Print();
	a2.Print();
	a3.Print();
	//ģ����������ͨ��ĵ���
	B b1(1,2);
	b1.Print();
	UseA(a1);
	//ģ��������ģ����ĵ���
	C<int> c1(10, 20);
	c1.PrintC();
	system("pause");
	return 0;
}