#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVAILD_ACCESS,
};
/*静态函数前置声明*/
/*比较函数*/
static int comparaFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

// 创建节点
static BSTreeNode *createBSTreeNode(ELEMENTTYPE val, BSTreeNode *parentNode);
// 根据指定值获得二叉搜索树的结点
static BSTreeNode *baseAppointValGetNode(BinarySearchTree *pBstree, ELEMENTTYPE val);
// 二叉搜索树初始化
int binarySearchTreeInit(BinarySearchTree **pBstree)
{
    /*为树分配空间*/
    BinarySearchTree *bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /*清除脏数据*/
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);

    bstree->root = NULL;
    bstree->size = 0;
#if 0 /*为根节点分配空间*/
    // /*为根节点分配空间*/
    // bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    // if (bstree->root == NULL)
    // {
    //     return MALLOC_ERROR;
    // }
    // /*清除脏数据*/
    // memset(bstree->root, 0, sizeof(BSTreeNode) * 1);

    // /*初始化根节点*/
    // bstree->root->left = NULL;
    // bstree->root->parent = NULL;
    // bstree->root->right = NULL;
    // bstree->root->data = 0;
#endif
    /*为根节点分配空间*/
    bstree->root = createBSTreeNode(0, NULL);
    /*解引用*/
    *pBstree = bstree;

    return ON_SUCCESS;
}
static int checkBstree(BinarySearchTree *pBstree)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
}
#if 0 // 比较函数优化为回调函数
static int comparaFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    // if (val1 < val2)
    // {
    //     return -1;
    // }
    // else if (val1 > val2)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }

    return val1 - val2;
}
#endif
// 创建节点,并确定新节点的父节点
static BSTreeNode *createBSTreeNode(ELEMENTTYPE val, BSTreeNode *parentNode)
{
    /*分配新节点*/
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return NULL;
    }
    /*清除脏数据*/
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);

    newBstNode->data = val;
    newBstNode->left = NULL;
    newBstNode->right = NULL;
    newBstNode->parent = NULL;

    /*新节点赋值*/
    newBstNode->data = val;

    /*更新新节点的父结点*/
    newBstNode->parent = parentNode;
    return newBstNode;
}

// 二叉搜索树的插入
int binarySearchTreeInsertVal(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    if (pBstree->size == 0)
    {
        (pBstree->size)++;
        pBstree->root->data = val;
        return ON_SUCCESS;
    }

    BSTreeNode *travelNode = pBstree->root;
    BSTreeNode *parentNode = pBstree->root;

    /*确定符号：到底放在左边还是右边*/
    int cmp = 0;

    while (travelNode != NULL)
    {
        // 标记待插入位置的父节点
        parentNode = travelNode;
        cmp = comparaFunc(val, travelNode->data);

        /*确定travelnode的移动方向*/
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return ON_SUCCESS;
        }
    }
    BSTreeNode *newBstNode = createBSTreeNode(val, parentNode);

    if (cmp < 0)
    {
        /*挂在左子树*/
        parentNode->left = newBstNode;
    }
    else
    {
        /*挂在右子树*/
        parentNode->right = newBstNode;
    }
#if 0 // 更新新节点的父节点
    newBstNode->parent = parentNode;
#endif
    (pBstree->size)++;
    return ON_SUCCESS;
}

// 根据指定值获得二叉搜索树的结点
static BSTreeNode *baseAppointValGetNode(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode *travelNode = pBstree->root;
    while (travelNode != NULL)
    {
    }
}
// 二叉搜索树是否包含指定元素
int binarySearchTreeContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return ON_SUCCESS;
}
// 二叉搜索树的前序遍历
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
}
// 二叉搜索树的中序遍历
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
}

// 二叉搜索树的后序遍历
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
}

// 二叉搜索树的层次遍历
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
}