#include "LinkList.h"

//��ӡ����
void SLTPrint(SListNode* phead) {
	//������ԣ�������Ҳ���Դ�ӡ
	SListNode* cur = phead;
	//while(cur)
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}