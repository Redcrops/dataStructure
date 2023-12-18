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
    INVAILD_ACCESS,
};

#define DEFAULT_SIZE 10

// 静态函数前置声明
static int expandDynamicCapacity(dynamicArray *pArray);

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
int dynamicArrayInsertData(dynamicArray *pArray, ELEMENTTYPE val)
{
    dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}

// 动态数组扩容
static int expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    // 备份指针
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
    // 判malloc空
    if (!pArray->data)
    {
        return MALLOC_ERROR;
    }

    // 拷贝之前的数据
    for (int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }
    // memcpy(pArray->data,tmpPtr,sizeof(tmpPtr));

    // 释放之前的内存，避免内存泄漏
    if (tmpPtr)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    pArray->capacity = needExpandCapacity;
    return 0;
}

// 动态数组插入数据，在指定位置插入
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    // 指针判空
    if (!pArray)
    {
        return NULL_PTR;
    }

    // 判断位置的合法性
    if (pos < 0 || pos > pArray->len)
    {
        return INVAILD_ACCESS;
    }

    // 扩容的临界值是len大于容量的三分之二
    if (pArray->len + (pArray->len >> 1) > pArray->capacity)
    {
        // 开始扩容
        expandDynamicCapacity(pArray);
    }
#if 0 // 会覆盖
    // while (pos<pArray->len)
    // {
    //     pArray->data[pos+1] = pArray->data[pos];
    //     pos++;
    // }
#endif

    // 数据从数组尾部后移一位，腾出pos位置
    for (int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }

    // 找到对应值，写入数组中
    pArray->data[pos] = val;
    (pArray->len)++;
}

// 动态数组修改指定位置的数据
int dynamicArrayAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    // 指针判空
    if (!pArray)
    {
        return NULL_PTR;
    }

    // 判断位置的合法性
    if (pos < 0 || pos > pArray->len)
    {
        return INVAILD_ACCESS;
    }

    // 更新元素数据
    pArray->data[pos] = val;

    return ON_SUCCESS;
}

// 动态数组删除数据(默认情况下删除最后末尾的数据)
int dynamicArrayDeleteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointData(pArray, pArray->len - 1);
}

// 缩容,内部使用，无需判空
static int shrinkDynamicCapacity(dynamicArray *pArray)
{

    int needShrinkCapacity = pArray->capacity - (pArray->capacity >> 1);

    // 拷贝指针
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);
    // 判malloc空
    if (!pArray->data)
    {
        return MALLOC_ERROR;
    }

    // 拷贝数据
    for (int idx = 0; idx < needShrinkCapacity; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    // 回收内存
    if (tmpPtr)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    pArray->capacity = needShrinkCapacity;
    return ON_SUCCESS;
}
// 动态数组删除指定位置数据
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    // 判空
    if (!pArray)
    {
        return NULL_PTR;
    }

    // 判断插入位置的合法性
    if (pos < 0 || pos > pArray->len)
    {
        return INVAILD_ACCESS;
    }

    // 缩容
    if (pArray->len < pArray->capacity >> 1)
    {
        shrinkDynamicCapacity(pArray);
    }
    // 数据前移
    for (int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    // 更新数据的大小
    pArray->len--;
}

// 动态数组删除指定元素
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
    if (!pArray)
    {
        return NULL_PTR;
    }
    for (int idx = pArray->len - 1; idx >= 0; idx--)
    {
        if (val == pArray->data[idx])
        {

            dynamicArrayDeleteAppointPosData(pArray, idx);
        }
    }
    return ON_SUCCESS;
}

// 动态数组销毁
int dynamicArrayDestroy(dynamicArray *pArray)
{
    if (!pArray)
    {
        return NULL_PTR;
    }

    if (pArray->data)
    {
        free(pArray->data);
        pArray->data = NULL;
    }

    pArray->capacity = 0;
    pArray->len = 0;
    return ON_SUCCESS;
}

// 获取动态数组大小
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    if (!pArray)
    {
        return NULL_PTR;
    }

    if (pSize)
    {
        *pSize = pArray->len;
    }

    return ON_SUCCESS;
}

// 获取数组的容量
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{
    if (!pArray)
    {
        return NULL_PTR;
    }

    if (!pCapacity)
    {
        *pCapacity = pArray->capacity;
    }

    return ON_SUCCESS;
}

// 获取指定位置的元素数据
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{

    if (pArray == NULL)
    {
        return NULL_PTR;
    }

    if (pos < 0 || pos > pArray->len)
    {
        return INVAILD_ACCESS;
    }

    if (pVal)
    {
        return pArray->data[pos];
    }
}