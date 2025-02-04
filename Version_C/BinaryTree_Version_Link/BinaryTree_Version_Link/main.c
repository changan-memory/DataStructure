#include "BinTree.h"

////用全局变量求节点数，不合适，很危险，连续调用两次的话会累计计数
//int size = 0;
//void TreeSize(BinTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	//前序遍历求树的节点个数
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}



//这种写法也不合适
//void TreeSize(BinTNode* root, int* pSize) {
//	if (root == NULL) {
//		return;
//	}
//	//前序遍历求树的节点个数
//	++(*pSize);
//	TreeSize(root->left, pSize);
//	TreeSize(root->right, pSize);
//}




int main() {
	BinTNode* root = CreatTree();
	PreOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	PostOrder(root);
	printf("\n");

	//int size = 0;
	//TreeSize(root, &size);
	//TreeSize(root, &size); //连续调用两次，都传地址，还是会累计计数
	//printf("%d ", size);

	printf("TreeSize: %d\n", TreeSize(root));
	printf("TreeHeight: %d\n", TreeHeight(root));
	printf("KLevel: %d", TreeKLevel(root, 3));

	return 0;
}