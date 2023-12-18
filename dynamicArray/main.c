#include <stdio.h>
#include "dynamicArray.h"
#define BUFFER_SIZE 10
#define DEFAULT_SIZE 5
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

#if 0
    // 模块化
    {
        // 插入数据
        dynamicArrayInsertData(&array, 3);
        for (int idx = 0; idx < 3; idx++)
        {
            dynamicArrayInsertData(&array, 21);
        }
    }

    // 获取动态数组大小

    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size=%d\n", size);
    // printf("111");

    int val = 0;
    for (int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val=%d", val);
    }

    // 删除指定位置的元素
    int pos = 1;
    dynamicArrayDeletePosData(&array, pos);
#endif
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

    dynamicArrayInsertData(&array, stu1);
    dynamicArrayInsertData(&array, stu2);
    dynamicArrayInsertData(&array, stu3);
    return 0;
}