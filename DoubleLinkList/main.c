#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkList.h"

#define BUFFER_SIZE 3

typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int printStruct(void *arg)
{
    stuInfo *info = (stuInfo *)arg;
    printf("age=%d\tsex=%c\n", info->age, info->sex);
    return 0;
}
int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data=%d\n", data);
    return 0;
}
int main()
{
    // 初始化
    LinkList *list = NULL;
    LinkListInit(&list);

#if 1
    // 插入数据
    int array[] = {1, 2, 3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, &array[idx]);
    }

    // 获取链表的长度
    int len = 0;
    LinkListGetLength(list, &len);
    printf("len=%d\n", len);
    // LinkListForeach(list);

    LinkListForeach(list, printBasicData);
    LinkListDelAppointPos(list, 1);
    LinkListForeach(list, printBasicData);
#endif
#if 0
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, (void *)&buffer[idx]);
    }
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size=%d\n", size);
    LinkListForeach(list, printStruct);
    int num1 = 10;
    LinkListAppointPosInsert(list, 0, &num1);
    LinkListForeach(list, printStruct);
#endif
    return 0;
}