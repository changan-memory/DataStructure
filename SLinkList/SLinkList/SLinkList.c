#include "SLinkList.h"

//��ӡ����
void SLTPrint(SListNode* phead) {	//������ԣ�������Ҳ���Դ�ӡ
	SListNode* cur = phead;
	//while(cur)
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//�������ڵ�Ĵ����װ��һ������
SListNode* BuySLTNode(SLTDataType data) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		perror("malloc error");
		return NULL;
	}
	//��ʼ��
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//β�巨
void SLTPushBack(SListNode** pphead, SLTDataType data) {
	SListNode* newNode = BuySLTNode(data);
	if (*pphead == NULL) {
		*pphead = newNode;
		return;
	}

	//�ҵ�ǰ������β���
	SListNode* tail = *pphead;
	while (tail->next != NULL) {	//���pheadΪ�գ���ôtail��ʼʱ  Ϊ  Ұָ��
		tail = tail->next;
	}
	tail->next = newNode;
}
//ͷ�巨
void SLTPushFront(SListNode** pphead, SLTDataType data) {
	SListNode* newNode = BuySLTNode(data);
	//��*ppheadΪ��ʱ�� ���´���Ҳ����
	newNode->next = *pphead;
	*pphead = newNode;
}
//βɾ��ͷɾ
void SLTPopBack(SListNode** pphead) {
	assert(*pphead);//ɾ��ʱȷ����������Ϊ��
	if (*pphead == NULL) {
		return;
	}
	//1. ����ֻ��һ�����
	//2. �����ж�����
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SListNode* tail = *pphead;
		SListNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;	//����tail��ǰһ�����
			tail = tail->next;
		}
		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}
void SLTPopFront(SListNode** pphead) {
	assert(*pphead);
	if (*pphead == NULL) {
		return;
	}
	SListNode* prev = *pphead;
	*pphead = prev->next;
	prev->next = NULL;//����һ������֮��Ľ��Ͽ�
	free(prev);		//�ͷ�
	prev = NULL;	//�ÿ�
}