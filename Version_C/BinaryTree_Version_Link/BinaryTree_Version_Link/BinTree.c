#include "BinTree.h"

//创建二叉树结点
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
//手动创建一棵二叉树 来测试遍历
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

//前序遍历
void PreOrder(BinTNode* root) {
	//递归结束条件 当前结点为空
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//根左右
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
void InOrder(BinTNode* root) {
	//递归结束条件 当前结点为空
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//左 根 右
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
//后序遍历
void PostOrder(BinTNode* root) {
	//递归结束条件 当前结点为空
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	//左右根
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);	
}


//分治的思想  分治和递归有异曲同工之妙，可以提升思维能力
//求树的结点数，最优方法，采用分治的思想
int TreeSize(BinTNode* root) {
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//求树的深度  左右子树中深度更大的那个加一
int TreeHeight(BinTNode* root) {
	if (root == NULL)
		return 0;

	//这种写法不好，会增大递归深度   可以将递归调用的结果保存在变量中，避免重复计算。
	// 这样既能提升效率，又能保持清晰的代码结构。
	/*return TreeHeight(root->left) > TreeHeight(root->right) ? 
		(TreeHeight(root->left) + 1) : (TreeHeight(root->right) + 1);*/
	//对比两种写法的递归深度
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 求当前树的第k层的结点的个数 == 左子树的k-1层的节点数 + 右子树的 k-1 层的节点数
//递归，把一个问题，拆成若干解决方式相同的子问题
int TreeKLevel(BinTNode* root, int k) {
	assert(k > 0);
	if (root == NULL)	//忘了考虑当前结点是空的情况
		return 0;
	if (k == 1)	//用k来判断递归条件
		return 1;

	int leftNum = TreeKLevel(root->left, k - 1);
	int rightNum = TreeKLevel(root->right, k - 1);
	
	return leftNum + rightNum;
}

//查找值为data的结点,返回结点的指针，使该函数同时具有修改的功能
BinTNode* BinTFind(BinTNode* root, BinTDataType data) {
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

	return NULL;
}