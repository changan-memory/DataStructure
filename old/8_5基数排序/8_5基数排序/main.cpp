#include <iostream>
#include <string>
using namespace std;

//基数排序的线性表一般用链表实现
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode, *LinkList;

typedef struct {
	LinkNode* front, *rear;
	int data;
}LinkQueue;

//假设待排序的数据为含有数字，每一位可以有 0-9
	//因此需要初始化 10 个队列
LinkQueue* LQ[10];	// 0-9 代表 个位 十位 百位 等等的数字


//遍历单链表 根据单链表中的数据的数字，放入到对应的链式队列中

//单链表内已有数据   我们需要扫描并放入队列中去
void print(LinkList& L,LinkQueue* LQ) {		//假设 L 是一个有表头的单链表
	LinkNode* pMove = L->next;
	while (pMove != nullptr) {
		int num = pMove->data % 10;
	}
}


int main() {

	

	return 0;
}