#include <iostream>
using namespace std;
//����һ��ģ����
template <typename T>
class AA {
public:
	static T m_a;
private:
};
//��ʼ��static�ؼ���
template <typename T>
T AA<T>::m_a = 0;

int main() {
	//int����
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;
	cout << AA<int>::m_a << endl;
	//char����
	AA<char> c1, c2, c3;
	c1.m_a = 'a';
	c2.m_a++;
	c3.m_a++;
	cout << AA<char>::m_a << endl;
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}