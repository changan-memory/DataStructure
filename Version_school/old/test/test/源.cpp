#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>

#include <iostream>
using namespace std;
//˳����ʵ�������� �� ���� / ���� , ��DemoΪ����ʵ��˳���,��̬����ռ�
const int Max_size = 8; //����˳���ĳ���
//��������ʵ��˳���Ľṹ��
typedef struct SeqList
{
    int* pBase; //��̬����ռ�
    int size; //��������
    int cnt; //���鵱ǰ����
}SeqList;
//��ʼ������
void Init_List(SeqList* pArr)
{
    //����ռ�
    pArr->pBase = (int*)malloc(sizeof(int) * Max_size);

    //��̬����ʧ��д�� (1)
    //����# include <stdlib.h>  //������exit����
    if (NULL == pArr->pBase)
    {
        cout << "��̬�ڴ����ʧ��" << endl;
        exit(-1);
    }
    //��̬����ʧ��д�� (2)
    //����# include <assert.h> //������assert����
    //assert(����)���ã�����������ش����������ֹ
    //assert(pArr -> base != NULL) ; 

    //��ֵ
    pArr->size = Max_size;
    pArr->cnt = 0;

}
//���˳���
void clear(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "���˳���ʧ��,˳����Ѿ�Ϊ�գ��޷�������ղ�����ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    pArr->cnt = 0;
    cout << "��ճɹ�" << endl << endl;
}
//���
int length(SeqList* pArr)
{
    return pArr->cnt;
}
//��λ�ò������
void insert_pos(SeqList* pArr, int x, int pos)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "˳���ռ��������޷����а�λ�ò��������ϵͳ���Զ����ؽ��棺" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }

    if (pos < 0 || pos > pArr->cnt)
    {
        cout << "����ʧ�ܣ��������λ������ϵͳ���Զ����ؽ���" << endl;
        cout << endl;
        return;
    }

    for (int i = pArr->cnt - 1; i >= pos; i--)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }

    pArr->pBase[pos] = x;

    pArr->cnt++;

    cout << "����ɹ�" << endl << endl;


}
//β�����
void push_back(SeqList* pArr, int x)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "˳���ռ��������޷�����β��������밴-1�˳���" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    pArr->pBase[pArr->cnt] = x;
    pArr->cnt++;

}
//ͷ�����
void push_front(SeqList* pArr, int x)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "˳���ռ��������޷�����ͷ��������밴-1�˳���" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    for (int i = pArr->cnt; i > 0; i--)
    {
        pArr->pBase[i] = pArr->pBase[i - 1];
    }

    pArr->pBase[0] = x;

    pArr->cnt++;
}
//βɾ����
void pop_back(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "βɾʧ��,˳���Ϊ�գ��޷�����βɾ������ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    cout << "βɾ�ɹ�" << endl << endl;
    pArr->cnt--;

}
//ͷɾ����
void pop_front(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "ͷɾʧ��,˳���Ϊ�գ��޷�����ͷɾ������ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    for (int i = 1; i <= pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }

    cout << "βɾ�ɹ�" << endl << endl;

    pArr->cnt--;

}
//��ֵɾ������
void remove_value(SeqList* pArr, int value)
{
    int flag = -1;
    for (int i = 0; i < pArr->cnt; i++)
    {
        if (pArr->pBase[i] == value)
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        cout << "��ֵ����ʧ��,ϵͳ�����ؽ���" << endl << endl;
        return;
    }
    else
    {
        for (int i = flag + 1; i < pArr->cnt; i++)
        {
            pArr->pBase[i - 1] = pArr->pBase[i];
        }
        pArr->cnt--;
        cout << "ɾ���ɹ�" << endl << endl;
    }
}
//��λ��ɾ������
void remove_pos(SeqList* pArr, int pos)
{
    if (pos < 0 || pos >= pArr->cnt)
    {
        cout << "��λ��ɾ��ʧ��,�����λ�ò������޷�����ɾ��������ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    for (int i = pos + 1; i <= pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    cout << "ɾ���ɹ�!!!" << endl << endl;
    pArr->cnt--;
}
//��ֵ���ң������±� 
int find(SeqList* pArr, int x)
{
    for (int i = 0; i < pArr->cnt; i++)
    {
        if (pArr->pBase[i] == x) return i;
    }
    return -1;
}
//����

void quick_sort(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "����ʧ��,˳���Ϊ�գ��޷�����ͷɾ������ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    sort(pArr->pBase, pArr->pBase + pArr->cnt);
    cout << "����ɹ�" << endl << endl;
}
//����˳���
void destroy(SeqList* pArr)
{
    free(pArr->pBase);
    pArr->pBase = NULL;
    pArr->cnt = 0;
    pArr->size = 0;
    cout << "���ٳɹ�,�޷������κβ���,ϵͳ������!!" << endl;
}
//����
void reverse(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "����ʧ��,˳���Ϊ�գ��޷�����ͷɾ������ϵͳ���Զ����ز�������" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }
    int i = 0, j = pArr->cnt - 1;
    while (i < j)
    {
        swap(pArr->pBase[i], pArr->pBase[j]);
        i++, j--;
    }
    cout << "���óɹ�" << endl << endl;
}
//��ʾ��ǰ˳������
void show_list(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "˳���Ϊ��,����в�������,ϵͳ���Զ����ز�������!" << endl;
        cout << endl;
        return; //�ص����ú����ĵط���ִ����һ�� 
    }

    for (int i = 0; i < pArr->cnt; i++)
    {
        cout << pArr->pBase[i] << " ";
    }
    cout << endl;

    cout << endl << "����������ǰ״̬" << endl;

    cout << endl;

}
//������
int main()
{
    SeqList mylist; //��������
    Init_List(&mylist); //��ʼ������

    int x, pos; //Ҫ�������
    int find_pos;
    int delete_pos;

    int select = 1;

    while (select)
    {
        printf("**************************************\n");
        printf("* [1]    push_back(β��)               [2]   push_fornt(ͷ��)              *\n");
        printf("* [3]    show_list(�鿴ѭ���)         [4]   pop_back(βɾ)                *\n");
        printf("* [5]    pop_front(ͷɾ)               [6]   insert_pos(��λ�ò���)        *\n");
        printf("* [7]    find(��ֵ����)                [8]   lenght(��˳�����)          *\n");
        printf("* [9]    delete_pos(��λ��ɾ��)        [10]  delete_val(��ֵɾ��)          *\n");
        printf("* [11]   sort(����)                    [12]  reverse(����)                 *\n");
        printf("* [13]   clear(���˳���)             [14]  destroy(�ݻ�˳���)           *\n");
        printf("* [15]   quit_system(�˳�ϵͳ)                                             *\n");
        printf("**************************************\n");
        cout << endl;
        printf("��ѡ����������ֽ��в���:>");

        scanf("%d", &select);

        cout << endl;

        if (select == 0) break;

        switch (select)
        {
        case 1:
            cout << "����Ҫ���������(-1����):>";
            while (scanf("%d", &x), x != -1)
            {
                cout << endl;
                push_back(&mylist, x);
                cout << "���ٴ�����Ҫ���������(-1����):>";
            }
            cout << endl;
            break;
        case 2:
            cout << "����Ҫ���������(-1����):>";
            while (scanf("%d", &x), x != -1)
            {
                cout << endl;
                push_front(&mylist, x);
                cout << "���ٴ�����Ҫ���������(-1����):>";
            }
            break;
        case 3:
            show_list(&mylist);
            break;
        case 4:
            pop_back(&mylist);
            break;
        case 5:
            pop_front(&mylist);
            break;
        case 6:
            cout << "��������ֵ:>";
            scanf("%d", &x);
            cout << "������λ��:>";
            scanf("%d", &pos);
            insert_pos(&mylist, x, pos);
            break;
        case 7:
            cout << "������Ҫ���ҵ�ֵ:>";
            scanf("%d", &x);
            cout << endl;
            find_pos = find(&mylist, x);
            if (find_pos == -1) cout << "���ҵ���ֵ:" << x << endl << endl << "��˳����в�����" << endl << endl;
            else 	             cout << "���ҵ���ֵ:" << x << "----------" << "���±�Ϊ:" << find_pos << "��˳�����" << endl << endl;
            break;
        case 8:
            cout << "˳���ı���:";
            printf("%d", mylist.cnt); //ֱ����� 
            //printf("%d",length(&mylist)) ; //���ú������ 
            cout << endl << endl;
            break;
        case 9:
            cout << "������Ҫɾ����λ��:>";
            scanf("%d", &pos);
            cout << endl;
            remove_pos(&mylist, pos);
            break;
        case 10:
            cout << "������Ҫɾ����ֵ:>";
            scanf("%d", &x);
            cout << endl;
            remove_value(&mylist, x);
            break;
        case 11:
            quick_sort(&mylist);
            break;
        case 12:
            reverse(&mylist);
            break;
        case 13:
            clear(&mylist);
            break;
        case 14:
            destroy(&mylist);
            return 0;
        case 15:
            cout << "�ɹ��˳�ϵͳ!" << endl;
            return 0;
        }
    }

    return 0;
}
