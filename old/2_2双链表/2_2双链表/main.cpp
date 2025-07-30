#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 在单链表的指针域中设置两个指针  一个指向前驱节点  另一个账指向后继结点
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;
DLinklist L;
void InitLinklist(DLinklist& L) {  // 需要传入表头	表头需要自己创建
    L = (DNode*) malloc(sizeof(DNode));
    assert(L);  // 防止L为空指针
    L->data = 0;
    L->next = NULL;
    L->prior = NULL;
}
// 判断是否为空
bool Empty(DLinklist& L) {
    if (L->next == NULL)  // 只需判断表头的下一个指向是否为空即可
        return true;
    return false;
}

bool InsertNextDNode(DNode* p, DNode* newNode) {  // 在p结点之后插入s结点
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
// 双链表的删除
bool DeleteNextNode(DNode* p) {  // 删除p的后继结点
    if (p == NULL)               // p是空指针则为非法指针
        return false;
    DNode* q = p->next;
    if (q == NULL)  // q = p->next   判断p 是否为最后一个节点
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
// 销毁一个链表
void DestroyList(DLinklist& L) {
    while (L->next != NULL) {
        DeleteNextNode(L);  //	销毁一个链表只需逐次删除L的后继结点
    }
    free(L);
    L = NULL;
}
// 双链表的遍历 例如打印
void printDList(DLinklist& L) {  // 向后遍历
    DNode* p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void printDList_Front(DNode* p) {
    while (p->prior != NULL) {  // 跳过头结点的向前遍历
        printf("%d ", p->data);
        p = p->prior;
    }
}
int main() {
    InitLinklist(L);
    return 0;
}
