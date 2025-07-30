#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100
typedef struct {
	int* top;	//ջ��ָ��    topָ��ָ���ջ��Ԫ�ص���һ��Ԫ�ص�λ��
	int* base;	//ջ��ָ��
	int stacksize; //ջ���������
}Sqstack;

void InitStack(Sqstack& S) {
	S.base = (int*)malloc(sizeof(int) * MAXSIZE);
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
//��ջ�ĳ���  
int LengthStack(Sqstack& S) {	//ָ�� - ָ��  �õ���ָ��� Ԫ�صĸ���
	return S.top - S.base;
}
//���˳��ջ
bool clearStack(Sqstack& S) {
	if (S.base) {
		S.top = S.base;
		return true;
	}
	return false;
}
//����˳��ջ
bool DestroyStack(Sqstack& S) {
	if (S.base) {
		free(S.base);
		S.base = NULL;
		S.top = NULL;
		S.stacksize = 0;
	}
}
//��ջ
bool Push(Sqstack& S, int ele) {
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
bool Pop(Sqstack& S, int ele) {	//�ٴ���һ��ֵ�������� ��ջԪ�ص�ֵ
	if (S.base == S.top)
		return false;
	S.top--;
	ele = *(S.top);
	//�ȼ��� ele = *--S.top;
	return true;
}
int main() {
	Sqstack S;
	InitStack(S);

	return 0;
}