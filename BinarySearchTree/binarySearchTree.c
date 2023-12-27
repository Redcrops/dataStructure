#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <doubleLinkListQueue.h>
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
// 判断二叉搜索树度为2
static int binarySearchTreeHasTwoChild(BSTreeNode *node);
// 判断二叉搜索树度为1
static int binarySearchTreeHasOneChild(BSTreeNode *node);
// 判断二叉搜索树度为0
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);
// 二叉搜索树的前序遍历
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
// 二叉搜索树的中序遍历
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
// 二叉搜索树的后序遍历
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node);
// 获取当前结点的前驱节点
static BSTreeNode *bstreeNodePreDecessor(BSTreeNode *node);

// 获取当前结点的后继节点
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node);
//  二叉搜索树初始化
int binarySearchTreeInit(BinarySearchTree **pBstree, int (*comparaFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
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

    /*钩子函数在这边赋值*/
    /*比较函数*/
    bstree->comparaFunc = comparaFunc;
    /*打印函数*/
    bstree->printFunc = printFunc;
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
int binarySearchTreeInsertVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
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
        cmp = pBstree->comparaFunc(val, travelNode->data);

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
    int cmp = 0;
    while (travelNode != NULL)
    {
        cmp = pBstree->comparaFunc(val, travelNode->data);
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
            return travelNode;
        }
    }
    return NULL;
}
// 二叉搜索树是否包含指定元素
int binarySearchTreeContainAppointVal(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetNode(pBstree, val) == NULL ? 0 : 1;
}

// 二叉搜索树的前序遍历
static int preOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    /*输出节点内容*/
    pBstree->printFunc(node->data);
    /*左子树*/
    inOrderTravel(pBstree, node->left);

    /*右子树*/
    inOrderTravel(pBstree, node->right);
}
// 二叉搜索树的前序遍历
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    preOrderTravel(pBstree, pBstree->root);
    return ON_SUCCESS;
}

// 二叉搜索树的中序遍历
static int inOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    /*左子树*/
    inOrderTravel(pBstree, node->left);
    /*输出节点内容*/
    pBstree->printFunc(node->data);
    /*右子树*/
    inOrderTravel(pBstree, node->right);
}
// 二叉搜索树的中序遍历
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    inOrderTravel(pBstree, pBstree->root);
    return ON_SUCCESS;
}

// 二叉搜索树的后序遍历
static int postOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    /*左子树*/
    inOrderTravel(pBstree, node->left);

    /*右子树*/
    inOrderTravel(pBstree, node->right);
    /*输出节点内容*/
    pBstree->printFunc(node->data);
}

// 二叉搜索树的后序遍历
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree, BSTreeNode *node)
{
    postOrderTravel(pBstree, pBstree->root);
    return ON_SUCCESS;
}

// 二叉搜索树的层序遍历
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    DoubleLinkListQueue *pQueue = NULL;
    doublelinklistQueueInit(&pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    BSTreeNode *popNode = NULL;
    while (!doublelinklistQueueIsEmpty(pQueue))
    {

        doubleLinkListQueueTop(pQueue, (void *)&popNode);
        // 使用回调函数
        pBstree->printFunc(popNode->data);
        doublelinklistQueuePop(pQueue);
        /*左子树入队*/
        if (popNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->left);
        }
        /*右子树入队*/
        if (popNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->right);
        }
    }
    doubleLinkListQueueDestroy(pQueue);
    return ON_SUCCESS;
}
// 判断二叉搜索树度为2
static int binarySearchTreeHasTwoChild(BSTreeNode *node)
{
    return (node->left != NULL && node->right != NULL) ? 1 : 0;
}
// 判断二叉搜索树度为1
static int binarySearchTreeHasOneChild(BSTreeNode *node)
{
    return ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL)) ? 1 : 0;
}
// 判断二叉搜索树度为0
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return (node->left == NULL && node->right == NULL) ? 1 : 0;
}
// 获取当前结点的前驱节点
static BSTreeNode *bstreeNodePreDecessor(BSTreeNode *node)
{

    BSTreeNode *travelNode = node;
    if (travelNode->left != NULL)
    {
        travelNode = travelNode->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    else
    {
        /*没有左子树且为根节点*/
        if (node->parent == NULL)
        {
            return NULL;
        }

        while (node == node->parent->left && node->parent != NULL)
        {
            node = node->parent;
        }
        return node->parent;
    }
    /*程序到这里一定是度为1或者度为0的*/
}
// 获取当前结点的后继节点
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node)
{
    if ()
}
// 获取二叉搜索树的高度
int binarySearchTreeGetHeight(BinarySearchTree *pBstree, int *pHeight)
{
    DoubleLinkListQueue *pQueue = NULL;
    doublelinklistQueueInit(pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    int height = 0;
    int size = 1;
    BSTreeNode *popNode = NULL;
    while (!doublelinklistQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&popNode);
        doublelinklistQueuePop(pQueue);
        size--;

        /*左子树不为空，入队*/
        if (popNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->left);
        }

        /*右子树不为空，入队*/
        if (popNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->right);
        }

        /*树的当前层结点遍历结束*/
        if (size == 0)
        {
            height++;
            doubleLinkListQueueSize(pQueue, &size);
        }
    }
    // 解引用
    *pHeight = height;

    /*释放队列空间*/
    doubleLinkListQueueDestroy(pQueue);
    return ON_SUCCESS;
}
/*二叉搜索树的删除*/
int binarySearchTreeDelete(BinarySearchTree *pBstree, ELEMENTTYPE val)
{
    BSTreeNode *currentNode = NULL;
    if (binarySearchTreeHasTwoChild(currentNode))
    {
        BSTreeNode *preNode = precursorNode(currentNode);
    }
}
/*二叉搜索树的销毁*/
int binarySearchTreeDestroy(BinarySearchTree *pBstree)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    DoubleLinkListQueue *pQueue = NULL;
    doublelinklistQueueInit(pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);
    BSTreeNode *popNode = NULL;
    while (!doublelinklistQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&popNode);
        doublelinklistQueuePop(pQueue);
#if 0 // 不可以先释放，因为左右孩子还没有入队
        /*释放结点*/
        if (popNode != NULL)
        {
            free(popNode);
            popNode == NULL;
        }
#endif
        /*左子树不为空，入队*/
        if (popNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->left);
        }

        /*右子树不为空，入队*/
        if (popNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, popNode->right);
        }

        /*释放结点*/
        if (popNode != NULL)
        {
            free(popNode);
            popNode == NULL;
        }
    }
    if (pBstree != NULL)
    {
        free(pBstree);
        pBstree == NULL;
    }
    /*释放队列*/
    doubleLinkListQueueDestroy(pQueue);
    return ON_SUCCESS;
}