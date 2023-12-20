#include "LinkList.h"
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
static int checkPlist(LinkList *pList);
static int checkPos(LinkList *pList, int pos);
static int checkMallocNode(LinkNode *Node);
static int LinkListAccordAppointValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos);

// 链表初始化
int LinkListInit(LinkList **pList)
{
    // 分配内存，判空，初始化
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);

    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清空脏数据
    memset(list, 0, sizeof(LinkList) * 1);

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清空脏数据
    memset(list->head, 0, sizeof(LinkNode) * 1);

    // 链表长度为0
    list->len = 0;

    list->head->data = 0;
    list->head->next = NULL;

    // 初始化的时候尾指针=头指针
    list->tail = list->head;

    // 二级指针
    *pList = list;
    return ON_SUCCESS;
}

// 链表头插
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

// 链表尾插
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}
static int checkPlist(LinkList *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
}
static int checkPos(LinkList *pList, int pos)
{
    if (pos <= 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }
}
static int checkMallocNode(LinkNode *Node)
{
    if (Node == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(Node, 0, sizeof(LinkNode) * 1);
}
// 链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{
    checkPlist(pList);
    checkPos(pList, pos);
    LinkNode *travelNode = pList->head;
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    checkMallocNode(newNode);
    int flag = 0;
    // 这种情况下需要更改尾指针
    if (pos = pList->len)
    {
        travelNode = pList->tail;
        // newNode->next = travelNode->next;
        // travelNode->next = newNode;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    // 修改节点指向
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if (flag)
    {
        // 尾指针更新
        pList->tail = newNode;
    }

    newNode->data = 0;
    newNode->next = NULL;

    // 更新链表长度
    (pList->len)++;
    return ON_SUCCESS;
}

// 链表头删
int LinkListHeadDel(LinkList *pList)
{
    return LinkListDelAppointPos(pList, 1);
}

// 链表尾删
int LinkListTailDel(LinkList *pList)
{
    return LinkListDelAppointPos(pList, pList->len);
}

// 链表指定位置删除
int LinkListDelAppointPos(LinkList *pList, int pos)
{
    checkPlist(pList);
    checkPos(pList, pos);
    int flag = 0;
    if (pos == pList->len)
    {
        flag = 1;
    }
    LinkNode *travelNode = pList->head;
    while (--pos)
    {
        travelNode = travelNode->next;
    }
    LinkNode *needDelNode = travelNode->next;
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
static int LinkListAccordAppointValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos)
{
    LinkNode *travelNode = pList->head->next;
    int pos = 1;
    for (; pos <= pList->len; pos++)
    {
        if (travelNode->data == val)
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
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val)
{
    int pos = 0;
    int len = 0;
    while (LinkListGetLength(pList, &len) && pos != NOT_FIND)
    {
        LinkListAccordAppointValGetPos(pList, val, &pos);
        LinkListDelAppointPos(pList, pos);
    }

    return ON_SUCCESS;
}

// 获取链表长度
int LinkListGetLength(LinkList *pList, int *pSize)
{
    checkPlist(pList);
    if (pSize != NULL)
    {
        *pSize = pList->len;
    }
    return pList->len;
}

// 链表销毁
int LinkListDestroy(LinkList *pList)
{
    int size = 0;
    while (LinkListGetLength(pList, &size))
    {
        LinkListHeadDel(pList);
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
int linkListforeach(LinkList *pList)
{
    checkPlist(pList);
    // LinkNode *travelNode = pList->head;//两种遍历方式
    LinkNode *travelNode = pList->head->next;
#if 0 // for
    // for(int idx=0;idx<pList->len;idx++){
    //     printf("data=%d\n",travelNode->data);
    //     travelNode=travelNode->next;
    // }
#endif
    while (travelNode->next != NULL)
    {
        // travelNode = travelNode->next;
        printf("data=%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
    return ON_SUCCESS;
}