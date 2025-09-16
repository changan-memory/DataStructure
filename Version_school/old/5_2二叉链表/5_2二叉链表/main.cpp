#include "head.h"
extern Sqstack S;

void visit(BiTree T) {
	printf("%d ", T->data);
}
// �ݹ�����㷨
//�������� ��������㷨
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//���� �� �� ��
		visit(T);	//�Խ����з���
		PreOrderTraverse(T->Lchild);// �ݹ����������
		PreOrderTraverse(T->Rchild);// �ݹ����������
	}
}

//�������� ��������㷨
void InOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//����  �� �� ��
		InOrderTraverse(T->Lchild);// �ݹ����������
		visit(T);	//�Խ����з���
		InOrderTraverse(T->Rchild);// �ݹ����������
	}
}

//�������� ��������㷨
void PostOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//����  �� �� ��
		PostOrderTraverse(T->Lchild);// �ݹ����������
		PostOrderTraverse(T->Rchild);// �ݹ����������
		visit(T);	//�Խ����з���
	}
}

// �ǵݹ�����㷨
// ����ջ ֱ�߷ǵݹ����������
// ��������ǵݹ��㷨

BiTree BT;
BiNode* creatNode(int data) {
	BiNode* T = (BiNode*)malloc(sizeof(BiNode));
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return T;
}
bool InitBinTree(BiTree T, int data) {
	T = (BiNode*)malloc(sizeof(BiNode)* MAXSIZE);
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return true;
}
// ����ջ ʵ�� ����ǵݹ����
bool InOrderTraverse_N(BiTree T) {
	BiTree p = T;
	BiTree q = NULL;
	InitStack(S);
	// p ָ����  �Ӹ���㿪ʼ
	while (p || !EmptyStack(S)) {	
		if (p) {	// ��� ��㲻Ϊ��  ��ý����ջ ͬʱ p ָ��ý��������� 
			Push(S, q);
			p = p->Lchild;
		}
		else {	// ��� ���Ϊ��  ˵�� �� �Ѿ�������, ��ʱ��ջ��Ԫ��Ϊ �����ĸ� 
			Pop(S, q);	// ջ��Ԫ�س�ջ������q ָ���ջԪ�أ��� q ָ�������ĸ�

			printf("%d ", 1);//ʵ���� q->data   ��������Ϊ ��������Ϊ����  �ʹ�ӡ�� 1
			assert(q);
			// ������ p ֮�� �� p ָ�� �ܸ� �������������� ��һ�� �ж�
			p = q->Rchild;
		}
	}
	return true;
}
int main() {
	
	printf("%d ", 1);
	return 0;
}