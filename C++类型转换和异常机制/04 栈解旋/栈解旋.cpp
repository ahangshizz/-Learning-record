#include <iostream>
using namespace std;



class Person {
public:
	Person() {
		cout << "���󹹽�" << endl;
	}
	~Person() {
		cout << "��������" << endl;
	}
};
int divide(int x, int y) {
	//���쳣�׳�ʱ,���������������Զ�������
	Person p1, p2;
	if (y == 0) {
		throw y;
	}
	return x / y;
}

void test01() {
	try {
		divide(10, 0);
	}
	catch (int e){
		cout << "�쳣����" << endl;
	}
}
int main() {
	test01();


	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}