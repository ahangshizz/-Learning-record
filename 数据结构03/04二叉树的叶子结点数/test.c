#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//������
typedef struct CinaryNode {
	char ch;
	struct CinaryNode* Lchild;
	struct CinaryNode* Rchild;
}CinaryNode;

//��Ҷ�ӽ��ĵݹ麯��

void Leaf_Tree(CinaryNode* node, int* count) {
	if (node == NULL) {
		return;
	}
	if (node->Lchild == NULL && node->Rchild == NULL) {
		printf("%c  ", node->ch);
		++(*count);
	}
	//���ӵ�Ҷ����Ŀ
	Leaf_Tree(node->Lchild,&(*count));
	//�Һ��ӵ�Ҷ����Ŀ
	Leaf_Tree(node->Rchild,&(*count));
}

//�������Ŀ���

CinaryNode* Copy_Tree(CinaryNode* node) {
	if (node == NULL) {
		return NULL;
	}
	CinaryNode* newnode=NULL;
	CinaryNode* newLeft=NULL;
	CinaryNode* newright=NULL;
	if (node->Lchild) {
		newLeft = Copy_Tree(node->Lchild);
	}
	else {
		return NULL;
	}
	if (node->Rchild) {
		newright = Copy_Tree(node->Rchild);
	}
	else {
		return NULL;
	}
	newnode = (CinaryNode*)malloc(sizeof(CinaryNode));
	newnode->Lchild = newLeft;
	newnode->Rchild = newright;
	return newnode;
}

//��������ĸ߶�
int Tree_Max(CinaryNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftdepth = Tree_Max(root->Lchild);
	int rightdepth = Tree_Max(root->Rchild);
	int depth = leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
	return depth;
}
void TestCinaryNode() {
	//��������
	CinaryNode node1 = { 'A',NULL,NULL };
	CinaryNode node2 = { 'B',NULL,NULL };
	CinaryNode node3 = { 'C',NULL,NULL };
	CinaryNode node4 = { 'D',NULL,NULL };
	CinaryNode node5 = { 'E',NULL,NULL };
	CinaryNode node6 = { 'F',NULL,NULL };
	CinaryNode node7 = { 'G',NULL,NULL };
	CinaryNode node8 = { 'H',NULL,NULL };
	CinaryNode node9 = { 'I',NULL,NULL };
	CinaryNode node10 = { 'J',NULL,NULL };
	//��������֮��Ĺ�ϵ
	node1.Lchild = &node2;
	node1.Rchild = &node3;
	node2.Lchild = &node4;
	node2.Rchild = &node5;
	node4.Lchild = &node8;
	node4.Rchild = &node9;
	node5.Lchild = &node10;
	node3.Lchild = &node6;
	node3.Rchild = &node7;
	{
		int count = 0;
		Leaf_Tree(&node1, &count);
		printf("�����������Ҷ�Ӽӵ�����%d\n", count);
	}
	//����������ʹ�������ܷ���
	{
		CinaryNode* copytree = Copy_Tree(&node1);
		int count = 0;
		Leaf_Tree(&node1, &count);
		printf("���copy��������Ҷ�Ӽӵ�����%d\n", count);
		free(copytree);
	}
	//��������ĸ߶�
	{
		int MaxDepth = Tree_Max(&node1);
		printf("�������ĸ߶���%d \n", MaxDepth);
	}
}

int main() {
	TestCinaryNode();
	system("pause");
	return 0;
}