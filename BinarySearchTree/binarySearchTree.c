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
    bstree->root->val = 0;

    /*解引用*/
    *pBstree = bstree;
    
    return ON_SUCCESS;
}

// 二叉搜索树的插入
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;

    return ret;
}