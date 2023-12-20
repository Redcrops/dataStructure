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
int LinkListInit();

// 链表头插
int LinkListHeadInsert();

// 链表尾插
int LinkListTailInsert();

// 链表指定位置插入
int LinkListAppointPosInsert();

// 链表头删
int LinkListHeadDel();

// 链表尾删
int LinkListTailDel();

// 链表指定位置删除
int LinkListDelAppointPos();

// 删除指定数据
int LinkListDelAppointData();

// 获取链表长度
int LinkListGetLength();

// 链表销毁
int LinkListDestroy();
#endif //__LINKLIST_H_