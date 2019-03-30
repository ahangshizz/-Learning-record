#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 9//�궨���ά���������
#define MAX_COL 9//�궨���ά���������
#define MINE_count 10//�궨����׵ĸ���
void init(char show_map[MAX_ROW][MAX_COL], char  mine_map[MAX_ROW][MAX_COL]) {//��ʼ������,��ʼ��������ά����
	int row;
	int col;
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			mine_map[row][col]='0';
		}
	}
}
void Mine_count(char mine_map[MAX_ROW][MAX_COL]) {//��ʼ�����׵�����ֲ�ͼ
	int n = MINE_count;
	while (n> 0) {
		int row = rand() % 9;//�������
		int col = rand() % 9;
		if (mine_map[row][col] != '1') {//�жϵ��׵ĺϷ���,�ظ����������
			mine_map[row][col] = '1';
			--n;
		}
		else {
			continue;
		}
	}
}
void Print_map(char map[MAX_ROW][MAX_COL]) {//��ӡ��ͼ����,��ӡ����ͼ
	int row;
	int col;
	for (col = 0; col < MAX_COL; ++col) {
		printf("    %d", col);
	}
	printf("\n");
	for (col = 0; col < MAX_COL; ++col) {
		printf("-----");
	}
	printf("\n");
	for (row = 0; row < MAX_ROW; ++row) {
		printf("%d | ", row);
		for (col = 0; col < MAX_COL; ++col) {
			printf("%c    ", map[row][col]);
		}
		printf("\n");
	}
}
void Show_Mine(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL], int row, int col) {//�ж���Χ�ĵ��׸���
	int count=0;
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row-1][col-1]=='1') {
		count++;
	}
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col >= 0 && col <= MAX_COL&&mine_map[row-1][col] == '1') {
		count++;
	}
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row-1][col+1] == '1') {
		count++;
	}
	if (row >= 0 && row <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row][col-1] == '1') {
		count++;
	}
	if (row >= 0 && row <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row][col+1] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row+1][col-1] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col >= 0 && col <= MAX_COL&&mine_map[row+1][col] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row+1][col+1] == '1') {
		count++;
	}
	show_map[row][col] = '0'+count;//�ж�����׸�����ʾ��������
}
int Is_Win(char show_map[MAX_ROW][MAX_COL]) {//�ж�����Ƿ�ʤ��
	int row;
	int col;
	int count=0;
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			if (show_map[row][col] == '*') {
				count++;//�����δ�����������������һ
			}
		}
	}
	return count;//���ؼ���ֵ
}
void GAME(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {//��Ϸ����
	init(show_map, mine_map);//�ȳ�ʼ������
	Mine_count(mine_map);//��ʼ������
	//Print_map(mine_map);//TODO     Ϊ�˲�����ӵĵ��׷ֲ�ͼ
	while (1) {
		Print_map(show_map);
		printf("��������������(�� ��):");
		int row;
		int col;
		int i;//����ʱ�����
		int j;//����ʱ�����
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {//�ж�����ĺϷ���
			printf("���������������,����������");
			continue;
		}
		else if (mine_map[row][col] == '1'){//�������ֱ�ӽ�����Ϸ
			printf("��ʧ����\n");
			Print_map(mine_map);
			break;
		}
		else if (show_map[row][col] != '*') {//�ж���������ĺϷ���
			printf("������������Ѿ�������,����������\n");
			continue;
		}
		int IsWin = Is_Win(show_map);//���պ����ķ���ֵ,�������ֵ����0�������Ϸ,�������ֵ������,���ʤ��
		if (IsWin == 0) {
			printf("��ϲ��ʤ����!");
		}
		Show_Mine(show_map, mine_map, row, col);
		system("cls");//�������Ժ�����
	}
}

void menu() {
	printf("==============\n");
	printf("==1.��ʼ��Ϸ==\n");
	printf("==0.�˳���Ϸ==\n");
	printf("==============\n");
	printf("����������ѡ��:");
}
int main() {
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	while (1) {
		int ret;
		menu();
		scanf("%d", &ret);
		if (ret == 1) {
		GAME(show_map, mine_map);
		}
		else if (ret == 0) {
			printf("Goodbay");
			return 0;
		}
		else {
			printf("�������ѡ������,����������");
			continue;
		}
	}
	system("pause");
	return 0;
}