#include "Stack.h"

int main() {
	Stack s;
	StackInit(&s);
	int Empty = StackEmpty(&s);
	if (Empty == 0) {
		printf("ջΪ��\n");
	}
	else {
		printf("ջ��Ϊ��\n");
	}
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPop(&s);
	int ret=StackTop(&s);
	printf("%d\n", ret);
	int size = StackSize(&s);
	printf("%d\n", size);
	Empty = StackEmpty(&s);
	if (Empty == 0) {
		printf("ջΪ��\n");
	}
	else {
		printf("ջ��Ϊ��\n");
	}
	StackDestroy(&s);
	system("pause");
	return 0;
}