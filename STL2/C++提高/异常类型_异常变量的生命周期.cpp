#include <iostream>
using namespace std;

#if 0
void My_Strcpy(char* des, char* src) {
	if (des == NULL) {
		throw "����Ŀ�ĳ���";
	}
	if (src == NULL) {
		throw "����Դ����";
	}
/*
	ʵ��ʧ��,��throw�׳��ĳ����ַ��������޷��׳�
	ʧ��ԭ��δ֪
*/
	if (*src == 'a') {
		throw "�������̳���";
	}
	while (*src !='\0') {
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}

int main() {

	char buf1[] = "anndwoa";
	char buf2[1024] = { 0 };
	try
	{
		My_Strcpy(buf2, buf1);
	}
	catch (int e)
	{
		cout << e << "int���ʹ���" << endl;
	}
	catch (char *e)
	{
		cout << e << "char*���ʹ���" << endl;
	}
	printf("%s \n", buf2);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}
#endif


//�쳣�׳���
class BadSrcType{};
class BaddesType {};
class BadProcessType {
public:
	BadProcessType() {
		cout << "������BadProcessType�Ĺ��캯��" << endl;
	}
	BadProcessType(const BadProcessType& e) {
		cout << "������BadProcessType�Ŀ������캯��" << endl;
	}
	~BadProcessType() {
		cout << "������BadProcessType����������" << endl;
	}
};
void My_Strcpy(char* des, char* src) {
	if (des == NULL) {
		throw BaddesType();
	}
	if (src == NULL) {
		throw BadSrcType();
	}
	if (*src == 'a') {
		throw BadProcessType();
	}
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}

int main() {
	char buf[] = "awdawd";
	char buf2[1024] = { 0 };
	try
	{
		My_Strcpy(buf2, buf);
	}
	catch (BaddesType e)
	{
		cout << "Ŀ��Դ�����쳣" << endl;
	}
	catch (BadSrcType e)
	{
		cout << "����Դ�����쳣" << endl;
	}
	//����1:��������쳣��ʱ��ʹ��һ���쳣����,�򿽱������쳣����
	/*
	catch (BadProcessType e)//�����׽������ͨ����Ŀ������캯��������
	{
		cout << "�������̳����쳣" << endl;
	}
	*/
	//����2:ʹ�����õĻ�,��ʹ���׳����Ǹ�����
	catch (BadProcessType &e)
	{
		cout << "�������̳����쳣" << endl;
	}
	printf("%s \n", buf2);
	system("pause");
	return 0;
}