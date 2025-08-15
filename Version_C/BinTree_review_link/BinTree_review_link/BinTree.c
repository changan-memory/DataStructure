#include "BinTree.h"


// �������Ľ��
BinTNode* BuyNode(BTDataType data) {
	BinTNode* newNode = (BinTNode*)malloc(sizeof(BinTNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	// ��ʼ������
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BinTNode* CreatTree() {
	BinTNode* node1 = BuyNode(1);
	BinTNode* node2 = BuyNode(2);
	BinTNode* node3 = BuyNode(3);
	BinTNode* node4 = BuyNode(4);
	BinTNode* node5 = BuyNode(5);
	BinTNode* node6 = BuyNode(6);
	// �������ӹ�ϵ
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

// ǰ�����
void PreOrder(BinTNode* root) {
	// �ݹ��������
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// �� �� ��
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
// �������
void InOrder(BinTNode* root) {
	// �ݹ��������
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// �� �� ��
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
// �������
void PostOrder(BinTNode* root) {
	// �ݹ��������
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// �� �� ��
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}