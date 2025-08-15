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

// 前序遍历
void PreOrder(BinTNode* root);
// 中序遍历
void InOrder(BinTNode* root);
// 后序遍历
void PostOrder(BinTNode* root);
