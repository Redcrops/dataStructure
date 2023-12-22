#include "doubleLinkList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
};
// 静态函数只在源文件起作用
static int checkPlist(DoubleLinkList *pList);
static int checkPos(DoubleLinkList *pList, int pos);
static int checkMallocNode(DoubleLinkNode *Node);
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
static DoubleLinkList *createDoubleLinkNode(ELEMENTTYPE val);
// 链表初始化
int DoubleLinkListInit(DoubleLinkList **pList)
{
    // 分配内存，判空，初始化
    DoubleLinkList *list = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);

    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清空脏数据
    memset(list, 0, sizeof(DoubleLinkList) * 1);

    list->head = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清空脏数据
    memset(list->head, 0, sizeof(DoubleLinkNode) * 1);

    // 链表长度为0
    list->len = 0;

    list->head->data = 0;
    list->head->next = NULL;
    list->head->prev = NULL;

    // 初始化的时候尾指针=头指针
    list->tail = list->head;

    // 二级指针
    *pList = list;
    return ON_SUCCESS;
}

// 链表头插
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

// 链表尾插
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}
static int checkPlist(DoubleLinkList *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
}
static int checkPos(DoubleLinkList *pList, int pos)
{
    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }
}
static int checkMallocNode(DoubleLinkNode *Node)
{
    if (Node == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(Node, 0, sizeof(DoubleLinkNode) * 1);
}
static DoubleLinkList *createDoubleLinkNode(ELEMENTTYPE val)
{
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (newNode == NULL)
    {
        return NULL;
    }
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 链表指定位置插入
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val)
{
    checkPlist(pList);

    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    DoubleLinkNode *travelNode = pList->head;

    // 新建新结点封装成函数
    DoubleLinkNode *newNode = createDoubleLinkNode(val);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
#if 0
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    checkMallocNode(newNode);

    newNode->data = val;
    newNode->next = NULL;
#endif
    int flag = 0;
    // 这种情况下需要更改尾指针
    if (pos == pList->len)
    {
        travelNode = pList->tail;
        // newNode->next = travelNode->next;
        // travelNode->next = newNode;
        flag = 1;
    }
    else
    {
        for (int idx = 0; idx < pos; idx++)
        {
            travelNode = travelNode->next;
        }
    }
    // 修改节点指向
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    travelNode->next->prev = newNode;
    travelNode->next = newNode;
    if (flag)
    {
        // 尾指针更新
        pList->tail = newNode;
    }

    // 更新链表长度
    (pList->len)++;
    return ON_SUCCESS;
}

// 链表头删
int DoubleLinkListHeadDel(DoubleLinkList *pList)
{
    return DoubleLinkListDelAppointPos(pList, 1);
}

// 链表尾删
int DoubleLinkListTailDel(DoubleLinkList *pList)
{
    return DoubleLinkListDelAppointPos(pList, pList->len);
}

// 链表指定位置删除
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos)
{
    checkPlist(pList);
    if (pos <= 0 && pos > pList->len)
    {
        return INVAILD_ACCESS;
    }
    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }
    DoubleLinkNode *travelNode = pList->head;
    while (--pos)
    {
        travelNode = travelNode->next;
    }
    DoubleLinkNode *needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;
    if (flag)
    {
        pList->tail = travelNode;
    }

    if (needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    (pList->len)--;
    return ON_SUCCESS;
}

// 根据指定元素得到在链表中所在的位置
static int DoubleLinkListAccordAppointValGetPos(DoubleLinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    DoubleLinkNode *travelNode = pList->head->next;
    int pos = 1;
    for (; pos <= pList->len; pos++)
    {
        // if (travelNode->data == val)
        // {
        //     *pPos = pos;
        //     return pos;
        // }

        int cmp = compareFunc(val, travelNode);
        if (cmp = 0)
        {
            *pPos = pos;
            return pos;
        }
        travelNode = travelNode->next;
    }

    *pPos = NOT_FIND;
    return NOT_FIND;
}

// 链表删除指定数据
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    int pos = 0;
    int len = 0;
    while (DoubleLinkListGetLength(pList, &len) && pos != NOT_FIND)
    {
        DoubleLinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        DoubleLinkListDelAppointPos(pList, pos);
    }

    return ON_SUCCESS;
}

// 获取链表长度
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize)
{
    checkPlist(pList);
    if (pSize != NULL)
    {
        *pSize = pList->len;
    }
    return pList->len;
}

// 链表销毁
int DoubleLinkListDestroy(DoubleLinkList *pList)
{
    int size = 0;
    while (DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }
    if (pList->head != NULL)
    {
        free(pList->head);
        // 指针置为NULL
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ON_SUCCESS;
}

// 链表遍历
int DoubleLinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE))
// int DoubleLinkListForeach(DoubleLinkList *pList)
{
    checkPlist(pList);
    DoubleLinkNode *travelNode = pList->head; // 两种遍历方式
    // DoubleLinkNode *travelNode = pList->head->next;
#if 0 // for
    // for(int idx=0;idx<pList->len;idx++){
    //     printf("data=%d\n",travelNode->data);
    //     travelNode=travelNode->next;
    // }
#endif
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;

        // printf("data=%d\n", *(int *)(travelNode->data));

        // 包装器，钩子，回调函数
        printFunc(travelNode->data);
        // travelNode = travelNode->next;
    }
    printf("\n");
    return ON_SUCCESS;
}