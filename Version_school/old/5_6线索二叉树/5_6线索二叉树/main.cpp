#include <iostream>
#include <stdlib.h>
#include <assert.h>

typedef struct BiThrNode {
	int Ltag, Rtag;	//���Խ��Ҫ����������� ���ı�tag�����ͺ�λ��(���ýṹ���ڴ����) �Դ�����ʡ�ռ�
	// tag  ���Ϊ0  ָ����
	// Ltag ���Ϊ 1 ָ��ǰ��    Rtag���Ϊ 1 ָ����
	// ��ָ��ָ��ǰ��   ��ָ��ָ����
	int data;
	struct BiThrNode *Lchild, *Rchild;
}BiThrNode, *BiThrTree;

int main() {

	std::cout << sizeof(bool);
	return 0;
}