#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define  ROW_MAX 3//�궨�����̵���
#define  COL_MAX 3//�궨�����̵���
char Chess[ROW_MAX][COL_MAX] = {0};//����һ����ά���������
int neum() {//������Ϸ�˵�
	int chooice = 0;
	printf("******************\n");
	printf("**1.��ʼ��Ϸ******\n");
	printf("**2.�˳���Ϸ******\n");
	printf("******************\n");
	printf("����������ѡ�� ");
	scanf("%d", &chooice);
	return chooice;
}
void Print() {//��ӡ����
	for (int ROW=0; ROW < ROW_MAX; ROW++) {
		printf("| %c | %c | %c |\n", Chess[ROW][0], Chess[ROW][1], Chess[ROW][2]);
		if (ROW != ROW_MAX-1) {
		printf("|---|---|---|\n");
		}
	}
}
void Playermove() {
	while (1) {

		printf("�������\n");
		printf("����������λ��(ROW,COL) ");
		int ROW = 0;
		int COL = 0;
		scanf("%d %d", &ROW, &COL);
		//����û�����������Ƿ�Ϸ�
		
		if (ROW>2 || COL > 2||ROW<0||COL<0) {
			printf("�������������������������\n");
			continue;
		}
		if (Chess[ROW][COL] != ' ') {
			printf("������������Ѿ�������ռ������������\n");
			continue;
		}
		Chess[ROW][COL] = 'X';
		break;
		printf("����������\n");
	}

}
void Computermove() {
	srand((unsigned int)time(NULL));
		printf("��������\n");
	while (1) {
		int ROW = rand() % 3;
		int COL = rand() % 3;
		if (Chess[ROW][COL] != ' ') {
			continue;
		}
		Chess[ROW][COL] = 'O';
		break;
	}

	printf("�����������\n");
}
char Cheekwinner() {
	//����������Ƿ�����һ����
	for (int ROW = 0; ROW < ROW_MAX; ++ROW) {
		if (Chess[ROW][0] == Chess[ROW][1] && Chess[ROW][0] == Chess[ROW][2]) {
			return Chess[ROW][0];
		}
	}
	for (int COL = 0; COL < COL_MAX; ++COL) {
		if (Chess[0][COL] == Chess[1][COL] && Chess[0][COL] == Chess[2][COL]) {
			return Chess[0][COL];
		}
	}
	if (Chess[0][0] == Chess[1][1] && Chess[0][0] == Chess[2][2]) {
		return Chess[0][0];
	}
	else if (Chess[0][2] == Chess[1][1] && Chess[0][2] == Chess[2][0]) {
		return Chess[0][2];
	}
	else if (IsFull()){
		return 'q';//����q��ʾ����
	}
	return ' ';//���ؿո��ʾδ��ʤ��
}
//����������1���򷵻�0
int IsFull() {
	for (int ROW = 0; ROW < ROW_MAX; ++ROW) {
		for (int COL = 0; COL < COL_MAX; ++COL) {
			if (Chess[ROW][COL] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
void Cheek_body() {
	int ROW=0;
	int COL=0;
	for (ROW = 0; ROW < ROW_MAX; ++ROW) {
		for (COL = 0; COL < COL_MAX; ++COL) {
			Chess[ROW][COL] = ' ';
		}
	}
}
void GAME() {
	char winner = ' ';
	//��ʼ������
	Cheek_body();
	while (1) {
		//��ӡ����
		Print();
		//�������
		Playermove();
		Print();
		//�ж�ʤ��
		winner=Cheekwinner();
		if (winner != ' ') {
			break;
		}
		//��������
		Computermove();
		//�ж�ʤ��
		winner=Cheekwinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'X') {
		printf("��Ӯ��!\n");
	}
	else if (winner == 'O') {
		printf("�����!\n");
	}
	else if (winner == 'q') {
		printf("���͵������忪");
	}
}



int main() {

	while (1)
	{
		int ret=neum();
		if (ret == 1) {
			GAME();
		}
		else if (ret == 2) {
			printf("GOODBAY\n");
			return;
		}
		else {
			printf("�������ѡ������");
		}
	}
	system("pause");
	return 0;
}