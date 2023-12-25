#ifndef __COMMON_H_
#define __COMMON_H_


/* 万能指针 */
#define ELEMENTTYPE void*

typedef struct node
{
    ELEMENTTYPE val;                /* 数据 */
    struct node * prev;     /* 前置指针 */
    struct node * next;     /* 后置指针 */
} Node;

typedef struct linkList
{
    Node *head;
    Node *tail;
    int len;
} linkList;


#endif //__COMMON_H_