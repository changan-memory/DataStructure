#define _CRT_SECURE_NO_WARNINGS 1

#include<algorithm>

#include <iostream>
using namespace std;
//顺序表的实现有两种 ： 链表 / 数组 , 本Demo为数组实现顺序表,动态分配空间
const int Max_size = 8; //定义顺序表的长度
//定义数组实现顺序表的结构体
typedef struct SeqList
{
    int* pBase; //动态申请空间
    int size; //数组容量
    int cnt; //数组当前个数
}SeqList;
//初始化操作
void Init_List(SeqList* pArr)
{
    //分配空间
    pArr->pBase = (int*)malloc(sizeof(int) * Max_size);

    //动态分配失败写法 (1)
    //利用# include <stdlib.h>  //包含了exit函数
    if (NULL == pArr->pBase)
    {
        cout << "动态内存分配失败" << endl;
        exit(-1);
    }
    //动态分配失败写法 (2)
    //利用# include <assert.h> //包含了assert函数
    //assert(条件)作用：如果条件返回错误，则程序终止
    //assert(pArr -> base != NULL) ; 

    //赋值
    pArr->size = Max_size;
    pArr->cnt = 0;

}
//清空顺序表
void clear(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "清空顺序表失败,顺序表已经为空，无法进行清空操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    pArr->cnt = 0;
    cout << "清空成功" << endl << endl;
}
//求表长
int length(SeqList* pArr)
{
    return pArr->cnt;
}
//按位置插入操作
void insert_pos(SeqList* pArr, int x, int pos)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "顺序表空间已满，无法进行按位置插入操作，系统将自动返回界面：" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }

    if (pos < 0 || pos > pArr->cnt)
    {
        cout << "插入失败！您输入的位置有误，系统将自动返回界面" << endl;
        cout << endl;
        return;
    }

    for (int i = pArr->cnt - 1; i >= pos; i--)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }

    pArr->pBase[pos] = x;

    pArr->cnt++;

    cout << "插入成功" << endl << endl;


}
//尾插操作
void push_back(SeqList* pArr, int x)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "顺序表空间已满，无法进行尾插操作，请按-1退出：" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    pArr->pBase[pArr->cnt] = x;
    pArr->cnt++;

}
//头插操作
void push_front(SeqList* pArr, int x)
{
    if (pArr->cnt >= pArr->size)
    {
        cout << "顺序表空间已满，无法进行头插操作，请按-1退出：" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    for (int i = pArr->cnt; i > 0; i--)
    {
        pArr->pBase[i] = pArr->pBase[i - 1];
    }

    pArr->pBase[0] = x;

    pArr->cnt++;
}
//尾删操作
void pop_back(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "尾删失败,顺序表为空，无法进行尾删操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    cout << "尾删成功" << endl << endl;
    pArr->cnt--;

}
//头删操作
void pop_front(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "头删失败,顺序表为空，无法进行头删操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    for (int i = 1; i <= pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }

    cout << "尾删成功" << endl << endl;

    pArr->cnt--;

}
//按值删除操作
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
        cout << "按值插入失败,系统将返回界面" << endl << endl;
        return;
    }
    else
    {
        for (int i = flag + 1; i < pArr->cnt; i++)
        {
            pArr->pBase[i - 1] = pArr->pBase[i];
        }
        pArr->cnt--;
        cout << "删除成功" << endl << endl;
    }
}
//按位置删除操作
void remove_pos(SeqList* pArr, int pos)
{
    if (pos < 0 || pos >= pArr->cnt)
    {
        cout << "按位置删除失败,输入的位置不合理，无法进行删除操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    for (int i = pos + 1; i <= pArr->cnt; i++)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    cout << "删除成功!!!" << endl << endl;
    pArr->cnt--;
}
//按值查找，返回下标 
int find(SeqList* pArr, int x)
{
    for (int i = 0; i < pArr->cnt; i++)
    {
        if (pArr->pBase[i] == x) return i;
    }
    return -1;
}
//排序

void quick_sort(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "排序失败,顺序表为空，无法进行头删操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    sort(pArr->pBase, pArr->pBase + pArr->cnt);
    cout << "排序成功" << endl << endl;
}
//销毁顺序表
void destroy(SeqList* pArr)
{
    free(pArr->pBase);
    pArr->pBase = NULL;
    pArr->cnt = 0;
    pArr->size = 0;
    cout << "销毁成功,无法进行任何操作,系统将结束!!" << endl;
}
//倒置
void reverse(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "倒置失败,顺序表为空，无法进行头删操作，系统将自动返回操作界面" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }
    int i = 0, j = pArr->cnt - 1;
    while (i < j)
    {
        swap(pArr->pBase[i], pArr->pBase[j]);
        i++, j--;
    }
    cout << "倒置成功" << endl << endl;
}
//显示当前顺序表操作
void show_list(SeqList* pArr)
{
    if (pArr->cnt == 0)
    {
        cout << "顺序表为空,请进行插入数据,系统将自动返回操作界面!" << endl;
        cout << endl;
        return; //回到调用函数的地方，执行下一行 
    }

    for (int i = 0; i < pArr->cnt; i++)
    {
        cout << pArr->pBase[i] << " ";
    }
    cout << endl;

    cout << endl << "以上是链表当前状态" << endl;

    cout << endl;

}
//主函数
int main()
{
    SeqList mylist; //创建链表
    Init_List(&mylist); //初始化链表

    int x, pos; //要插入的数
    int find_pos;
    int delete_pos;

    int select = 1;

    while (select)
    {
        printf("**************************************\n");
        printf("* [1]    push_back(尾插)               [2]   push_fornt(头插)              *\n");
        printf("* [3]    show_list(查看循序表)         [4]   pop_back(尾删)                *\n");
        printf("* [5]    pop_front(头删)               [6]   insert_pos(按位置插入)        *\n");
        printf("* [7]    find(按值查找)                [8]   lenght(求顺序表长度)          *\n");
        printf("* [9]    delete_pos(按位置删除)        [10]  delete_val(按值删除)          *\n");
        printf("* [11]   sort(排序)                    [12]  reverse(倒置)                 *\n");
        printf("* [13]   clear(清空顺序表)             [14]  destroy(摧毁顺序表)           *\n");
        printf("* [15]   quit_system(退出系统)                                             *\n");
        printf("**************************************\n");
        cout << endl;
        printf("请选择上面的数字进行操作:>");

        scanf("%d", &select);

        cout << endl;

        if (select == 0) break;

        switch (select)
        {
        case 1:
            cout << "输入要插入的数据(-1结束):>";
            while (scanf("%d", &x), x != -1)
            {
                cout << endl;
                push_back(&mylist, x);
                cout << "请再次输入要插入的数据(-1结束):>";
            }
            cout << endl;
            break;
        case 2:
            cout << "输入要插入的数据(-1结束):>";
            while (scanf("%d", &x), x != -1)
            {
                cout << endl;
                push_front(&mylist, x);
                cout << "请再次输入要插入的数据(-1结束):>";
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
            cout << "请插入的数值:>";
            scanf("%d", &x);
            cout << "请插入的位置:>";
            scanf("%d", &pos);
            insert_pos(&mylist, x, pos);
            break;
        case 7:
            cout << "请输入要查找的值:>";
            scanf("%d", &x);
            cout << endl;
            find_pos = find(&mylist, x);
            if (find_pos == -1) cout << "查找的数值:" << x << endl << endl << "在顺序表中不存在" << endl << endl;
            else 	             cout << "查找的数值:" << x << "----------" << "在下标为:" << find_pos << "的顺序表中" << endl << endl;
            break;
        case 8:
            cout << "顺序表的表长是:";
            printf("%d", mylist.cnt); //直接输出 
            //printf("%d",length(&mylist)) ; //调用函数输出 
            cout << endl << endl;
            break;
        case 9:
            cout << "请输入要删除的位置:>";
            scanf("%d", &pos);
            cout << endl;
            remove_pos(&mylist, pos);
            break;
        case 10:
            cout << "请输入要删除的值:>";
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
            cout << "成功退出系统!" << endl;
            return 0;
        }
    }

    return 0;
}
