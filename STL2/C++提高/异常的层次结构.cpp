#include <iostream>
using namespace std;


class MyArray {
public:
	MyArray(int len);
	~MyArray();
public:
	int & operator[](int id);
	int Get_len();
	//ʵ������쳣�׳���
	class Msize {
	public:
		Msize(int size) {
			this->size = size;
		}
		virtual void PrintErr() {
			cout << "size:" << size << endl;
		}
	protected:
		int size;
	};
	class eNegative :public Msize {
	public:
		eNegative(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eNegative����size:" << size << endl;
		}
	};
	class eZero :public Msize {
	public:
		eZero(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eZero����size:" << size << endl;
		}
	};
	class eTooBig :public Msize {
	public:
		eTooBig(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eTooBig����size:" << size << endl;
		}
	};
	class eTooSmall :public Msize {
	public:
		eTooSmall(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eTooSmall����size:" << size << endl;
		}
	};
private:
	int* m_space;
	int m_len;
};
//�ۺ�֪ʶӦ��
//�Ѻ���д���������
MyArray::MyArray(int len) {
	//�׳���������
	if (len < 0) {
		//�������������ж���,ʵ�ֶ�̬
		throw eNegative(len);
	}
	if (len == 0) {
		throw eZero(len);
	}
	if (len > 1000) {
		throw eTooBig(len);
	}
	if (len < 3) {
		throw eTooSmall(len);
	}
	this->m_len = len;
	this->m_space = new int[len];
}
//��������д���������
MyArray::~MyArray() {
	if (this->m_space != NULL) {
		delete[] this->m_space;
		this->m_len = 0;
	}
}
//����������
int & MyArray::operator[](int id) {
	return m_space[id];
}
//��Ϊlen������private���ⲿ�޷������ṩһ����ȡ���ȵĺ���
int MyArray::Get_len() {
	return m_len;
}
int main() {

	try
	{
		MyArray arr(-4);
		for (int i = 0; i < arr.Get_len(); ++i) {
			arr[i] = i + 1;
			printf("%d ", arr[i]);
		}
	}
	catch (MyArray::Msize &e) //����ָ��ָ���������
	{
		e.PrintErr();
	}
	catch (...)
	{
		cout << "�������͵��쳣" << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}