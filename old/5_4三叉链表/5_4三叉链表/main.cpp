#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TriTNode {
	int data;
	struct TriTNode* parent, * LChild, * RChild;	//指针域   指向双亲结点 和 左右孩子结点
}TriTNode, * TriTree;


int main() {



	return 0;
}