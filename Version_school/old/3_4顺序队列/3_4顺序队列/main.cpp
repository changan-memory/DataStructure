#define _CRT_SECURE_NO_WARNINGS 1
#define MaxQsize 10

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ѭ������������һ���洢�ռ�

typedef struct {
	int front; //�����ͷ
	int rear;	//�����β
	int* base; //�������ַ
}SqQuence;
SqQuence Q;
//��ʼ��һ������
bool InitSqQuence(SqQuence& Q) {
	Q.base = (int*)malloc(sizeof(int) * MaxQsize);	//��������������ռ�
 	//Q.base = new int[MaxQsize];  Ҳ����C++�Ķ�̬�����ڴ�ķ�ʽ
	assert(Q.base);
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//	��ȡѭ�����еĳ���
int GetQlength(SqQuence& Q) {
	return (Q.rear - Q.front + MaxQsize) % MaxQsize;
}

//	ѭ���������
bool PushQuence(SqQuence& Q, int ele) {   
	if ((Q.rear + 1) % MaxQsize == Q.front)	//�ж��Ƿ����
		return false;

	Q.base[Q.rear] = ele;
	Q.rear = (Q.rear + 1) % MaxQsize;	//���￼����ѭ��������Ӻ�rearָ��ı仯
}

//ѭ�����г���
int PopQuence(SqQuence& Q, int& x) {
	x = Q.base[Q.front];
	Q.front = (Q.front + MaxQsize) % MaxQsize;
	return 	x;	//	ֻ���ڶ���ͷ����
}

// ȡ��ͷԪ��
int GetFrontele(SqQuence& Q) {
	if (Q.front == Q.rear)
		return false;
	return Q.base[Q.front];   //ֻ���ض�ͷԪ��  ��ͷָ�벻��
}

//��������
void printQuence(SqQuence& Q) {
	if (Q.rear > Q.front) {
		for (int i = Q.front; i < Q.rear; i++)
			printf("%d ", Q.base[i]);
		printf("\n");
	}
	if (Q.rear < Q.front) {
		for (int i = Q.front; i > Q.rear; i--)
			printf("%d ", Q.base[i]);
		printf("\n");
	}
}
int main() {
	InitSqQuence(Q);
	PushQuence(Q, 9);
	PushQuence(Q, 8);
	PushQuence(Q, 7);
	PushQuence(Q, 6);
	PushQuence(Q, 5);
	PushQuence(Q, 4);
	PushQuence(Q, 3);
	PushQuence(Q, 2);
	printQuence(Q);
	return 0;
}