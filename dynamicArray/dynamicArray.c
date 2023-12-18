#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 状态码
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
};

#define DEFAULT_SIZE 10

// 动态数组初始化
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if (!pArray)
    {
        return NULL_PTR;
    }

    // 避免传入非法制
    if (capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * 1);
    if (!pArray->data)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

// 动态数组插入数据(默认插入到数组的末尾)
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val);

// 动态数组插入数据，在指定位置插入
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

// 动态数组修改指定位置的数据
int dynamicArrayAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

// 动态数组删除数据(默认情况下删除最后末尾的数据)
int dynamicArrayDeleteData(dynamicArray *pArray);

// 动态数组删除指定位置数据
int dynamicArrayDeletePosData(dynamicArray *pArray, int pos);

// 动态数组删除指定元素
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);

// 动态数组销毁
int dynamicArrayDestroy(dynamicArray *pArray);

// 获取动态数组大小
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

// 获取数组的容量
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);