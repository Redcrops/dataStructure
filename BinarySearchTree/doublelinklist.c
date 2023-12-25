#include "doublelinklist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* command + K + 0 */
/* 链表的初始化 */
int doubleLinkListInit(linkList **pList)
{
    int ret = 0;
    linkList *plist = (linkList *)malloc(sizeof(linkList) * 1);    
    if (!plist)
    {
        return -1;
    }
    /* 清空内存中的脏数据 */
    memset(plist, 0, sizeof(linkList) * 1);
    
    plist->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if (!(plist->head))
    {
        return -1;
    }
    /* 清空内存中的脏数据 */
    memset(plist->head, 0, sizeof(LinkNode) * 1);
    /* 初始化链表 */
    plist->len = 0;
    /* 初始化虚拟结点*/
    plist->head->val = 0;
    plist->head->next = NULL;
    /* 初始化尾指针 */
    plist->tail = plist->head;

    *pList = plist;
    return ret;
}

/* 头插 */
int doubleLinkListHeadInsert(linkList *pList, ELEMENTTYPE val)
{
    return doubleLinkListAppointPosInsert(pList, 0, val);
}

/* 尾巴 */
int doubleLinkListTailInsert(linkList *pList, ELEMENTTYPE val)
{
    int pos = pList->len;
    return doubleLinkListAppointPosInsert(pList, pos, val);
}

/* 指定位置插 */
int doubleLinkListAppointPosInsert(linkList *pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if (!pList)
    {
        return NULL_PTR;
    }
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if (!newnode)
    {
        return MALLOC_ERR;
    }
    memset(newnode, 0, sizeof(LinkNode));
    /* 维护新的节点 */
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;


    /* 判断位置是否合法 */
    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    /* 备份一下pos的位置 */
    int tmpPos = pos;
    LinkNode * travel = pList->head;
    while (pos)
    {
        pos--;
        travel = travel->next;
    }

    newnode->next = travel->next;       // 1
    /* 没有结点的情况下 */
    if ((pList->len != 0) && (tmpPos != pList->len))
    {
        travel->next->prev = newnode;       // 2
    }
    newnode->prev = travel;             // 3
    travel->next = newnode;             // 4

    /* 更新长度 */
    (pList->len)++;
    return ret;
}

/* 获取链表的数据 此处的返回值返回的是:链表的长度 */
int doubleLinkListGetLength(linkList *pList, int *pLen)
{
    int ret;
    if (!pList || !pLen)
    {
        return 0;
    }
    /* 解引用 */
    *pLen = pList->len;
    return pList->len;
}

#if 0
/* 顺序遍历链表 */
int doubleLinkListSeqForeach(linkList *pList)
{
    int ret = 0;
    if (!pList)
    {
        return -1;
    }

    Node *travel = pList->head->next;
    while(travel != NULL)
    {
        printf("%d\t->", travel->val);
        travel = travel->next;
    }
    printf("\n");
    return ret;
}
#endif

#if 0
/* 逆序遍历链表 */
int doubleLinkListReverseForeach(linkList *pList)
{
    int ret = 0;
    if (!pList)
    {
        return -1;
    }

    Node *travel = pList->head;
    while(travel->next != NULL)
    {
        // printf("%d\t->", travel->val);
        travel = travel->next;
    }

    while (travel != pList->head)
    {
        printf("%d\t->", travel->val);
        travel = travel->prev;
    }
    printf("\n");
    
    return ret;
}
#endif
/* 头删 */
int doubleLinkListHeadDel(linkList *pList)
{
    int ret = 0;
    return doubleLinkListAppointPosDel(pList, 1);
}

/* 尾删 */
int doubleLinkListTailDel(linkList *pList)
{
    int ret = 0;
    int pos = pList->len;
    return doubleLinkListAppointPosDel(pList, pos);
}

/* 任意位置删除 */
int doubleLinkListAppointPosDel(linkList *pList, int pos)
{
    int ret = 0;

    if (!pList)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    LinkNode * travelNode = pList->head;
    while(pos--)
    {
        travelNode = travelNode->next;
    }
    /* 修改*/
    travelNode->prev->next = travelNode->next;
    if (travelNode->next)
    {
        travelNode->next->prev = travelNode->prev;
    }
    free(travelNode);
    travelNode = NULL;

    /* 链表长度减一 */
    pList->len--;

    return ret;
}

/* 链表销毁 */
int doubleLinkListDestory(linkList *pList)
{
    int ret = 0;
    if (!pList)
    {
        return NULL_PTR;
    }

    int len = pList->len;
    for (int idx = 0; idx < len; idx++)
    {
        doubleLinkListHeadDel(pList);
    }
    
    /* 释放虚拟头结点 */
    if (pList->head)
    {
        free(pList->head);
        pList->head = NULL;
    }

    /* 释放链表  */
    if (pList)
    {
        free(pList);
        pList = NULL;
    }

    return ret;
}


/* 获取链表 头部数据 */
int doubleLinkListGetHeadVal(linkList *pList, ELEMENTTYPE *pVal)
{
    return doubleLinkListGetAppointPosVal(pList, 1, pVal);
}

/* 获取链表 尾部数据 */
int doubleLinkListGetTailVal(linkList *pList, ELEMENTTYPE *pVal)
{
    int len = pList->len;
    return doubleLinkListGetAppointPosVal(pList, len, pVal);
}

/* 获取链表 指定位置数据 */
int doubleLinkListGetAppointPosVal(linkList *pList, int pos, ELEMENTTYPE *pVal)
{
    int ret = 0;
    if (!pList)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pList->len)
    {
        return INVAILD_ACCESS;
    }

    LinkNode * travel = pList->head;
    while(pos)
    {
        pos--;
        travel = travel->next;
    }
    *pVal = travel->val;


    return ret;
}