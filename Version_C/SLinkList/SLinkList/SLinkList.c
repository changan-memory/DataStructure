#include "SLinkList.h"

// ��ӡ����
// ���������һ���ڵ�ĵ�ַ
// ˳��� �����ǽṹ���ָ�룬����������û�����ݣ��ṹ��Ҳ������ڣ����ܽ��з���
// ��������ݴ���ڽڵ��У�һ���ڵ����һƬ�ռ䣬ָ��Ϊ�գ�����ý�㲻����,���ָ�����Ϊ��
// ����Ľ����һ��һ����ڴ棬�ڴ��ǿ���Ϊ�յģ���˲��ܶ���
// ˳���Ľṹ��ָ�벻��Ϊ�գ���Ϊ�ṹ���ڳ������黹������Ԫ�أ����ṹ���ڵ��������Ϊ��

// һ������Ϊ�յı���������Ҫ����

void SLTPrint(SListNode* phead) { // ������Ҳ���Դ�ӡ����˲���Ҫ����
    SListNode* cur = phead;
    // while(cur)
    while (cur != NULL) { // ��������д cur->next != NULL;
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");   // cur���� NULLʱ������ѭ����Ȼ�����NULL
}

//�����������
void SListDestroy(SListNode** pphead) {
    assert(pphead);
    //assert(*pphead);  //������Ҳ�������� ֻ����û�����κβ���
    SListNode* cur = *pphead;	//�õ���һ�����
    while (cur != NULL) {
        SListNode* next = cur->next;	//������һ���ڵ�ĵ�ַ
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}


// �������ڵ�Ĵ����װ��һ������
SListNode* BuySLTNode(SLTDataType data) {
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if (newNode == NULL) {
        perror("malloc error");
        return NULL;
    }
    // ��ʼ��
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// β�巨
void SLTPushBack(SListNode** pphead, SLTDataType data) {
    assert(pphead);     //ppheadһ������Ϊ��,����pphead��Ϊ�˷�ֹ���˴���,ppheadΪ�յĻ�,���Ҳ�������Ľ����
    //������Ҳ���Խ��в��룬��˲������ ���� assert(*pphead)
    // ppheadΪ��ʱ�����޷������ˣ������Ҫ���ж���
    //�����Ƕ����ڵģ����ԵĴ���ļ�飬������ԣ����Եĳɱ����Ը���

    SListNode* newNode = BuySLTNode(data);
    //���BuyNode�ķ���ֵ�Ƿ�Ϊ��
    if (newNode == NULL) {
        printf("BuyNode failed\n");
        return;
    }
    //�����ǰ����û�н�㣬��ô�½���������ĵ�һ�����
    if (*pphead == NULL) {
        *pphead = newNode;
        return;
    }
    // �ҵ�ǰ�����β���
    SListNode* tail = *pphead;
    while (tail->next != NULL) { // ���pheadΪ�գ���ôtail��ʼʱ  Ϊ  Ұָ��
        tail = tail->next;
    }
    tail->next = newNode;
}
// ͷ�巨
void SLTPushFront(SListNode** pphead, SLTDataType data) {
    assert(pphead);

    SListNode* newNode = BuySLTNode(data);
    if (newNode == NULL) {
        perror("malloc failed");
        return;
    }
    // ��*ppheadΪ��ʱ�� ���´���Ҳ����
    newNode->next = *pphead;    //*ppheadΪ��ʱ��newNode->next  ΪNULL
    *pphead = newNode;
}
// βɾ��ͷɾ
void SLTPopBack(SListNode** pphead) {
    assert(pphead);
    assert(*pphead); // ɾ��ʱȷ��������Ϊ��
    if (*pphead == NULL) {
        return;
    }
    // 1. ����ֻ��һ�����
    // 2. �����ж�����
    //βɾ��Ҫ�ҵ����һ������ǰһ����㣬���ֻ��һ����㣬�Ǿ��޷�ɾ�ˣ�������Ҫ��ֻ��һ����������⴦��
    if ((*pphead)->next == NULL) {
        free(*pphead);
        *pphead = NULL;
    }
    else {
        SListNode* tail = *pphead;
        SListNode* prev = NULL;
        while (tail->next != NULL) {
            prev = tail; // ����tail��ǰһ�����
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}
//ͷɾ
void SLTPopFront(SListNode** pphead) {
    assert(pphead);
    assert(*pphead);    //ȷ���������
    if (*pphead == NULL) {
        return;
    }
    SListNode* prev = *pphead;
    *pphead = prev->next;
    prev->next = NULL; // ����һ������֮��Ľ��Ͽ�
    free(prev);        // �ͷ�
    prev = NULL;       // �ÿ�
}

//��������� ���Դ����޸�
SListNode* SListFind(SListNode* phead, SLTDataType data) {
    //pheadΪ��ʱ�����Բ��ң�������� assert(phead)
    SListNode* cur = phead;
    //����һ�� �ҵ��Ļ���return ָ�룬�Ҳ�����cur �ƶ�
    while (cur != NULL) {
        if (cur->data == data)
            return cur;
        else
            cur = cur->next;
    }
    //�ߵ��������û�ҵ�  ���ؿ�ָ��
    return NULL;
}

// ��������pos֮ǰ����  �ǳ�������
void SListInsert(SListNode** pphead, SListNode* pos, SLTDataType data) {
    assert(pos);    //��ֹposΪ��
    assert(pphead); //pphead ��Զ������Ϊ��, ��������Բ��룬����assert(*pphead)

    //1. pos λ����ͷ��
    if (pos == *pphead) {
        //SLTPushFront(*pphead, data); ������
        SLTPushFront(pphead, data);
    }
    else {
        //Ĭ�� pos �������е�λ��
        //����ڵ㣬�� pos ǰ���룬��Ҫ���ҵ� pos ǰ��λ��
        SListNode* prev = *pphead;
        while (prev->next != pos) {
            prev = prev->next;
        }
        //�����½�㣬����������
        SListNode* newNode = BuySLTNode(data);
        prev->next = newNode;
        newNode->next = pos;
        
    }
}
//posλ��ɾ��
void SListErase(SListNode** pphead, SListNode* pos) {
    assert(pphead);
    assert(pos);
    assert(*pphead);
    //ɾ��һ��λ�ã���Ҫ�ҵ���λ�õ�ǰһ��λ��
    //���pos�ǵ�һ�����(�޷��ҵ�prev)����ͷɾ
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
        //pos = NULL; //pos�ÿ�Ҳû�ã�pos�Ǿֲ�����������Ӱ���ⲿ��pos
    }
}

// pos�������
void SListInsertAfter(SListNode* pos, SLTDataType data) {
    assert(pos);
    SListNode* newNode = BuySLTNode(data);
    //һ��Ҫ�����ϣ��ٶϿ�
    newNode->next = pos->next;
    pos->next = newNode;
}
//ɾ��pos����һ��λ��
void SListEraseAfter(SListNode* pos) {
    assert(pos);
    assert(pos->next);  //pos��pos->next���������

    //������Ժ�pos��pos->next������
    SListNode* delNode = pos->next;
    pos->next = delNode->next;
    free(delNode);
    delNode = NULL;
}
