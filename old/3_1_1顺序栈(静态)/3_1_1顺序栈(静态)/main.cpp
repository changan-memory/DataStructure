#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 100

typedef struct Sqstack {
	int top;
	int base, stacksize;
	int data[MAXSIZE];
}Sqstack;

// 初始化静态栈
bool InitStack(Sqstack& S) {
	S.base = 0;
	S.top = 0;
	S.stacksize = MAXSIZE;
	return true;
}

// 判断是否为空
bool isEmpty(Sqstack& S) {
	if (S.top == S.base)
		return true;
	return false;
}

// 求栈的长度
bool GetLength(Sqstack& S) {
	return (S.top - S.base);
}

// 入栈
bool PushStack(Sqstack& S, int ele) {
	if ((S.top - S.base) == S.stacksize)
		return false;
	S.data[S.top++] = ele;
	return true;
}

// 出栈
bool PopStack(Sqstack& S, int& ele) {
	if (isEmpty(S))
		return false;
	ele = S.data[--(S.top)];
	return true;
}
// 清空栈
bool clearStack(Sqstack& S) {
	S.top = S.base;
	return true;
}

// 销毁栈    利用了数组存储， 程序运行时  程序员不能销毁 栈上的空间

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
