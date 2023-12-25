#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_
#define ELEMENTTYPE void *
typedef struct BSTreeNode
{
    ELEMENTTYPE val;
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
} BinarySearchTree;

// 二叉搜索树初始化
int binarySearchTreeInit(BinarySearchTree **pBstree);

// 二叉搜索树的插入
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val);

#endif //__BINARY_SEARCH_TREE_H_