#include <stdlib.h>
#include <assert.h>
#include <iostream>
//经常找后继的   用二叉链表
typedef struct BiNode {
	char data;	//	数据域
	struct BiNode* LChild, * RChild;	//左右孩子指针域
}BiNode, *BiTree;	//前面是结点   后面是指向该结点的指针

// 此处的二叉树结点内存放的数据是 char 类型      
bool creatBiTree(BiTree& T) {
	char input;
	std::cin >> input;	//输入数据
	if (input == '#')	// 各种 int  各种 char 都归于整形家族，比较的时候比较  ASCII 码值
		T = NULL;
	else {
		if (!(T = (BiNode*)malloc(sizeof(BiNode))))	// 建立结点
			return false;
		T->data = input;
		creatBiTree(T->LChild);	//递归建立根结点的左子树
		creatBiTree(T->RChild);	//递归建立根结点的右子树
	}
	return true;
}
//二叉树的 先序遍历算法
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//先序 根 左 右 //对结点进行访问
		std::cout << T->data << " ";
		PreOrderTraverse(T->LChild);// 递归遍历左子树
		PreOrderTraverse(T->RChild);// 递归遍历右子树
	}
	
}

bool CopyBiTree(BiTree& NewT, BiTree T) {	// 第一个参数是 要复制去的空间
	if (T == NULL) {	//判断是否为空，空的话就不需要复制了
		NewT = NULL;
		return false;	//如果是空树的话返回 false
	}
	else {	//不为空的话  申请空间开始复制
		NewT = (BiNode*)malloc(sizeof(BiNode));
		assert(NewT);
		NewT->data = T->data;	// 复制根结点
		CopyBiTree(NewT->LChild, T->LChild);	//递归复制左子树
		CopyBiTree(NewT->RChild, T->RChild);	// 递归复制右子树
		return true;	// 复制结束返回 true
		//这里也可以不返回，不返回就进入下一层递归，判空后再返回
	}
}
// 求二叉树的深度 
int Depth(BiTree T) {
	if (T == NULL)
		return 0;
	else {
		int m = Depth(T->LChild);
		int n = Depth(T->RChild);
		return (m > n ? m + 1 : n + 1);
	}
}

// 求二叉树的结点个数
int NodeCount(BiTree T) {
	if (T == NULL)	// 结点为空就返回 0
		return 0;
	else {	// 节点不为空 返回 左右子树的结点数之和再 + 1
		return NodeCount(T->LChild) + NodeCount(T->RChild) + 1;	// 递归，层次渐进
	}
}

// 求二叉树的叶子结点数
int LeafCount(BiTree T) {
	if (T == NULL)
		return 0;	//为空 返回 0
	if ((T->LChild == NULL) && (T->RChild == NULL))
		return 1;	//左右都为空 是叶子结点 返回1
	else							//不为空的话向下找子树 返回左右子树的叶子结点之和
		return LeafCount(T->LChild) + LeafCount(T->RChild);
}
int main() {
	BiTree T;
	creatBiTree(T);
	PreOrderTraverse(T);
	std::cout << "\n";
	BiTree T2;
	CopyBiTree(T2, T);
	PreOrderTraverse(T2);
	std::cout << "\n";
	std::cout << NodeCount(T) << " ";
	return 0;
}