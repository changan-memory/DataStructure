#include <iostream>
#include <stdlib.h>
#include <assert.h>

typedef struct BiThrNode {
	int Ltag, Rtag;	//可以结合要存的数据类型 来改变tag的类型和位置(利用结构体内存对齐) 以此来节省空间
	// tag  标记为0  指向孩子
	// Ltag 标记为 1 指向前驱    Rtag标记为 1 指向后继
	// 左指针指向前驱   右指针指向后继
	int data;
	struct BiThrNode *Lchild, *Rchild;
}BiThrNode, *BiThrTree;

int main() {

	std::cout << sizeof(bool);
	return 0;
}