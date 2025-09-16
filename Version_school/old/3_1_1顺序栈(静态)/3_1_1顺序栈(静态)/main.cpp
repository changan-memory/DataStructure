#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100

typedef struct Sqstack {
	int top;
	int base, stacksize;
	int data[MAXSIZE];
}Sqstack;

// ��ʼ����̬ջ
bool InitStack(Sqstack& S) {
	S.base = 0;
	S.top = 0;
	S.stacksize = MAXSIZE;
	return true;
}

// �ж��Ƿ�Ϊ��
bool isEmpty(Sqstack& S) {
	if (S.top == S.base)
		return true;
	return false;
}

// ��ջ�ĳ���
bool GetLength(Sqstack& S) {
	return (S.top - S.base);
}

// ��ջ
bool PushStack(Sqstack& S, int ele) {
	if ((S.top - S.base) == S.stacksize)
		return false;
	S.data[S.top++] = ele;
	return true;
}

// ��ջ
bool PopStack(Sqstack& S, int& ele) {
	if (isEmpty(S))
		return false;
	ele = S.data[--(S.top)];
	return true;
}
// ���ջ
bool clearStack(Sqstack& S) {
	S.top = S.base;
	return true;
}

// ����ջ    ����������洢�� ��������ʱ  ����Ա�������� ջ�ϵĿռ�

int main() {
	Sqstack S;
	InitStack(S);
	PushStack(S, 1);
	PushStack(S, 2);
	PushStack(S, 3);
	PushStack(S, 4);
	PushStack(S, 5);
	int  x = 0;
	while (!isEmpty(S)) {
		PopStack(S, x);
		printf("%d ", x);
		//clearStack(S);
	}
	return 0;
}
