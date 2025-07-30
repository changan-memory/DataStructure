#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct HTNode {
	int weight;	//表示每个结点的权重
	int parent, LChlid, RChild;	//表示双亲和左右孩子  在数组中的下标
}HTNode, * HuffmanTree;

typedef char** HuffmanCode;

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {

	HC = new char* [n + 1];		//存放 哈夫曼码的字符串数组
	char* code = new char[n];	//暂时存放每一个码的数组  从倒数第二个空间开始  倒着存放
	code[n - 1] = '\0';		//最后一位设置成 \0  为字符串的标志
	int start = 0, f_Node = 0, now_Node = 0;	//定义变量 初始化
	for (int i = 1; i <= n; i++) {	// 遍历所有 数据结点
		start = n - 1;  f_Node = HT[i].parent;  now_Node = i;
		while (f_Node != 0) {			// 只要当前结点的  父节点 存在  就进入循环
			--start;
			if (now_Node == HT[f_Node].LChlid )		//看当前结点是 父节点的左  还是  右 孩子
				code[start] = '0';
			else
				code[start] = '1';
			now_Node = f_Node;			//再接着往上找，知道父节点 没有父节点
			f_Node = HT[f_Node].parent;	// 相应的父节点变成 父节点的父节点
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &code[start]);
	}
	delete[]code;
}
int main() {
	

	return 0;
}