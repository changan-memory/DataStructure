#include "LinkList.h"

//打印链表
void SLTPrint(SListNode* phead) {
	//无需断言，空链表也可以打印
	SListNode* cur = phead;
	//while(cur)
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}