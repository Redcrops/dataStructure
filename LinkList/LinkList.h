#ifndef __LINKLIST_H_
#define __LINKLIST_H_
#define ELEMENTTYPE void *

typedef struct LinkNode
{
    ELEMENTTYPE data;

    // 指向下一个节点的指针
    struct LinkNode *next; // 指针的类型为什么是节点
} LinkNode;

typedef struct LinkList
{
    // 链表的虚拟头结点，数据域无意义，只使用指针域
    LinkNode *head;

    // 链表的长度
    int len;
} LinkList;

// 链表初始化
int LinkListInit(LinkList **pList);

// 链表头插
int LinkListHeadInsert(LinkList *pList,ELEMENTTYPE val);

// 链表尾插
int LinkListTailInsert(LinkList *pList,ELEMENTTYPE val);

// 链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList,int pos, ELEMENTTYPE val);

// 链表头删
int LinkListHeadDel(LinkList *pList);

// 链表尾删
int LinkListTailDel(LinkList *pList);

// 链表指定位置删除
int LinkListDelAppointPos(LinkList *pList,int pos);

// 链表删除指定数据
int LinkListDelAppointData(LinkList *pList,ELEMENTTYPE val);

// 获取链表长度
int LinkListGetLength(LinkList *pList,int *pSize);

// 链表销毁
int LinkListDestroy(LinkList *pList);
#endif //__LINKLIST_H_