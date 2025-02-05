#pragma once
//堆(数组存储)只适合表示完全二叉树，对于一般的二叉树，推荐用链式存储
//普通的二叉树的增删查改是没有意义的，只有给普通的二叉树加上一些性质(例如搜索二叉树)才有意义
//普通二叉树不学习增删查改，主要学习 前序 中序 后序 层序 遍历

//根 左子树 右子树   
//前序  根 左 右 
//中序  左 根 有
//后序  左 右 根	前中后说的是 根 在前 在中 在后
//层序 就是 一层一层的遍历

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BinTDataType;
typedef struct BinaryTreeNode
{
	BinTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinTNode;


//创建二叉树结点
BinTNode* BuyNode(BinTDataType data);
//手动创建一棵二叉树 来测试遍历
BinTNode* CreatTree();

//前序 中序 后序遍历
//递归的过程，是不断建立栈帧的过程，函数中的参数和函数体都存在栈帧中
//递归的过程不一样，只是访问根的时机不同
void PreOrder(BinTNode* root);
void InOrder(BinTNode* root);
void PostOrder(BinTNode* root);
//获取树的结点个数
int TreeSize(BinTNode* root);
//求树的高度(深度)
int TreeHeight(BinTNode* root);

//求第k层的结点的个数
int TreeKLevel(BinTNode* root, int k);

//查找值为data的结点,返回结点的指针，使该函数同时具有修改的功能
BinTNode* BinTFind(BinTNode* root, BinTDataType data);




