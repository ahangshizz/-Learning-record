#include <iostream>
#include <deque>
using namespace std;



void test() {

	deque<int> d1;
	deque<int> d2(10, 2);
	deque<int> d3(d2.begin(), d2.end());
	deque<int> d4(d3);

	for (deque<int>::iterator it = d2.begin(); it != d2.end(); ++it) {
		cout << "d2:" << *it << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
}

//��ֵ����
void test01() {
	deque<int> d1(10, 5);
	deque<int> d2;
	d2.assign(d1.begin(), d2.end());//���������丳ֵ
	deque<int> d3;
	d3 = d2;//�ȺŸ�ֵ
}
int main() {
	test();
	system("pause");
	return 0;
}