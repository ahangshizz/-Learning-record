#include <iostream>
using namespace std;


//�쳣����
int test01(int a,int b) {
	if (b == 0) {
	throw b;
	}
	return a / b;
}
int main() {

	try {
		test01(10, 0);
	}
	catch (int b) {
		cout << "����Ϊ" << b << endl;
	}

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}