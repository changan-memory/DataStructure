#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
//��ʽջ���������޵ĵ�����  ����ֻ���ڱ�ͷ����
typedef struct StackNode {
	int data;
	struct StackNode* prior;	//����ջ�ĺ����ȳ����ԣ���ʽջ��  ջ�����ָ�����ǰһ������λ��
}StackNode, *LinkStack;

LinkStack S;//����һ��ָ��  ָ��ջ�ڵ�    ջ������Ҫ��ͷ

//ͷ��㼴Ϊջ��  ջ������Ҫ��ͷ
// �����ɾ�����ڱ�ͷ����

void InitStack(LinkStack& S) {
	S = NULL;
}
//�ж�ջ�Ƿ�Ϊ��
bool EmptyJudge(LinkStack S) {
	if (S == NULL)
		return true;
	return false;
}
//��ʽջ����ջ
void PushStack(LinkStack& S, int data) {
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	assert(newNode);
	newNode->data = data;
	newNode->prior = S;	//S��ʼΪ��ָ��
	S = newNode;
}
//��ʽջ�ĳ�ջ
void PopStcak(LinkStack& S, int& ele) {
	assert(S);
	StackNode* p = S;
	ele = S->data;
	S = S->prior;
	free(p);
}

//��ӡ��ʽջ
void printLStcak(LinkStack& S) {
	StackNode* pMove = S;
	while (pMove != NULL) {
		printf("%d ", pMove->data);
		pMove = pMove->prior;
	}
	printf("\n");
}

//ȡջ��Ԫ��
int GetEle(LinkStack& S) {
	assert(S);
	return S->data;
}
int main() {
	InitStack(S);
	PushStack(S, 1);
	PushStack(S, 2);
	PushStack(S, 3);
	PushStack(S, 4);
	PushStack(S, 5);
	PushStack(S, 6);
	PushStack(S, 7);
	PushStack(S, 8);
	printLStcak(S);
	int x = 0;
	PopStcak(S, x);
	printLStcak(S);
	printf("%d ", x);
	return 0;
}