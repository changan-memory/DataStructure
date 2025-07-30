#include "BinTree.h"

////��ȫ�ֱ�����ڵ����������ʣ���Σ�գ������������εĻ����ۼƼ���
//int size = 0;
//void TreeSize(BinTNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	//ǰ����������Ľڵ����
//	++size;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}



//����д��Ҳ������
//void TreeSize(BinTNode* root, int* pSize) {
//	if (root == NULL) {
//		return;
//	}
//	//ǰ����������Ľڵ����
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
	//TreeSize(root, &size); //�����������Σ�������ַ�����ǻ��ۼƼ���
	//printf("%d ", size);

	printf("TreeSize: %d\n", TreeSize(root));
	printf("TreeHeight: %d\n", TreeHeight(root));
	printf("KLevel: %d", TreeKLevel(root, 3));

	return 0;
}