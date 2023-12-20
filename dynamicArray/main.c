#include <stdio.h>
#include "dynamicArray.h"
#include <string.h>
#define BUFFER_SIZE 10
#define DEFAULT_SIZE 5
#define DEFAULT_NUM 3
typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo;

int main()
{
    /* 静态数组
         1.不够灵活
         2.可能会有浪费的现象
    */
    dynamicArray array;
    dynamicArrayInit(&array, BUFFER_SIZE);

#if 1
    // 模块化
    int idx = 1;
    for (; idx < 4; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&idx);
    }
    //idx=4,地址：0x7fffffffdfd8

    // 获取动态数组大小

    // int size = 0;
    // dynamicArrayGetSize(&array, &size);
    // printf("size=%d\n", size);

    int len = 0;
    dynamicArrayGetSize(&array, &len);

    int *val = NULL;
    for (int idx = 0; idx < len; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val=%d\n", *val);
    }

    // 打印数据

    // 删除指定位置的元素

    // dynamicArrayDeleteData(&array);
#endif
#if 0
    int len = 0;
    dynamicArrayGetSize(&array, &len);
    int *val = NULL;
    printf("len=%d\n", len);
    for (int idx = 0; idx < len; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val=%d\n", *val);
    }

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

    stuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }

    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size=%d\n", size);

    stuInfo *info = NULL;
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&info);
        printf("info.age=%d\t,info.sex=%c\n", info->age, info->sex);
    }
#endif
#if 0
    int buffer[DEFAULT_NUM] = {1, 2, 3};
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size=%d\n", size);

    int num3 = 10;
    dynamicArrayAppointPosData(&array, 0, &num3);

    int *val = NULL;
    for (int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val=%d\n", *val);
    }
#endif
#if 0
    stuInfo stu1 = {
        10, 'm'};
    dynamicArrayInsertData(&array, (void *)&stu1);
    stuInfo *val = NULL;
    dynamicArrayGetAppointPosVal(&array, 0, (void *)&val);
    printf("array.data[0]=%d\n", val->age);

    int num[] = {1, 2, 3};
    for (int idx = 0; idx < 3; idx++)
    {
        dynamicArrayInsertData(&array, &num[idx]);
    }
    int *recval = NULL;
    for (int idx = 1; idx < 4; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&recval);
        printf("recval[%d]=%d\n", idx, *recval);
    }
    dynamicArrayDeleteAppointData(&array,(void*)&)
#endif
    return 0;
}