#include "head.h"

Sqstack S; //建立栈
void InitStack(Sqstack& S) {
	S.base = (BiTree*)malloc(sizeof(BiNode) * MAXSIZE);
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
//入栈
bool Push(Sqstack& S, BiNode* ele) {
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
bool Pop(Sqstack& S, BiNode* ele) {	//再传入一个值用来接收 出栈元素的值
	if (S.base == S.top)
		return false;
	S.top--;
	ele = *(S.top);
	//等价与 ele = *--S.top;
	return true;
}