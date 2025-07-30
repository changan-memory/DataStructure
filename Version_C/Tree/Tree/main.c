#include <stdio.h>

//普通的树形结构
typedef int TreeDataType;
typedef struct TreeNode {
	struct TreeNode* firstNode;		//第一个孩子结点
	struct TreeNode* nextBrother;	//指向下一个兄弟结点
	TreeDataType data;
}TNode;

//普通的树 在实际中用处并不广泛，主要用于操作系统的文件系统
// 数据结构实际上，我们使用的更多的是二叉树


int main() {

	printf("普通的树 在实际中用处并不广泛，主要用于操作系统的文件系统\n");
	printf("数据结构实际上，我们使用的更多的是二叉树");
	return 0;
}