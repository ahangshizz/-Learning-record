#include <iostream>
using namespace std;
#if 0
//��̬������д
class Shape{
public:
	virtual void show() = 0;
	virtual double getarea() = 0;
	virtual ~Shape() {
		cout << "�����˳�����" << endl;
		//do nothing
	}
};
class Square :public Shape{
public:
	Square(double a) {
		this->a = a;
	}
	virtual void show() {
		cout << "����һ��������" << endl;
	}
	virtual double getarea() {
		return this->a*this->a;
	}
	virtual ~Square() {
		cout << "����������" << endl;
	}
private:
	double a;
};
class Circle :public Shape{
public:
	Circle(double r) {
		this->r = r;
	}
	virtual void show() {
		cout << "����һ��Բ��" << endl;
	}
	virtual double getarea() {
		return this->r*this->r*3.14;
	}
	virtual ~Circle() {
		cout << "������԰��" << endl;
	}
private:
	double r;
};
int main() {
	Shape* array[2] = { 0 };
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			double r;
			cout << "������԰�İ뾶:";
			cin >> r;
			array[i] = new Circle(r);
		}
		else {
			double a;
			cout << "�����������εİ뾶:";
			cin >> a;
			array[1] = new Square(a);
		}
	}
	for (int i = 0; i < 2; ++i) {
		array[i]->show();
		cout<<array[i]->getarea()<<endl;
		delete array[i];
	}
	return 0;
}
#endif
#if 0
//����ָ��

int func(int a, int b) {
	cout << "func" << endl;
	return 0;
}
//����һ
typedef int(FUNC)(int,int);
//������
typedef int(*FUNC_p)(int, int);
int main() {
	//����һ
	FUNC* fp = NULL;//����һͨ������������ָ��
	fp = func;
	(*fp)(10, 20);
	//������
	FUNC_p fp2 = NULL;
	fp2 = func;
	fp2(100,200);
	//������//���д��,ֱ�Ӷ���ָ��
	int(*fp3)(int , int ) = NULL;
	fp3 = func;
	fp3(100, 200);
	return 0;
}
#endif
#if 0
//�ú���ָ��ʵ��һ�������ӿ�
int func1(int a, int b) {
	cout<<"1999 д��ҵ��"<<endl;
	return 0;
}
int func2(int a, int b) {
	cout << "1999 д��ҵ��" << endl;
	return 0;
}
int func3(int a, int b) {
	cout << "1999 д��ҵ��" << endl;
	return 0;
}
int func4(int a, int b) {
	cout << "2019 д��ҵ��" << endl;
	return 0;
}
//���������ֲ�ͬ,������ͬ�ĺ���д��һ���ӿ�,�����ڶ�̬,���������ֱ�ӵ���
void function(int(*fp)(int, int), int a, int b) {
	cout << "�̶�ҵ��1" << endl;
	cout << "�̶�ҵ��2" << endl;
	fp(a,b);
	cout << "�̶�ҵ��4" << endl;
}
int main() {
	function(func1, 10, 20);
	function(func2, 100, 200);
	function(func3, 1000, 2000);
	function(func4, 10000, 20000);
	return 0;
}
#endif

