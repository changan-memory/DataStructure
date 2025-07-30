#include <stdlib.h>
#include <assert.h>
#include <iostream>
//�����Һ�̵�   �ö�������
typedef struct BiNode {
	char data;	//	������
	struct BiNode* LChild, * RChild;	//���Һ���ָ����
}BiNode, *BiTree;	//ǰ���ǽ��   ������ָ��ý���ָ��

// �˴��Ķ���������ڴ�ŵ������� char ����      
bool creatBiTree(BiTree& T) {
	char input;
	std::cin >> input;	//��������
	if (input == '#')	// ���� int  ���� char ���������μ��壬�Ƚϵ�ʱ��Ƚ�  ASCII ��ֵ
		T = NULL;
	else {
		if (!(T = (BiNode*)malloc(sizeof(BiNode))))	// �������
			return false;
		T->data = input;
		creatBiTree(T->LChild);	//�ݹ齨��������������
		creatBiTree(T->RChild);	//�ݹ齨��������������
	}
	return true;
}
//�������� ��������㷨
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//�ж϶������Ƿ�Ϊ��    Ϊ�յĻ�����
		return;
	else {
		//���� �� �� �� //�Խ����з���
		std::cout << T->data << " ";
		PreOrderTraverse(T->LChild);// �ݹ����������
		PreOrderTraverse(T->RChild);// �ݹ����������
	}
	
}

bool CopyBiTree(BiTree& NewT, BiTree T) {	// ��һ�������� Ҫ����ȥ�Ŀռ�
	if (T == NULL) {	//�ж��Ƿ�Ϊ�գ��յĻ��Ͳ���Ҫ������
		NewT = NULL;
		return false;	//����ǿ����Ļ����� false
	}
	else {	//��Ϊ�յĻ�  ����ռ俪ʼ����
		NewT = (BiNode*)malloc(sizeof(BiNode));
		assert(NewT);
		NewT->data = T->data;	// ���Ƹ����
		CopyBiTree(NewT->LChild, T->LChild);	//�ݹ鸴��������
		CopyBiTree(NewT->RChild, T->RChild);	// �ݹ鸴��������
		return true;	// ���ƽ������� true
		//����Ҳ���Բ����أ������ؾͽ�����һ��ݹ飬�пպ��ٷ���
	}
}
// ������������ 
int Depth(BiTree T) {
	if (T == NULL)
		return 0;
	else {
		int m = Depth(T->LChild);
		int n = Depth(T->RChild);
		return (m > n ? m + 1 : n + 1);
	}
}

// ��������Ľ�����
int NodeCount(BiTree T) {
	if (T == NULL)	// ���Ϊ�վͷ��� 0
		return 0;
	else {	// �ڵ㲻Ϊ�� ���� ���������Ľ����֮���� + 1
		return NodeCount(T->LChild) + NodeCount(T->RChild) + 1;	// �ݹ飬��ν���
	}
}

// ���������Ҷ�ӽ����
int LeafCount(BiTree T) {
	if (T == NULL)
		return 0;	//Ϊ�� ���� 0
	if ((T->LChild == NULL) && (T->RChild == NULL))
		return 1;	//���Ҷ�Ϊ�� ��Ҷ�ӽ�� ����1
	else							//��Ϊ�յĻ����������� ��������������Ҷ�ӽ��֮��
		return LeafCount(T->LChild) + LeafCount(T->RChild);
}
int main() {
	BiTree T;
	creatBiTree(T);
	PreOrderTraverse(T);
	std::cout << "\n";
	BiTree T2;
	CopyBiTree(T2, T);
	PreOrderTraverse(T2);
	std::cout << "\n";
	std::cout << NodeCount(T) << " ";
	return 0;
}