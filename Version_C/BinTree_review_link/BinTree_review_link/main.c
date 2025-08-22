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
void testSize() {
	BinTNode* root = CreatTree();

	int size = 0;
	TreeSize1(root, &size);
	printf("%d\n", size);
}
int main() {
	//test_Order();
	testSize();
	return 0;
}

