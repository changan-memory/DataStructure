#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100
typedef struct {
	int* top;	//栈顶指针    top指针指向的栈顶元素的下一个元素的位置
	int* base;	//栈底指针
	int stacksize; //栈的最大容量
}Sqstack;

void InitStack(Sqstack& S) {
	S.base = (int*)malloc(sizeof(int) * MAXSIZE);
	assert(S.base);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//判断栈 是否为空
bool EmptyStack(Sqstack& S) {
	if (S.base == S.top)
		return true;
	return false;
}
//求栈的长度  
int LengthStack(Sqstack& S) {	//指针 - 指针  得到两指针间 元素的个数
	return S.top - S.base;
}
//清空顺序栈
bool clearStack(Sqstack& S) {
	if (S.base) {
		S.top = S.base;
		return true;
	}
	return false;
}
//销毁顺序栈
bool DestroyStack(Sqstack& S) {
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
		S.stacksize = 0;
	}
}
//入栈
bool Push(Sqstack& S, int ele) {
	/*if ((S.top - S.base) < S.stacksize) {
		*(S.top) = ele;
		S.top++;
	}*/
	if (S.top - S.base == S.stacksize)	//判断是否栈满
		return false;
	*S.top++ = ele;
	return true;
}
//出栈
bool Pop(Sqstack& S, int ele) {	//再传入一个值用来接收 出栈元素的值
	if (S.base == S.top)
		return false;
	S.top--;
	ele = *(S.top);
	//等价与 ele = *--S.top;
	return true;
}
int main() {
	Sqstack S;
	InitStack(S);

	return 0;
}