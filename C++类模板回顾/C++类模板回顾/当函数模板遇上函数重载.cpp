#include <iostream>
using namespace std;

template <typename T>
//����ģ��
void My_Swap(T& a, T& b) {
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
	cout << "ģ�庯��" << endl;
}
//��������
void My_Swap(int a, char c) {
	cout << "a:" << a << "c:" << c << endl;
	cout << "��ͨ����" << endl;
}

int main03() {
	{
		int a = 10;
		char c = 'c';
		My_Swap(a, c);//������ͨ����
		My_Swap(c, a);//������ͨ����
		My_Swap(a, a);//����ģ�庯��
		//ģ�庯�������ϸ������ƥ��
		//��ͨ����������ʽ����ת��
	}
	return 0;
}