#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100

typedef struct PTNode {
	int data;		//要存放的数据
	int parent;		//双亲在数组中的位置
}PTNode;

typedef struct {
	PTNode nodes[MAXSIZE];
	int pos_Root, count_Node;		//表示结构体数组中 根结点的位置    以及  当前的结点个数
}PTree;




int main() {





	return 0;
}