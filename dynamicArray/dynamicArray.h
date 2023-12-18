#ifndef __DANAMIC_ARRAY_H_
#define __DANAMIC_ARRAY_H_
typedef int ELEMENTTYPE;

// 避免头文件包含

typedef struct dynamicArray
{
    ELEMENTTYPE *data; // 数组空间
    int len;           // 数组大小
    int capacity;      // 数组容量
} dynamicArray;

// API：application pragram inferface

// 动态数组初始化
int dynamicArrayInit(dynamicArray *pArray,int capacity);

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

#endif //__DANAMIC_ARRAY_H_