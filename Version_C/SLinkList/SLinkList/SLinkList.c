#include "SLinkList.h"

// 打印链表
// 传入链表第一个节点的地址
// 顺序表 传的是结构体的指针，就算数组内没有数据，结构体也必须存在，才能进行访问
// 链表的数据存放在节点中，一个节点就是一片空间，指针为空，代表该结点不存在,因此指针可以为空
// 链表的结点是一块一块的内存，内存是可以为空的，因此不能断言
// 顺序表的结构体指针不能为空，因为结构体内除了数组还有其他元素，但结构体内的数组可以为空

// 一定不能为空的变量，就需要断言

void SLTPrint(SListNode* phead) { // 空链表也可以打印，因此不需要断言
    SListNode* cur = phead;
    // while(cur)
    while (cur != NULL) { // 不能这样写 cur->next != NULL;
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");   // cur等于 NULL时，跳出循环，然后输出NULL
}

//单链表的销毁
void SListDestroy(SListNode** pphead) {
    assert(pphead);
    //assert(*pphead);  //空链表也可以销毁 只不过没有做任何操作
    SListNode* cur = *pphead;	//拿到第一个结点
    while (cur != NULL) {
        SListNode* next = cur->next;	//保存下一个节点的地址
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}


// 将创建节点的代码封装成一个函数
SListNode* BuySLTNode(SLTDataType data) {
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if (newNode == NULL) {
        perror("malloc error");
        return NULL;
    }
    // 初始化
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 尾插法
void SLTPushBack(SListNode** pphead, SLTDataType data) {
    assert(pphead);     //pphead一定不能为空,断言pphead是为了防止别人传错,pphead为空的话,就找不到链表的结点了
    //空链表也可以进行插入，因此插入操作 无需 assert(*pphead)
    // pphead为空时，就无法插入了，因此需要进行断言
    //断言是对早期的，明显的错误的检查，避免调试，调试的成本明显更高

    SListNode* newNode = BuySLTNode(data);
    //检查BuyNode的返回值是否为空
    if (newNode == NULL) {
        printf("BuyNode failed\n");
        return;
    }
    //如果当前链表没有结点，那么新结点就是链表的第一个结点
    if (*pphead == NULL) {
        *pphead = newNode;
        return;
    }
    // 找当前链表的尾结点
    SListNode* tail = *pphead;
    while (tail->next != NULL) { // 如果phead为空，那么tail初始时  为  野指针
        tail = tail->next;
    }
    tail->next = newNode;
}
// 头插法
void SLTPushFront(SListNode** pphead, SLTDataType data) {
    assert(pphead);

    SListNode* newNode = BuySLTNode(data);
    if (newNode == NULL) {
        perror("malloc failed");
        return;
    }
    // 当*pphead为空时， 以下代码也适用
    newNode->next = *pphead;    //*pphead为空时，newNode->next  为NULL
    *pphead = newNode;
}
// 尾删和头删
void SLTPopBack(SListNode** pphead) {
    assert(pphead);
    assert(*pphead); // 删除时确保链表不能为空
    if (*pphead == NULL) {
        return;
    }
    // 1. 链表只有一个结点
    // 2. 链表有多个结点
    //尾删需要找到最后一个结点的前一个结点，如果只有一个结点，那就无法删了，所以需要对只有一个结点是特殊处理
    if ((*pphead)->next == NULL) {
        free(*pphead);
        *pphead = NULL;
    }
    else {
        SListNode* tail = *pphead;
        SListNode* prev = NULL;
        while (tail->next != NULL) {
            prev = tail; // 存下tail的前一个结点
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}
//头删
void SLTPopFront(SListNode** pphead) {
    assert(pphead);
    assert(*pphead);    //确保链表存在
    if (*pphead == NULL) {
        return;
    }
    SListNode* prev = *pphead;
    *pphead = prev->next;
    prev->next = NULL; // 将第一个结点和之后的结点断开
    free(prev);        // 释放
    prev = NULL;       // 置空
}

//单链表查找 可以代表修改
SListNode* SListFind(SListNode* phead, SLTDataType data) {
    //phead为空时，可以查找，因此无需 assert(phead)
    SListNode* cur = phead;
    //遍历一遍 找到的话，return 指针，找不到，cur 移动
    while (cur != NULL) {
        if (cur->data == data)
            return cur;
        else
            cur = cur->next;
    }
    //走到这里代表没找到  返回空指针
    return NULL;
}

// 单链表在pos之前插入  非常不方便
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType data) {
    assert(pos);    //防止pos为空
    assert(pphead); //pphead 永远不可能为空, 空链表可以插入，无需assert(*pphead)

    //1. pos 位置是头部
    if (pos == *pphead) {
        //SLTPushFront(*pphead, data); 传错了
        SLTPushFront(pphead, data);
    }
    else {
        //默认 pos 是链表中的位置
        //多个节点，在 pos 前插入，需要先找到 pos 前的位置
        SListNode* prev = *pphead;
        while (prev->next != pos) {
            prev = prev->next;
        }
        //创建新结点，并建立连接
        SListNode* newNode = BuySLTNode(data);
        prev->next = newNode;
        newNode->next = pos;
        
    }
}
//pos位置删除
void SListErase(SListNode** pphead, SListNode* pos) {
    assert(pphead);
    assert(pos);
    assert(*pphead);
    //删除一个位置，需要找到该位置的前一个位置
    //如果pos是第一个结点(无法找到prev)，就头删
    if (*pphead == pos) {   
        SLTPopFront(pphead);
        return;
    }
    else {
        SListNode* prev = *pphead;
        while (prev->next != pos) {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        //pos = NULL; //pos置空也没用，pos是局部变量，不会影响外部的pos
    }
}

// pos后面插入
void SListInsertAfter(SListNode* pos, SLTDataType data) {
    assert(pos);
    SListNode* newNode = BuySLTNode(data);
    //一定要先连上，再断开
    newNode->next = pos->next;
    pos->next = newNode;
}
//删除pos的下一个位置
void SListEraseAfter(SListNode* pos) {
    assert(pos);
    assert(pos->next);  //pos和pos->next都必须存在

    //两层断言后，pos和pos->next都存在
    SListNode* delNode = pos->next;
    pos->next = delNode->next;
    free(delNode);
    delNode = NULL;
}
