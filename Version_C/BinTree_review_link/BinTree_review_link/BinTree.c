#include "BinTree.h"
#include "Queue.h"

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
	BinTNode* node7 = BuyNode(7);
	// �������ӹ�ϵ
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->right = node7;
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

// ��������Ľ��ĸ���
// ���ε�˼��  ���κ͵ݹ�������ͬ��֮���������˼ά����
// �����Ľ���������ŷ��������÷��ε�˼��
// �����ܽ���� = �������Ľڵ��� + �������Ľڵ��� + ���ڵ���(1)
int TreeSize(BinTNode* root) {
	if (root == NULL)
		return 0;
	return TreeSize(root->left) 
		+ TreeSize(root->right) + 1;
}
// �����Ǽ���д��
//int TreeSize(BinTNode* root) {
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}

// �����ⲿ��size���̰߳�ȫ��д��
void TreeSize1(BinTNode* root, int* psize) {
	if (root == NULL)
		return;
	++(*psize);
	TreeSize1(root->left, psize);
	TreeSize1(root->right, psize);
}

// 2 ȫ�ֱ�����д��
void TreeSize2(BinTNode* root) {
	if (root == NULL)
		return;
	++g_size;
	TreeSize(root->left);
	TreeSize(root->right);
}

// �����ĸ߶ȣ�ֻ��Ҫ�������������и߶������Ǹ����ټ�һ
int TreeHeight(BinTNode* root) {
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// �ݹ�Ĺؼ��� 1. ���������  2. �ݹ��������
// ���K��Ľڵ�ĸ���
// ���ĵ�K�� == �������ĵ� K - 1 �� + �������ĵ� K - 1 ��
int TreeKLevel(BinTNode* root, int k) {
	assert(k > 0);
	if (root == NULL)
		return 0;
	// �ݹ��������
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
	//������������
	BinTNode* leftRes = BinTFind(root->left, data);
	if (leftRes)
		return leftRes;
	//������������
	BinTNode* rightRes = BinTFind(root->right, data);
	if (rightRes)
		return rightRes;
	// һ������������������û�ҵ������� NULL ���ϲ�ջ֡
	return NULL;
}
// �������
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
