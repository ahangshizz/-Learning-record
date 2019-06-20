#include <iostream>
using namespace std;


template <class T>
class MyArray {
public:
	MyArray(int capacity) {
		this->mCacpcity = capacity;
		this->mSize = 0;
		this->paddr = new T[this->mCacpcity];
	}
	MyArray(const MyArray<T>& arr) {
		this->mCacpcity = arr.mCacpcity;
		this->mSize = arr.mSize;
		//�����ڴ�
		this->paddr = new T[this->mCacpcity];
		for (int i = 0; i < this->mSize; ++i) {
			this->paddr[i] = arr.paddr[i];
		}
	}
	T& operator[](int index) {
		return this->paddr[index];
	}
	MyArray<T> operator=(const MyArray<T>& arr) {
		if (this->paddr != NULL) {
			delete[] this->paddr;
		}
		this->mCacpcity = arr.mCacpcity;
		this->mSize = arr.mSize;
		this->paddr = new T[this->mCacpcity];
		for (int i = 0; i < this->mSize; ++i) {
			this->paddr[i] = arr.paddr[i];
		}
		return *this;
	}
	//�����������Ԫ��
	void PushBack(T& data) {
		if (this->mSize >= this->mCacpcity) {
			return;
		}
		this->paddr[this->mSize] = data;
		++this->mSize;
	}
	//c++11������±�׼  &&���Զ���ֵȡ����
	//ʵ�ֲ�Ԫ�صĺ�������
	void PushBack(T&& data) {
		if (this->mSize >= this->mCacpcity) {
			return;
		}
		this->paddr[this->mSize] = data;
		++this->mSize;
	}
	~MyArray() {
		if (this->paddr != NULL) {
			delete[] this->paddr;
		}
		return;
	}
public:
	int mCacpcity;//���������
	int mSize;//��ǰ�����Ԫ�ظ���
	T* paddr;//�����׵ĵ�ַ
};

void test() {
	MyArray<int> myarr(20);
	//����ֵȡ����,�������������Ԫ��
	int a = 10, b = 20, c = 30, d = 40;
	myarr.PushBack(a);
	myarr.PushBack(b);
	myarr.PushBack(c);
	myarr.PushBack(d);
	//����ֵȡ���ø����������Ԫ��
	myarr.PushBack(100);
	myarr.PushBack(200);
	myarr.PushBack(300);
	for (int i = 0; i < myarr.mSize; ++i) {
		cout << myarr[i] << " ";
	}
	cout << endl;
}
int main() {

	test();

	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}