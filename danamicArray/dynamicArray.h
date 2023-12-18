#ifndef __DANAMIC_ARRAY_H_
#define __DANAMIC_ARRAY_H_
typedef int ELEMENTTYPE

    // 避免头文件包含

    typedef struct dynamicArray
{
    ELEMENTTYPE *data; // 数组空间
    int len;           // 数组大小
    int capacity;      // 数组容量
} dynamicArray;

#endif //__DANAMIC_ARRAY_H_