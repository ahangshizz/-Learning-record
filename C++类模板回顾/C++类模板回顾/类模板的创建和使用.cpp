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
//��ģ�������������������c++������,����������,��Ȼ��������֪����������ڴ�
void UseA(A<int> &a) {
	cout << "����ʹ��ģ����ĺ���" << endl;
}
int main() {

	A<int> a1(11), a2(22), a3(33);
	a1.Print();
	a2.Print();
	a3.Print();
	system("pause");
	return 0;
}