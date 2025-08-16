#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ���������ض���
typedef int BTDataType;

// ���������
typedef struct BinTreeNode {
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType data;
}BinTNode;

// �������
BinTNode* BuyNode(BTDataType data);
// ����һ����
BinTNode* CreatTree();

// ǰ���������  �ݹ�Ĺ�����һ���ģ�ֻ�Ƿ��ʸ��ڵ��ʱ����ͬ
// ǰ�����
void PreOrder(BinTNode* root);
// �������
void InOrder(BinTNode* root);
// �������
void PostOrder(BinTNode* root);
// ��������Ľ��ĸ���
int TreeSize(BinTNode* root);

void TreeSize1(BinTNode* root, int* psize);

