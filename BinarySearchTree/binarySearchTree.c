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

    /*为根节点分配空间*/
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    /*清除脏数据*/
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);

    /*初始化根节点*/
    bstree->root->left = NULL;
    bstree->root->parent = NULL;
    bstree->root->right = NULL;
    bstree->root->data = 0;

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
// 二叉搜索树的插入
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
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
    /*分配新节点
     */
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);

    newBstNode->data = val;
    newBstNode->left = NULL;
    newBstNode->right = NULL;
    newBstNode->parent = NULL;

    /*新节点赋值*/
    newBstNode->data = val;

    if (cmp < 0)
    { /*挂在左子树*/
        parentNode->left = newBstNode;
    }
    else
    { /*挂在右子树*/
        parentNode->right = newBstNode;
    }

    newBstNode->parent = parentNode;
    (pBstree->size)++;
    return ON_SUCCESS;
}