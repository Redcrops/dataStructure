#ifndef __LINKLIST_H_
#define __LINKLIST_H_

/* 状态码 */
enum STATUSCODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERR,
    INVAILD_ACCESS,
};

/* 万能指针 */
#define ELEMENTTYPE void*

typedef struct linkNode
{
    ELEMENTTYPE val;                /* 数据 */
    struct linkNode * prev;     /* 前置指针 */
    struct linkNode * next;     /* 后置指针 */
} LinkNode;

typedef struct linkList
{
    LinkNode *head;
    LinkNode *tail;
    int len;
} linkList;

/* 链表的初始化 */
int doubleLinkListInit(linkList **pList);

/* 头插 */
int doubleLinkListHeadInsert(linkList *pList, ELEMENTTYPE val);

/* 尾插 */
int doubleLinkListTailInsert(linkList *pList, ELEMENTTYPE val);

/* 指定位置插入 */
int doubleLinkListAppointPosInsert(linkList *pList, int pos, ELEMENTTYPE val);

/* 获取链表的数据 */
int doubleLinkListGetLength(linkList *pList, int *pLen);

/* 顺序遍历链表 */
int doubleLinkListSeqForeach(linkList *pList);

/* 逆序遍历链表 */
int doubleLinkListReverseForeach(linkList *pList);

/* 头删 */
int doubleLinkListHeadDel(linkList *pList);

/* 尾删 */
int doubleLinkListTailDel(linkList *pList);

/* 任意位置删除 */
int doubleLinkListAppointPosDel(linkList *pList, int pos);

/* 链表销毁 */
int doubleLinkListDestory(linkList *pList);

/* 获取链表 头部数据 */
int doubleLinkListGetHeadVal(linkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 尾部数据 */
int doubleLinkListGetTailVal(linkList *pList, ELEMENTTYPE *pVal);

/* 获取链表 指定位置数据 */
int doubleLinkListGetAppointPosVal(linkList *pList, int pos, ELEMENTTYPE *pVal);


#endif  //__LINKLIST_H_