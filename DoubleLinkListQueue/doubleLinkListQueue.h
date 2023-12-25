#ifndef __DOUBLE_LINK_LIST_QUEUE_H_
#define __DOUBLE_LINK_LIST_QUEUE_H_

/*队列初始化*/
int doublelinklistQueueInit();

/*入队*/
int doubleLinkListQueuePush();

/*查看队头元素*/
int doubleLinkListTop();

/*队尾元素*/
int doubleLinkListTail();

/*出队*/
int doublelinklistQueuePop();

/*队列大小*/
int doubleLinkListQueueSize();

/*队列是否为空*/
int whetherDoubleLinkListIsEmpty();

/*队列销毁*/
int doubleLinkListDestroy();

#endif