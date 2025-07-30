#include "BinTree.h"

//�������������
BinTNode* BuyNode(BinTDataType data) {
	BinTNode* newNode = (BinTNode*)malloc(sizeof(BinTNode));
	if (newNode == NULL) {
		perror("malloc failed\n");
		return NULL;
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}
//�ֶ�����һ�ö����� �����Ա���
BinTNode* CreatTree() {
	BinTNode* node1 = BuyNode(1);
	BinTNode* node2 = BuyNode(2);
	BinTNode* node3 = BuyNode(3);
	BinTNode* node4 = BuyNode(4);
	BinTNode* node5 = BuyNode(5);
	BinTNode* node6 = BuyNode(6);
	BinTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;

	node2->left = node3;
	node3->right = node7;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//ǰ�����
void PreOrder(BinTNode* root) {
	//�ݹ�������� ��ǰ���Ϊ��
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//������
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//�������
void InOrder(BinTNode* root) {
	//�ݹ�������� ��ǰ���Ϊ��
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//�� �� ��
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
//�������
void PostOrder(BinTNode* root) {
	//�ݹ�������� ��ǰ���Ϊ��
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//���Ҹ�
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);	
}


//���ε�˼��  ���κ͵ݹ�������ͬ��֮���������˼ά����
//�����Ľ���������ŷ��������÷��ε�˼��
int TreeSize(BinTNode* root) {
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//���������  ������������ȸ�����Ǹ���һ
int TreeHeight(BinTNode* root) {
	if (root == NULL)
		return 0;

	//����д�����ã�������ݹ����   ���Խ��ݹ���õĽ�������ڱ����У������ظ����㡣
	// ������������Ч�ʣ����ܱ��������Ĵ���ṹ��
	/*return TreeHeight(root->left) > TreeHeight(root->right) ? 
		(TreeHeight(root->left) + 1) : (TreeHeight(root->right) + 1);*/
	//�Ա�����д���ĵݹ����
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ��ǰ���ĵ�k��Ľ��ĸ��� == ��������k-1��Ľڵ��� + �������� k-1 ��Ľڵ���
//�ݹ飬��һ�����⣬������ɽ����ʽ��ͬ��������
int TreeKLevel(BinTNode* root, int k) {
	assert(k > 0);
	if (root == NULL)	//���˿��ǵ�ǰ����ǿյ����
		return 0;
	if (k == 1)	//��k���жϵݹ�����
		return 1;

	int leftNum = TreeKLevel(root->left, k - 1);
	int rightNum = TreeKLevel(root->right, k - 1);
	
	return leftNum + rightNum;
}

//����ֵΪdata�Ľ��,���ؽ���ָ�룬ʹ�ú���ͬʱ�����޸ĵĹ���
BinTNode* BinTFind(BinTNode* root, BinTDataType data) {
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

	return NULL;
}