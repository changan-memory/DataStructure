#include "head.h"

//��ʼ��ѭ������
bool InitSqQuence(SqQuence& Q) {
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//	ѭ���������
bool PushQuence(SqQuence& Q, BiNode* ele) {
	if ((Q.rear + 1) % MaxSize == Q.front)	//�ж��Ƿ����
		return false;

	Q.data[Q.rear] = ele;
	Q.rear = (Q.rear + 1) % MaxSize;	//���￼����ѭ��������Ӻ�rearָ��ı仯
}

//ѭ�����г���
BiTree PopQuence(SqQuence& Q, BiNode* x) {
	x = Q.data[Q.front];
	Q.front = (Q.front + MaxSize) % MaxSize;
	return 	x;	//	ֻ���ڶ���ͷ����
}

bool QuenceEmpty(SqQuence& Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}


void LevelOrder(BiNode* B) {
	BiNode* p = NULL;
	SqQuence qu;	// ������ʱ���ʼ��һ���ֲ�����
	InitSqQuence(qu);

	PushQuence(qu, B);	//������ĳ�ʼ����� ���
	while (!QuenceEmpty(qu)) {	// ֻҪ �����зǿ� �ͽ���ѭ��
		PopQuence(qu, p);	// �ý����ӣ� �Գ��ӵĽ����з��� 
		assert(p);
		printf("%d ", p->data);
		if (p->Lchild != NULL)		// �ոճ��ӵĽ�� ����  ֻҪ��  ���ҽ��  �ͷֱ����
			PushQuence(qu, p->Lchild);
		if (p->Rchild != NULL)
			PushQuence(qu, p->Rchild);
	}
}
