#include <iostream>
using namespace std;


//��Ỻ����
int main01() {
	char ch;
	while ((ch = cin.get()) != EOF) {
		cout << ch << endl;
	}

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}

//����ϵͳ��������С����


int main2() {
	char a, b, c;
	//������û������,ϵͳ����,�ȴ���������
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << b << c << endl;
	//�������ַ���������Ҫ���ַ�ʱ,�����ַ����ڻ�������,����Ҫʱֱ����ȡ
	cout << "��������������,ϵͳ��������" << endl;
	char d, e, f;
	cin.get(d);
	cin.get(e);
	cin.get(f);
	cout << d << e << f << endl;
	system("pause");
	return 0;
}

//cin.getline�������Խ��տո�

int main() {

	char buf1[10];
	char buf2[10];
	cout << "����һ�����ݿ��Դ��ո��� aa bb cc dd ee" << endl;
	//���������������ַ�,��cin�����տո�,�����ո�buf1�������,
	//cin.getline���տո�,����buf2�����ʣ�µ��ַ�
	cin >> buf1;
	cin.getline(buf2,10);
	cout << "buf1:"<<buf1 << endl;
	cout << "buf2:" << buf2 << endl;
	system("pause");
	return 0;
}