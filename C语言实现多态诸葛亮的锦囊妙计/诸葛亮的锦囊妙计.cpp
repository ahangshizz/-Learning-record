#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//�����
//�򿪽��ҵķ���
typedef void (TIPS)(void);
struct tip {
	char from[64];
	char to[64];
	TIPS*tp;
};
//�������ҵķ���
struct tip* creat_tip( char const*from, char const*to, TIPS*tp) {
	struct tip* temp = (struct tip*)malloc(sizeof(struct tip));
	if (temp == NULL) {
		return NULL;
	}
	strcpy(temp->from, from);
	strcpy(temp->to, to);
	temp->tp = tp;
	return temp;
}
//�򿪽��ҵĹ��ܺ���
void open_tips(struct tip*tip_p) {
	cout << "���˽���" << endl;
	cout << "�˽�������" << tip_p->from << "д��" << tip_p->to << "��." << endl;
	cout << "������" << endl;
	tip_p->tp();
}
//���ٽ���
void destory(struct tip*tp) {
	if (tp != NULL) {
		free(tp);
		tp = NULL;
	}
}
//ʵ�ֲ�
void tip1_func(void) {
	cout << "���������ǹ���" << endl;
}
void tip2_func(void) {
	cout << "�����ֲ�˼��,��˵�������ѹ��" << endl;
}
void tip3_func(void) {
	cout << "��׷ɱ��������˰�æ" << endl;
}


int main() {
	//������������
	struct tip*tip1 = creat_tip("�����", "����", tip1_func);
	struct tip*tip2 = creat_tip("�����", "����", tip2_func);
	struct tip*tip3 = creat_tip("�����", "����", tip3_func);
	//�����
	cout << "������������" << endl;
	open_tips(tip1);
	cout << "�������" << endl;
	open_tips(tip2);
	cout << "����׷ɱʱ" << endl;
	open_tips(tip3);
	//�ͷ�
	destory(tip1);
	destory(tip2);
	destory(tip3);
	return 0;
}