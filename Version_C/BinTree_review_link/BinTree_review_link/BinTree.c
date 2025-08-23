#include "BinTree.h"
#include "Queue.h"

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
	BinTNode* node7 = BuyNode(7);
	// 建立链接关系
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;
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

// 求二叉树的结点的个数
// 分治的思想  分治和递归有异曲同工之妙，可以提升思维能力
// 求树的结点数，最优方法，采用分治的思想
// 树的总结点数 = 左子树的节点数 + 右子树的节点数 + 根节点数(1)
int TreeSize(BinTNode* root) {
	if (root == NULL)
		return 0;
	return TreeSize(root->left) 
		+ TreeSize(root->right) + 1;
}
// 以下是简略写法
//int TreeSize(BinTNode* root) {
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}

// 传入外部的size，线程安全的写法
void TreeSize1(BinTNode* root, int* psize) {
	if (root == NULL)
		return;
	++(*psize);
	TreeSize1(root->left, psize);
	TreeSize1(root->right, psize);
}

// 2 全局变量的写法
void TreeSize2(BinTNode* root) {
	if (root == NULL)
		return;
	++g_size;
	TreeSize(root->left);
	TreeSize(root->right);
}

// 求树的高度，只需要返回左右子树中高度最大的那个，再加一
int TreeHeight(BinTNode* root) {
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 递归的关键： 1. 拆成子问题  2. 递归结束条件
// 求第K层的节点的个数
// 根的第K层 == 左子树的第 K - 1 层 + 右子树的第 K - 1 层
int TreeKLevel(BinTNode* root, int k) {
	assert(k > 0);
	if (root == NULL)
		return 0;
	// 递归结束条件
	if (k == 1)
		return 1;
	int leftNum = TreeKLevel(root->left, k - 1);
	int rightNum = TreeKLevel(root->right, k - 1);
	return leftNum + rightNum;
}

BinTNode* BinTFind(BinTNode* root, BTDataType data) {
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	//在左子树中找
	BinTNode* leftRes = BinTFind(root->left, data);
	if (leftRes)
		return leftRes;
	//在右子树中找
	BinTNode* rightRes = BinTFind(root->right, data);
	if (rightRes)
		return rightRes;
	// 一棵子树的左右子树都没找到，返回 NULL 给上层栈帧
	return NULL;
}
// 层序遍历
void LevelOrder(BinTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q)) {
		BinTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);
		if(front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	QueueDestroy(&q);
}
