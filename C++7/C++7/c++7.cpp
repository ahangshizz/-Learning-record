#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#if 0
class A {
public:
	void funcA() {
		cout << "funcA..." << endl;
	}
	int a;
};

//��B��������A,����B has A;
class C1 {
public:
	void funcB() {
		cout << "funcB..." << endl;
	}
	A a;
};
#endif
//��϶�   ���ھ۵����
//��C�ĳ�Ա������Ҫ��A���β�    C use A
#if 0
class C {
public:
	void funcC(A* a1) {
		cout << "funcC..." << endl;
	}
};
//��D�̳���A      ��D is A     �̳е���϶ȷǳ�֮��
class D :public A {
public:
	void funcD() {
		cout << a << endl;
	}
};
int main0() {


	return 0;
}
#endif
//�̳еĻ�������
#if 0
class Student {
public:
	Student(int id, string name) {
		this->id = id;
		this->name = name;
	}
	void PrintS() {
		cout << this->id <<"   "<< this->name << endl;
	}
private:
	int id;
	string name;
};

//ѧ����2�̳�ѧ����
class Student2 :public Student {
public:
	Student2(int id, string name, int score) :Student(id, name) {
		this->score = score;
	}
	void PrintS2() {
		Student::PrintS();
		cout << this->score << endl;
	}
private:
	int score;
};
int main1() {
	Student2 s1(2815, "weihang", 99);
	s1.PrintS2();
	return 0;
}

#endif
//�̳еķ�ʽ
#if 0
class SKT {
public:
	int pub;
protected:
	int pro;
private:
	int pri;
};
class SKT1 :public SKT {
public:
	void func() {
		cout << pub << endl;//pub�����public��Ա����,��public�̳�����ڲ����ⲿ�����Է���
		cout << pro << endl;//pro�����protected��Ա����,��public�̳�����ڲ����Է���,�ⲿ�����Է���
//		cout << pri << endl;//pri�����private��Ա����,��public�̳�����ڲ������Է���,�ⲿ�����Է���
	}
};
int main02() {
	SKT1 T1;
	T1.func();
	T1.pub;
//	T1.pro;
//	T1.pri;
	return 0;
}
#endif	

//��ļ����Ը�ֵԭ��
//���������Ե����������ʹ��
//����������ֱ�Ӹ�ֵ���������
//����������ֱ�ӳ�ʼ���������
//����ָ�����ֱ��ָ������ָ��
//�������ÿ���ֱ�������������
#if 0
class prent {
public:
	prent() {

	}
	prent(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void printP() {
		cout << this->b << endl;
		cout << this->a << endl;
	}
	int a;
	int b;
};
class clid :public prent {
public:
	clid() {

	}
	clid(int a, int b, int c) :prent(a, b) {
		this->c = c;
	}
	int c;
};
int main3() {
//	prent p;
	//clid c = p;//����ͨ����������ำֵ
//	clid c;
//	p = c;//����ͨ����������ำֵ
//	c.printP();//�������ֱ�ӵ���������ʹ��
	prent* pp = NULL;
	clid* cp = NULL;
	prent p;
	clid c;
	pp = &c;//����ָ�����ֱ��ָ���������
//	cp = &p;//����ָ�벻��ָ�������
	pp->printP();
	pp->a;//�������������㸸��ָ�����������
	pp->b;
	return 0;
}
#endif

//����Ĺ��������
//�ڹ�������ʱ,���Զ����ø���Ĺ��캯��
//����ʱ��ѭ˭�ȹ���˭������
#if 0
class EDG {
public:
	EDG(int a) {
		cout << "EDG<int>" << endl;
		this->a = a;
	}
	~EDG() {
		cout << "~EDG.." << endl;
	}
	int a;
};
class EDGY :public EDG {
public:
	EDGY(int a, int y_a) :EDG(a){
		cout << "EDGY<int int>"<<endl;
		this->a = y_a;
	}
	~EDGY() {
		cout << "~EDGY" << endl;
	}
	void printY() {
		cout << this->a << endl;
		cout << EDG::a << endl;
	}
	int a;
};
int main4() {
	EDGY Y1(10, 20);
	Y1.printY();
	return 0;
}
#endif
//�̳��й���static
#if 0
class B {
public:
	static int a;
};
class B2 :public B {
public:
	int b;
};
int B	::a = 0;
int main() {
	B b1;
	B b2;
	B2 a1;
	B2 a2;
	cout << b1.a << endl;
	cout << b2.a << endl;
	B::a = 300;
	cout << a1.a << endl;
	cout << a2.a << endl;
	return 0;
}
#endif

//��̳к���̳�
//�������μ̳�Ӧ������̳н���,��ֹ������ʲ���ȷ.
#if 0
class haro {
public:
	int six;
};
class gailun :virtual public haro {
public:
	void gai() {
		cout << "����֮��" << endl;
	}
};
class huangzi :virtual public haro {
public:
	void huang() {
		cout << "�������" << endl;
	}
};
class huanggai :public gailun, huangzi {
public:
	void hga() {
		gailun::gai();
		huangzi::huang();
	cout << "�������" << endl;
	}
};
int main() {
	gailun g1;
	huangzi h1;
	huanggai hg;
	g1.gai();
	g1.six;
	hg.six;
	hg.hga();
	return 0;
}
#endif
//��̬��ʹ���Լ��麯��
//��̬������������Ҫ����
//Ҫ�м̳�
//Ҫ���麯��
//Ҫ�и���ָ��ָ������
#if 0
class yuebuqun {

public:
	yuebuqun(string kongfu) {
		this->kongfu = kongfu;
	}
	virtual void fight() {//�ӹؼ���virtual ʹ������Ϊ�麯��,������ɶ�̬
		cout << "����Ⱥʹ��" << kongfu << "����" << endl;
	}
	string kongfu;
};
class linpingzhi :public yuebuqun {
public:
	linpingzhi(string kongfu) :yuebuqun(kongfu) {

	}
	void fight() {
		cout << "��ƽ֮ʹ��" << kongfu << "����" << endl;
	}
};
void fightpeople(yuebuqun*hero) {
	hero->fight();
}
int main() {
	yuebuqun *xiaoyy = new yuebuqun("��������");
	linpingzhi* xiaopp = new linpingzhi("��а����");
	fightpeople(xiaoyy);
	fightpeople(xiaopp);

	delete xiaoyy;
	delete xiaopp;
	return 0;
}
#endif
class A {
public:
	A() {
		cout << "������A���޲ι���" << endl;
		this->p = new char[64];
		strcpy(this->p, "zhangsan");
	}
	virtual ~A() {
		cout << "������A����������" << endl;
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};
class B :public A {
public:
	B() {
		cout << "������B���޲ι���" << endl;
		this->p = new char[64];
		strcpy(this->p, "wangwu");
	}
	~B() {
		cout << "������B����������" << endl;
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
		}
	}
private:
	char* p;
};
void deleteA(A*obj) {
	delete obj;
}
void test() {
	//A* aobj = new A;
	B* bobj = new B;
	deleteA(bobj);
}
int main() {
	test();

	return 0;
}


//����  ��д   �ض���
//����һ������ͬһ��������
//�ض���:������������ͬ������,һ������,һ������
//��д:��дһ���麯��,������̬