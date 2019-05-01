#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
typedef struct MyChar {
	LinkNode node;
	char c;
}MyChar;
//�Ƿ�Ϊ����
int Is_Num(char p) {
	return p >= '0'&&p <= '9';
}
//��ӡ����
void Print_Num(char* p) {
	printf("%c", *p);
}
//�Ƿ�Ϊ������
int Is_Left(char p) {
	return p == '(';
}
//�Ƿ�Ϊ������
int Is_Right(char p) {
	return p == ')';
}
//�����Ų���
void RightOperator(LinkStack* stack) {
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		if (mychar->c == '(') {
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", mychar->c);
		Pop_LinkStack(stack);
		free(mychar);
	}
}
//�Ƿ�Ϊ�����
int Is_Operator(char p) {
	return p == '+' || p == '-' || p == '*' || p == '/';
}
//������ֱ�ӽ�վ,��վ����;
void Insert_stack(LinkStack* stack, LinkNode* node) {
	Push_LinkStack(stack, node);
}
//��������������ȼ�
int GetPorioty(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
//���������
void OperatorOperator(LinkStack* stack, char* p) {
	//��ȡ��ջ��Ԫ�ؽ��бȽ�
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL) {
		MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
		mychar->c = *p;
		Push_LinkStack(stack, (LinkNode*)mychar);
		return;
	}
	//���ջ�����ȼ����ڵ�ǰ�ַ����ȼ�,��ջ
	if (GetPorioty(mychar->c) < GetPorioty(*p)) {
		MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
		mychar->c = *p;
		Push_LinkStack(stack, (LinkNode*)mychar);
		return;
	}//���ջ�����ȼ���
	else {
		while (Size_LinkStack(stack) > 0) {
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			if (GetPorioty(mychar2->c) < GetPorioty(*p)) {
				MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
				mychar->c = *p;
				Push_LinkStack(stack, (LinkNode*)mychar);
				break;
			}
			printf("%c", mychar2->c);
			Pop_LinkStack(stack);
			free(mychar2);
		}
	}
}
int main() {
	char* str = "8+(3-1)*5";
	char* p = str;
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0') {
		if (Is_Num(*p)) {
			Print_Num(p);
		}
		if (Is_Left(*p)) {
			MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
			mychar->c = *p;
			Push_LinkStack(stack, (LinkNode*)mychar);
		}
		if (Is_Right(*p)) {
			RightOperator(stack);
		}
		if (Is_Operator(*p)) {
			OperatorOperator(stack, p);
		}
		p++;
	}
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("%c", mychar->c);
		Pop_LinkStack(stack);
	}
	system("pause");
	return 0;
}