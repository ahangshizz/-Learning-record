#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;
int Employee::starnum = 1000;
Employee::Employee()
{
	id = starnum;
	cout << "Ա�����캯��" << endl; 
	level = 1;
	starnum++;
}

void Employee::displaystatus() {
	cout << "Ա������" << this->name << endl;
	cout << "Ա������" << this->salary << endl;
	cout << "Ա�����" << this->id << endl;
	cout << "Ա���ȼ�" << this->level << endl;
}
Employee::~Employee()
{
	cout << "~Employee" << endl;
}
