//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_BSTREE_H
#define DATASTRUCTURE_BSTREE_H

#include "../sort/RcdSqList.h"
#include "../base/statu.h"

typedef struct BSTNode {               // 结点结构
    RcdType data;                      // 数据元素
    struct BSTNode *lchild, *rchild;   // 左右孩子指针
} BSTNode, *BSTree;                    // 二叉查找树

/**
 * 初始化二叉查找树
 * @param T
 * @return
 */
Status InitBST(BSTree &T);

/**
 * 销毁二叉查找树
 * @param T
 * @return
 */
Status DestroyBST(BSTree &T);

/**
 * 在二叉查找树查找元素
 * @param T
 * @param key
 * @return
 */
BSTree SearchBST(BSTree T, KeyType key);

/**
 * 在二叉查找树插入元素
 * @param T
 * @param e
 * @return
 */
Status InsertBST(BSTree &T, RcdType e);

/**
 * 在二叉查找树删除元素
 * @param T
 * @param key
 * @return
 */
Status DeleteBST(BSTree &T, KeyType key);
#endif //DATASTRUCTURE_BSTREE_H
