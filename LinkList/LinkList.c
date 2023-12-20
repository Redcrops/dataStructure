#include "LinkList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
};
// 链表初始化
static int checkPlist(LinkList *pList);
static int checkPos(LinkList *pList, int pos);
static int checkMallocNode(LinkNode *Node);
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
    if (pos < 0 || pos > pList->len)
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
        //尾指针更新
        pList->tail = newNode;
    }

    newNode->data = 0;
    newNode->next = NULL;

    // 更新链表长度
    pList->len++;
    return ON_SUCCESS;
}

// 链表头删
int LinkListHeadDel(LinkList *pList)
{
}

// 链表尾删
int LinkListTailDel(LinkList *pList)
{
}

// 链表指定位置删除
int LinkListDelAppointPos(LinkList *pList, int pos)
{
}

// 链表删除指定数据
int LinkListDelAppointData(LinkList *pList, ELEMENTTYPE val)
{
}

// 获取链表长度
int LinkListGetLength(LinkList *pList, int *pSize)
{
    checkPlist(pList);
    if (pSize != NULL)
    {
        *pSize = pList->len;
    }
    return ON_SUCCESS;
}

// 链表销毁
int LinkListDestroy(LinkList *pList)
{
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