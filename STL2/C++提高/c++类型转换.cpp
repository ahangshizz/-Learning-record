#include <iostream>
using namespace std;


#if 0
int main1() {

	double dpi = 3.1415926;
	int num1 = (int)dpi;//c��������ת��
	int num2 = static_cast<int>(dpi);//c++��������ת��,����ʱc++�������������ͼ��
	//int num3 = dpi;//C�����е���ʽ����ת���ĵط�,ȫ������ʹ��static_cast<>()

	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}

//����һ����������
class Animal {
public:
	virtual void cry() = 0;
private:
};
class Dog :public Animal {
public:
	virtual void cry() {
		cout << "����" << endl;
	}
	void DoHome() {
		cout << "�����Կ���" << endl;
	}
private:
};
class Cat :public Animal {
public:
	virtual void cry() {
		cout << "����" << endl;
	}
	void DoNothing() {
		cout << "è��ץ����" << endl;
	}
private:
};

void Print(Animal* base) {
	base->cry();//��̬����������,�麯����д,�м̳�,����ָ��ָ���������

	//dynamic_cast���԰Ѹ������ת�����������,
	//����ת��  ������תΪС��
	Dog* dog = dynamic_cast<Dog*>(base);
	if (dog != NULL) {
		dog->DoHome();
	}
	Cat* cat = dynamic_cast<Cat*>(base);
	if (cat != NULL) {
		cat->DoNothing();
	}

}
int main2() {
	Dog d1;
	Cat c1;
	Print(&d1);
	Print(&c1);
	system("pause");
	return 0;
}
#endif
//const char*�������βξ�����ֻ������
void Print(const char*myp) {
	cout << myp << endl;
	char* p = NULL;
	//const_castֻ�ǰ�ֻ������ȥ��
	p = const_cast<char*>(myp);
	//ͨ��ָ���޸�����ռ��ֵ
	p[0] = 'A';
	cout << p << endl;
}
int main() {

	const char *buf = "helloweihang";//ָ��ָ�����ֻ���ռ�
	char* p1 = const_cast<char*>(buf);//ȥ��ֻ������
	//p1="aaaa"   err
	char myp[13] = "helloweihang";
	Print(myp);
	system("pause");
	return 0;
}