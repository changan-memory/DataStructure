#include "BinTree.h"

void test_Order() {
	BinTNode* root = CreatTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
}
void testSize1() {
	BinTNode* root = CreatTree();

	int size = 0;
	TreeSize1(root, &size);
	printf("%d\n", size);
}
void testSize2() {
	BinTNode* root = CreatTree();
	int size = TreeSize(root);
	printf("%d\n", size);
}
void test_TreeHeight() {
	BinTNode* root = CreatTree();
	int height = TreeHeight(root);
	printf("%d\n", height);
}
void test_TreeLevel() {
	BinTNode* root = CreatTree();
	int K = TreeKLevel(root, 4);
	printf("%d\n", K);
}
void test_TreeFind() {
	BinTNode* root = CreatTree();
	BinTNode* pNode = BinTFind(root, 6);
	assert(pNode);
	printf("%d   %p\n", pNode->data, pNode);
}
int main() {
	//test_Order();
	//testSize1();
	//testSize2();
	//test_TreeHeight();
	//test_TreeLevel();
	test_TreeFind();

	return 0;
}

