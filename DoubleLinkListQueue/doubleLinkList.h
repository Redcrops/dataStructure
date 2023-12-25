#ifndef __DoubleLinkList_H_
#define __DoubleLinkList_H_
#define ELEMENTTYPE void *

typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;

    // 指向前一个节点的指针
    struct DoubleLinkNode *prev;
    // 指向下一个节点的指针
    struct DoubleLinkNode *next; // 指针的类型为什么是节点
} DoubleLinkNode;

typedef struct DoubleLinkList
{
    // 链表的虚拟头结点，数据域无意义，只使用指针域
    DoubleLinkNode *head;
    DoubleLinkNode *tail; // 为什么尾指针不需要分配空间
    // 链表的长度
    int len;
} DoubleLinkList;

// 链表初始化
int DoubleLinkListInit(DoubleLinkList **pList);

// 链表头插
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val);

// 链表尾插
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val);

// 链表指定位置插入
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val);

// 链表头删
int DoubleLinkListHeadDel(DoubleLinkList *pList);

// 链表尾删
int DoubleLinkListTailDel(DoubleLinkList *pList);

// 链表指定位置删除
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos);

// 链表删除指定数据
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));

// 获取链表长度
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

// 链表销毁
int DoubleLinkListDestroy(DoubleLinkList *pList);

// 遍历链表
int DoubleLinkListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));

// 双向链表逆序打印
int DoubleLinkListReverseForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTYPE));
#endif //__DoubleLinkList_H_