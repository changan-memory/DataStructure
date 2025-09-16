#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <assert.h>
typedef struct Node {
	int data;
	struct Node* next;
}LNode, *Linklist;

void Initlist(Linklist& L) {
	L = (LNode*)malloc(sizeof(LNode));	// L = new LNode;
	assert(L);
	L->next = NULL;
}
//判断链表是否为空
bool EmptyJuddge(Linklist L) {
	if (L->next == NULL)
		return true;
	return false;
}
//单链表的销毁
void DelNode(Linklist& L) {
	LNode* p;
	while (L != NULL) {
		p = L;
		L = L->next;
		free(p);
	}
}
int main() {

	return 0;
}