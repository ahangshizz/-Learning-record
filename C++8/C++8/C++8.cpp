#include <iostream>
using namespace std;
#if 0
//��̬������ԭ��    vptrָ��   ָ���麯����
class Prent {
public:
	Prent(int a) {
		this->a = a;
	}
	virtual void func(int a) {
		cout << "Prent func(int)" << endl;
	}
	virtual void func(int a, int b, int c) {
		cout << "Prentfunc (int int int)" << endl;
	}
private:
	int a;
};
class Child :public Prent{
public:
	Child(int a, int b) :Prent(a) {
		this->b = b;
	}
	virtual void func(int a) {
		cout << "Child func(int)" << endl;
	}
	virtual void func(int a, int b, int c) {
		cout << "Child func (int int int)" << endl;
	}
private:
	int b;
};
int main() {
	Prent* pp = new Child(10,20);
	pp->func(10, 20, 30);
	if (pp != NULL) {
		delete pp;
		pp = NULL;
	}
	return 0;
}
#endif
#if 0
//֤��vptrָ��Ĵ���
class T1 {

public:
	virtual void func(int a) {//�麯����д
		cout << "T1 func" << endl;
	}
private:
	int a;
};
class T2 {
public:
	void func(int a) {
		cout << "T2 func" << endl;
	}
private:
	int a;
};
int main() {
	T1 p1;
	T2 p2;
	cout << "sizeof(p1)=" << sizeof(p1) << endl;//8�ֽ�    �������4�ֽھ���vptrָ��
	cout << "sizeof(p2)=" << sizeof(p2) << endl;//4�ֽ�
	return 0;
}
#endif
#if 0
//vptrָ��ķֲ���ʼ��
class Prent {

public:
	Prent(int a) {
		cout << "Prent ::(int)" << endl;
		this->a = a;
		//print();//��ʱ���ø�����麯��
	}
	virtual void print() {
		cout << "prent a=" << a << endl;
	}
private:
	int a;
};
class Child :public Prent{
public:
	Child(int a, int b) :Prent(a) {
		this->b = b;
		print();//����������麯��     vptrָ���Ѿ��Ӹ���ָ������
	}
	virtual void print() {
		cout << "Child b=" << b << endl;
	}
private:
	int b;

};
int main() {
	Prent *pp = new Child(10, 20);
	delete pp;
	return 0;
}
#endif
#if 0
//���麯���ͳ�����
class Shape{
public:
	virtual double GetArea() = 0;//����һ�����麯��
};
class Square :public Shape{
public:
	Square(int a) {
		this->a = a;
	}
	virtual double GetArea() {
		cout << "�����������εĴ��麯��" << endl;
		return a*a;
	}
private:
	int a;//�����α߳�
};
class Circular:public Shape{
public:
	Circular(int r) {
		this->r = r;
	}
	virtual double GetArea() {//���������д���麯��
		cout << "������Բ��" << endl;
		return 3.14*r*r;
	}
private:
	int r;
};
class Triangle :public Shape{
public:
	Triangle(int len,int wid) {
		this->len = len;
		this->wid = wid;
	}
	virtual double GetArea() {//��д���麯��,������̬
		cout << "������������" << endl;
		return (len*wid) / 2;
	}
private:
	int len;
	int wid;
};
int main() {
	Shape *sp1 = new Square(10);//����ָ��ָ���������
	sp1->GetArea();
	Shape* sp2 = new Triangle(10, 20);//����ָ��ָ������
	sp2->GetArea();
	Shape* sp3 = new Circular(10);//����ָ��ָ������
	sp3->GetArea();
	return 0;
}
#endif
#if 0
//���ڴ��麯����д����ϰ,���������
class Bigbrother{
public:
	virtual void fightpeople() = 0;
};
class Eastnverlost :public Bigbrother{
public:
	virtual void fightpeople() {
		cout << "��������ʹ�ÿ����������" << endl;
	}
};
class Wuyazi :public Bigbrother{
public:
	virtual void fightpeople() {
		cout << "������ʹ�ñ�ڤ�񹦴���" << endl;
	}
};
class DuanYu :public Bigbrother{
public:
	virtual void fightpeople() {
		cout << "����ʹ�������񽣴���" << endl;
	}
};
int main() {
	Bigbrother* pp = new Wuyazi;
	pp->fightpeople();
	Bigbrother* pp2 = new DuanYu;
	pp2->fightpeople();
	Bigbrother* pp3 = new Eastnverlost;
	pp3->fightpeople();
	delete pp;
	delete pp2;
	delete pp3;
	return 0;
}
#endif
#if 0
//���麯���Ͷ�̳�
//���ͷſռ�ʱ��������,��������ô����
class T1{
public:
	virtual void func1(int a) = 0;
	virtual void func2(int a) = 0;
};
class T2{
public:
	virtual void func3(int a, int b, int c) = 0;
};
class T3 :public T1, public T2 {
public:
	virtual void func1(int a) {
		cout << "һ������func1" << endl;
	}
	virtual void func2(int a) {
		cout << "һ������func2" << endl;
	}
	virtual void func3(int a, int b, int c) {
		cout << "��������" << endl;
	}
};
int main() {
	T1* p = new T3;
	T2* p2 = new T3;
	p->func1(10);
	p->func2(100);
	p2->func3(10, 20, 30);
//	delete p2;    �ͷſռ䷢������,���������������
	//delete p;
	return 0;
}
#endif
class Cpu{
public:
	virtual void cpuwork() = 0;
};
class Memory{
public:
	virtual void memorywork() = 0;
};
class Card{
public:
	virtual void cardwork() = 0;
};
class Computer{
public:
	Computer(Cpu*cpu, Card*card, Memory*memory) {
		this->cpu = cpu;
		this->card = card;
		this->memory = memory;
	}
	void computerwork() {
		this->card->cardwork();
		this->cpu->cpuwork();
		this->memory->memorywork();
	}
	~Computer() {
		if (this->cpu != NULL) {
			delete[] this->cpu;
		}
		if (this->card != NULL) {
			delete[] this->card;
		}
		if (this->memory != NULL) {
			delete[] this->memory;
		}
	}
private:
	Cpu* cpu;
	Card* card;
	Memory* memory;
};
class Intelcpu :public Cpu{
public:
	virtual void cpuwork() {
		cout << "intel cpu ��ʼ������" << endl;
	}
};
class Intelcard :public Card {
public:
	virtual void cardwork() {
		cout << "intel card ��ʼ������" << endl;
	}
};
class Intelmemory :public Memory {
public:
	virtual void memorywork() {
		cout << "intel memory ��ʼ������" << endl;
	}
};
int main() {
	//Computer* com1 = new Computer(Intelcpu,Intelcard,Intelmemory);
	Cpu*cpu = new Intelcpu;
	Card*card = new Intelcard;
	Memory*mem = new Intelmemory;
	Computer*com = new Computer(cpu, card, mem);
	com->computerwork();
	delete com;
	return 0;
}