#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100

// 所有的结点都在数组中

// 孩子结点要形成一个链表
typedef struct CTNode {
	int child;		// 存放的是孩子结点 在数组中的下标
	struct CTNode* next;
}* ChildPtr;

// 双亲结点的结点类型
typedef struct {
	int data;
	ChildPtr firstchild; //孩子链表头指针    这是指向孩子链表的指针
	int parent;  //带双亲的话加上该行内容
	//定义了一个整型，表示当前结点 的  双亲结点  在结构体数组中的下标
}CTBox;

// 
typedef struct {
	CTBox nodes[MAXSIZE];
	int pos_root, count_node;	//记录根结点的位置 和当前已存储的结点数目
}CTree;




int main() {



	return 0;
}