#include "Technician.h"
#include <iostream>
using namespace std;

Technician::Technician()
{
	cout << "������Ա������" << endl;
	cin >> name;
	perhour = 100;
}
void Technician::getPay() {
	cout << "������Ա������ʱ��" << endl;
	cin >> workhour;
	salary = this->workhour *perhour ;
}
void Technician::uplevel(int level) {
	if (level == 1) {
		perhour = 100;
	}
	else if (level == 2) {
		perhour = 200;
	}
}

Technician::~Technician()
{
	cout << "���ü���Ա��������" << endl;
}
