#include <iostream>
using namespace std;

class A {
public:
	A(int a, int b) {
		this->a = a;
		this->b = b;
	}
	~A() {
		cout << "������������,�ұ�������" << endl;
	}
private:
	int a;
	int b;
};

void mydevide() {
	A a1(10, 20);
	A a2(1, 2);
	throw 1;
}
int main() {

	try
	{
		mydevide();
	}
	catch (int e)
	{
		cout << "�����쳣" << endl;
	}
	catch (...)
	{
		cout << "����δ֪�����쳣" << endl;
	}
	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}