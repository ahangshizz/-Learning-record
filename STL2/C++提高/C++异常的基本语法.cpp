#include <iostream>
using namespace std;

//1.�쳣�Ļ����﷨
//2.�����쳣���Բ����д���,�����������쳣
//3.�����쳣�Ժ��ǿ纯����
void devide(int x, int y) {
	if (y == 0) {
		//�׳��쳣,�쳣�ǿ纯����,���쳣,�����ֱ�Ӳ�ִ��
		throw x;
	}
	cout << x / y << endl;
}

void mydevide(int x,int y) {
	try
	{
		devide(x, y);
	}
	catch (...)
	{
		cout << "�Ҳ������쳣������û�д���,�����������쳣" << endl;
		throw;
	}
}
int main() {

	try
	{
		mydevide(100,0);

	}
	catch (int e)
	{
		cout << e << "��0����" << endl;
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}