#include "head.h"

Sqstack S; //����ջ
void InitStack(Sqstack& S) {
	S.base = (BiTree*)malloc(sizeof(BiNode) * MAXSIZE);
	assert(S.base);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
//�ж�ջ �Ƿ�Ϊ��
bool EmptyStack(Sqstack& S) {
	if (S.base == S.top)
		return true;
	return false;
}
//��ջ
bool Push(Sqstack& S, BiNode* ele) {
	/*if ((S.top - S.base) < S.stacksize) {
		*(S.top) = ele;
		S.top++;
	}*/
	if (S.top - S.base == S.stacksize)	//�ж��Ƿ�ջ��
		return false;
	*S.top++ = ele;
	return true;
}
//��ջ
bool Pop(Sqstack& S, BiNode* ele) {	//�ٴ���һ��ֵ�������� ��ջԪ�ص�ֵ
	if (S.base == S.top)
		return false;
	S.top--;
	ele = *(S.top);
	//�ȼ��� ele = *--S.top;
	return true;
}