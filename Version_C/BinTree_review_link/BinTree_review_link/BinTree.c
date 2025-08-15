#include "BinTree.h"


// 创建树的结点
BinTNode* BuyNode(BTDataType data) {
	BinTNode* newNode = (BinTNode*)malloc(sizeof(BinTNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return NULL;
	}
	// 初始化数据
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
	// 建立链接关系
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}

// 前序遍历
void PreOrder(BinTNode* root) {
	// 递归结束条件
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// 根 左 右
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
// 中序遍历
void InOrder(BinTNode* root) {
	// 递归结束条件
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// 左 根 右
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
// 后序遍历
void PostOrder(BinTNode* root) {
	// 递归结束条件
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	// 左 右 根
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}