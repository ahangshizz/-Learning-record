#include <iostream>
using namespace std;
class Test {
public:
	Test() {//����һ���޲ι��캯��
		cout << "�����޲ι��캯��" << endl;
		m_a = 0;
		m_b = 0;
	}
	Test(int x, int y) {//����һ�����������Ĺ��캯��
		cout << "���������������Ĺ��캯��" << endl;//���Ե��õ����ĸ����캯��
		m_a = x;
		m_b = y;
	}
	void prinT() {
		cout << m_a << ",,," << m_b << endl;
	}
	~Test() {
		cout << "������������" << endl;
	}
private:
	int m_a;
	int m_b;
};
int main() {
	//Test *p = (Test*)malloc(sizeof(Test));
	//p->prinT();//malloc�����ռ�ʱ�޷����г�ʼ��,��ӡ������Ϊ�����
	Test *p = new Test;//�����޲ι��캯��
	Test *tp = new Test(10, 20);//�����вι��캯��
	p->prinT();
	tp->prinT();
	if (p!=NULL) {
    free(p);//��free�ͷ�new�����Ŀռ�,���Բ��Ե�free���ͷſռ��ǲ��ᴥ����������
		p = NULL;
	}
	if (tp != NULL) {
		delete tp;//��delete�ͷ�new�����Ŀռ�ֱ�Ӵ�����������
		tp = NULL;
	}
	return 0;
}