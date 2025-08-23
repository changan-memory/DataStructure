#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 数据类型重定义
typedef int BTDataType;

// 二叉树结点
typedef struct BinTreeNode {
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType data;
}BinTNode;

// 创建结点
BinTNode* BuyNode(BTDataType data);
// 创建一棵树
BinTNode* CreatTree();

// 前序中序后序  递归的过程是一样的，只是访问根节点的时机不同
// 前序遍历
void PreOrder(BinTNode* root);
// 中序遍历
void InOrder(BinTNode* root);
// 后序遍历
void PostOrder(BinTNode* root);

int g_size;

// 求二叉树的结点的个数
int TreeSize(BinTNode* root);
// 外部变量的指针的写法
void TreeSize1(BinTNode* root, int* psize);
// 全局变量的写法
void TreeSize2(BinTNode* root);
// 求数的高度
int TreeHeight(BinTNode* root);
// 求第k层的结点个数
int TreeKLevel(BinTNode* root, int k);
// 查找一个数据在不在树中，返回对应的结点
BinTNode* BinTFind(BinTNode* root, BTDataType data);
