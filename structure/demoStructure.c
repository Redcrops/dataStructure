#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 16
#define DEFAULT_SIZE 2
typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFFER_SIZE];
    char *address;
} stuInfo;

// 结构体
// 什么叫结构体:讲不同的类型的属性封装成一个类型
// 2.结构体怎么定义？

// 值传递：不影响实参
#if 0
int printStruct(stuInfo stu)
{
    //栈空间很小不允许超过8M
    printf("stu.age=%d,stu.height=%d,stu.sex=%c,stu.weight=%d,stu.name=%s",
           stu.age, stu.height, stu.sex, stu.weight, stu.name);
    return 0;
};
#endif
// 传入参数：不要改变值
int printStruct(const stuInfo *stu)
{
    // 栈空间很小不允许超过8M
    // 结构体必须用指针
    int ret = 0;
    int len = sizeof(stu);
    printf("len=%d\n", len);
    return 0;
};
int printStructBuffer(stuInfo *stu, int stuSize)
{
    for (int idx = 0; idx < stuSize; idx++)
    {
        printf("stu.age=%d,stu.height=%d,stu.sex=%c,stu.weight=%d,stu.name=%s",
               stu[idx].age, stu[idx].height, stu[idx].sex, stu[idx].weight, stu[idx].name);
        printf("\n");
    }
    return 0;
}

// 结构体会默认进行字节对齐
// 结构的位域到网络编程的时候再深究，todo...
// 变长结构体？？？？？

int main()
{
    stuInfo stu;
    memset(&stu, 0, sizeof(stu));
#if 0
    
    

    stu.age = 10;
    stu.weight = 50;
    stu.sex = 'm';
    stu.height = 170;
    strncpy(stu.name, "zhnagsan", sizeof(stu.name) - 1);
    printf("stu.age=%d,stu.height=%d,stu.sex=%c,stu.weight=%d,stu.name=%s",
           stu.age, stu.height, stu.sex, stu.weight, stu.name);
    printf("\n");

#endif
#if 0 // 结构体数组
    // 结构体的大小
    int len = sizeof(stu);
    printf("len=%d\n", len);

    /*结构体数组
    1.一块连续的地址
    2.存放的是同一数据类型*/
    stuInfo buffer[DEFAULT_SIZE];
    buffer[0].age = 10;
    buffer[0].weight = 30;
    buffer[0].sex = 'm';
    buffer[0].height = 130;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name - 1));

    buffer[1].age = 20;
    buffer[1].weight = 50;
    buffer[1].sex = 'w';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "wangwu", sizeof(buffer[1].name - 1));
    // printf("buffer[0].age=%d,buffer[0].height=%d,buffer[0].sex=%c,buffer[0].weight=%d,buffer[0].name=%s",
    //        buffer[0].age, buffer[0].height, buffer[0].sex, buffer[0].weight, buffer[0].name);
    // printf("\n");
    // printf("buffer[1].age=%d,buffer[1].height=%d,buffer[1].sex=%c,buffer[1].weight=%d,buffer[1].name=%s",
    //        buffer[1].age, buffer[1].height, buffer[1].sex, buffer[1].weight, buffer[1].name);
    // printf("\n");
    printStructBuffer(buffer, sizeof(buffer) / sizeof(buffer[0]));

#endif

#if 0 // 结构体指针
    stu.age = 10;
    stu.weight = 50;
    stu.sex = 'm';
    stu.height = 130;
    strncpy(stu.name, "zhnagsan", sizeof(stu.name) - 1);

    // 回顾指针
    int a = 5;
    int *p = &a;

    // 结构体指针
    stuInfo *info = &stu;
    // 结构体指针读或者写数据，都是用->符号
    info->age = 30;
    printf("info->age=%d\n", info->age);
    printStruct(&stu);

#endif
#if 1

    stu.age = 10;
    stu.weight = 50;
    stu.sex = 'm';
    stu.height = 170;
    strncpy(stu.name, "zhnagsan", sizeof(stu.name) - 1);

    // 结构体里有指针(野指针)，必须要分配空间
    stu.address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!stu.address)
    {
        return NULL;
    }
    strncpy(stu.address, "china", sizeof(stu.address) - 1);

#endif

    return 0;
}