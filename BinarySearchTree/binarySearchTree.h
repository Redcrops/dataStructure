#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#define ELEMENTTYPE void *
#include "common.h"
typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct BSTreeNode *left;   /*左子树*/
    struct BSTreeNode *right;  /*右子树*/
    struct BSTreeNode *parent; /*父结点*/
} BSTreeNode;
typedef struct BinarySearchTree
{
    /*根节点*/
    BSTreeNode *root;
    /*树的节点*/
    int size;

    // 钩子函数比较器放到结构体内部
    int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);

    // 钩子函数包装器实现自定义打印函数接口
    int (*printFunc)(ELEMENTTYPE val);
    /*把队列的属性放在树里面*/
    // DoubleLinkListQueue *pQueue;
} BinarySearchTree;

// 二叉搜索树初始化
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val));

// 二叉搜索树的插入
int binarySearchTreeInsertVal(BinarySearchTree *pBstree, ELEMENTTYPE val);

// 二叉搜索树是否包含指定元素
int binarySearchTreeContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val);

// 二叉搜索树的前序遍历
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);

// 二叉搜索树的中序遍历
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);

// 二叉搜索树的后序遍历
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);

// 二叉搜索树的层次遍历
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree);

// 获取二叉搜索树的高度
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight);

/*二叉搜索树的删除*/
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val);

/*二叉搜索树的销毁*/
int binarySearchTreeDestroy(BinarySearchTree *pBstree);
#endif //__BINARY_SEARCH_TREE_H_