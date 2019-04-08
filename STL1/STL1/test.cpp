#include <iostream>
#include <string>
using namespace std;
//int ���͵Ľ���
#if 0
void myswap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
//double���͵Ľ���
void myswap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}
#endif 
#if 0
//�������ʹ��ģ�庯��,�����﷨ template<class T> T��һ��������,�������

template<class T> //���߱�������ʼдģ�庯��,������ֵĶ�����Ҫ��㱨��,һ��ģ��ͷֻ�������һ��������Ч
void Myswap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
void test01() {
	int a = 10;
	int b = 20;
	cout << "a:" << a<<endl;
	cout << "b:" << b<<endl;
	//�Զ������Ƶ�
	Myswap(a, b);
	cout << "a:" << a<<endl;
	cout << "b:" << b<<endl;
	double c = 1.31;
	double d = 1.12;
	Myswap(c, d);//�����㴫������ֵ,�Զ������Ƶ�
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
}
int main() {
	test01();
	return 0;
}
#endif
#if 0
template<class T>
int Add(T a, T b) {
	return a + b;
}
int Add(int a, char c) {
	return a + c;
}
void test02() {
	int a = 10;
	int b = 20;
	char c = 'a';
	char d = 'b';
	Add(a, c);//������ͨ����     ��ͨ�����������ʽ����ת��
	Add(a, b);//���ú���ģ��     ����ģ������ϸ�ȷ����
	Add(c, a);//������ͨ����
	//����ģ����������,����ͨ����Ҳ��������ƥ��,C++����������ʹ����ͨ����
}
int main() {
	test02();

	return 0;
}
#endif
#if 0
//��ģ��    
template<class T>
class Person {
public:
	Person(T id, T age) {
		this->mId = id;
		this->mAge = age;
	}
	void show() {
		cout << "id:" << mId << endl;
		cout << "age:" << mAge << endl;
	}
public:
	T mId;
	T mAge;
};
void test01() {
	Person<int> p(10, 20);
	p.show();
}
int main() {
	test01();

	return 0;
}
#endif
#if 0
template<class T>//�Ѵ�ӡ���������   ����ģ��
void PrintArr(T arr[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << "arr[" << i << "]=" << arr[i]<<"  ";
	}
	cout << endl;
}
template<class T>//�������� �����   ����ģ��
void mysort(T arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if(arr[j]<arr[j+1]) {
			T tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
			}
		}
	}
}
int main() {
	int arr[] = { 2,5,4,1,9,8,6 };
	int len = sizeof(arr) / sizeof(int);
	cout<<"����֮ǰ"<<endl;
	PrintArr(arr, len);
	cout << "����֮��" << endl;
	mysort(arr, len);
	PrintArr(arr, len);
	char charr[] = { 'a','n','b','w','t' };
	len = sizeof(charr) / sizeof(char);
	PrintArr(charr, len);
	mysort(charr, len);
	PrintArr(charr, len);
	return 0;
}
#endif
#if 0
// ��ģ��������ͨ��
template<class T> 
class Person {
public:
	Person(T age) {
		this->mAge = age;
	}
public:
	T mAge;
};
//��ģ��������ͨ��ʱ,Ҫ����һ�����������,��Ȼ�������޷������ڴ�
class people :public Person<int> {
public:
};
int main() {
	return 0;
}
#endif 
#if 0
//��ģ��������ģ��
//Ҫ������������
template<class T> 
class Animal {
public:
	void Jiao() {
		cout << mAge << "��Ķ����ڽ�" << endl;
	}
public:
	T mAge;
};
template<class T>
class Cat :public Animal<T> {
	;
};
#endif
#if 0
//����ʵ����ģ��
template<class T1,class T2>
class Person {
public:
	Person(T1 name,T2 age) {
		this->mAge = age;
		this->mName = name;
	}
	void show() {
		cout << "name:" << mName << endl;
		cout << "age:" << mAge << endl;
	}
public:
	T1 mName;
	T2 mAge;
};
void test01() {
	Person<string, int> p("aaa", 20);
	p.show();
}
int main() {

	test01();
	return 0;
}
#endif


#if 0
//��ģ������ʵ��
//����ʵ����ģ��,��Ҫ������Ԫ����,�м�,���鷳
template<class T>
class Person {
public:
	//��Ԫ����Ҳ��Ҫ����,��ģ��,ֻ��windows֧������д��
	//template<class T>
	//friend ostream& operator<<(ostream&os, Person<T> p);//������Ԫ����,ʵ�ֲ���������
	//Linuxͨ��Ӧ��������д��
	friend ostream& operator<< <T>(ostream& os, Person<T> p);
	Person(T age, T id);//��������,����ʵ��
	void show();
private:
	T mAge;
	T mId;
};
//����������ģ��
template<class T>
ostream& operator<<(ostream& os, Person<T> p) {
	os << "age:" << p.mAge << " " << "id:" << p.mId << endl;
	return os;
}
template<class T>
Person<T>::Person(T age, T id) {             //һ��ע������ʵ��ʱ,�������ŵ�λ��
	mAge = age;
	mId = id;
}
template<class T> 
void Person<T>::show() {                  //һ��ע������ʵ��ʱ,�������ŵ�λ��
	cout << "age:" << mAge << " " << "id:" << mId << endl;
}
void test01() {
	Person<int> p(10, 20);
	//p.show();
	cout << p;//ʹ�ò���������ʵ��
}
int main() {

	test01();
	return 0;
}
//��ģ����ļ����ʱ
//Ӧ�ð�cpp�ļ��ĳ�hpp�ļ�,˵������һ����ģ���ļ�
//ԭ��:�ڱ���ʱ,��ģ��ĺ���ʵ����һ������ģ��,����ģ����Ҫ�������α���,�ڶ��α��������ɾ���ĺ���
//	���ֱ����ҵ��cpp������ģ���.h�ļ�,����ģ��û�н��ж��α���,���Ա������
#endif

//����ģ������static
template<class T>
class Person {
public:
	static int a;//ÿ��������඼���Լ��ľ�̬����a,ÿ�������ඨ�����  �����������
};
template<class T>
int Person<T>::a = 0;
int main() {
	Person<int> p1, p2, p3;
	Person<char>pp1, pp2, pp3;
	p1.a = 10;
	pp1.a = 100;
	cout << p1.a << "   " << p2.a << "   " << p3.a << endl;
	cout << pp1.a << "   " << pp2.a << "   " << pp3.a << endl;
	return 0;
}