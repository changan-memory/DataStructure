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
int main() {
	test_Order();
	return 0;
}