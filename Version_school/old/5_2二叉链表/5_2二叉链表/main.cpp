#include "head.h"
extern Sqstack S;

void visit(BiTree T) {
	printf("%d ", T->data);
}
// 递归遍历算法
//二叉树的 先序遍历算法
void PreOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//先序 根 左 右
		visit(T);	//对结点进行访问
		PreOrderTraverse(T->Lchild);// 递归遍历左子树
		PreOrderTraverse(T->Rchild);// 递归遍历右子树
	}
}

//二叉树的 中序遍历算法
void InOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//中序  左 根 右
		InOrderTraverse(T->Lchild);// 递归遍历左子树
		visit(T);	//对结点进行访问
		InOrderTraverse(T->Rchild);// 递归遍历右子树
	}
}

//二叉树的 后序遍历算法
void PostOrderTraverse(BiTree T) {
	if (T == NULL)	//判断二叉树是否为空    为空的话返回
		return;
	else {
		//后序  左 右 根
		PostOrderTraverse(T->Lchild);// 递归遍历左子树
		PostOrderTraverse(T->Rchild);// 递归遍历右子树
		visit(T);	//对结点进行访问
	}
}

// 非递归遍历算法
// 利用栈 直线非递归遍历二叉树
// 中序遍历非递归算法

BiTree BT;
BiNode* creatNode(int data) {
	BiNode* T = (BiNode*)malloc(sizeof(BiNode));
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return T;
}
bool InitBinTree(BiTree T, int data) {
	T = (BiNode*)malloc(sizeof(BiNode)* MAXSIZE);
	assert(T);
	T->data = data;
	T->Lchild = NULL;
	T->Rchild = NULL;
	return true;
}
// 利用栈 实现 中序非递归遍历
bool InOrderTraverse_N(BiTree T) {
	BiTree p = T;
	BiTree q = NULL;
	InitStack(S);
	// p 指向结点  从根结点开始
	while (p || !EmptyStack(S)) {	
		if (p) {	// 如果 结点不为空  则该结点入栈 同时 p 指向该结点的左子树 
			Push(S, q);
			p = p->Lchild;
		}
		else {	// 如果 结点为空  说明 左 已经访问完, 此时的栈顶元素为 子树的根 
			Pop(S, q);	// 栈顶元素出栈，并用q 指向出栈元素，即 q 指向子树的根

			printf("%d ", 1);//实际是 q->data   这里是因为 二叉树还为建立  就打印了 1
			assert(q);
			// 访问完 p 之后 ， p 指向 总根 的右子树，进行 下一轮 判断
			p = q->Rchild;
		}
	}
	return true;
}
int main() {
	
	printf("%d ", 1);
	return 0;
}