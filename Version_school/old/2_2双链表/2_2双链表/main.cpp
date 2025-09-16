#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// �ڵ������ָ��������������ָ��  һ��ָ��ǰ���ڵ�  ��һ����ָ���̽��
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;
DLinklist L;
void InitLinklist(DLinklist& L) {  // ��Ҫ�����ͷ	��ͷ��Ҫ�Լ�����
    L = (DNode*) malloc(sizeof(DNode));
    assert(L);  // ��ֹLΪ��ָ��
    L->data = 0;
    L->next = NULL;
    L->prior = NULL;
}
// �ж��Ƿ�Ϊ��
bool Empty(DLinklist& L) {
    if (L->next == NULL)  // ֻ���жϱ�ͷ����һ��ָ���Ƿ�Ϊ�ռ���
        return true;
    return false;
}

bool InsertNextDNode(DNode* p, DNode* newNode) {  // ��p���֮�����s���
    if (p == NULL || newNode == NULL) {
        assert(p || newNode);
        return false;
    }
    newNode->next = p->next;
    newNode->prior = p;
    if (p->next != NULL)
        p->next->prior = newNode;
    p->next = newNode;
}
// ˫�����ɾ��
bool DeleteNextNode(DNode* p) {  // ɾ��p�ĺ�̽��
    if (p == NULL)               // p�ǿ�ָ����Ϊ�Ƿ�ָ��
        return false;
    DNode* q = p->next;
    if (q == NULL)  // q = p->next   �ж�p �Ƿ�Ϊ���һ���ڵ�
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
// ����һ������
void DestroyList(DLinklist& L) {
    while (L->next != NULL) {
        DeleteNextNode(L);  //	����һ������ֻ�����ɾ��L�ĺ�̽��
    }
    free(L);
    L = NULL;
}
// ˫����ı��� �����ӡ
void printDList(DLinklist& L) {  // ������
    DNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void printDList_Front(DNode* p) {
    while (p->prior != NULL) {  // ����ͷ������ǰ����
        printf("%d ", p->data);
        p = p->prior;
    }
}
int main() {
    InitLinklist(L);
    return 0;
}
