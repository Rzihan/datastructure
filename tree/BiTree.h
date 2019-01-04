//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H

#include "SqBiTree.h"

typedef struct BiTNode {
    TElemType data;                   // 数据域
    struct BiTNode *lchild, *rchild;  // 左、右孩子指针
} BiTNode, *BiTree;   // 二叉链表

/**
 * 创建一棵二叉树T，其中根结点的值为e，L和R分别作为左子树和右子树
 * @param e
 * @param L
 * @param R
 * @return
 */
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R);

/**
 * 替换左子树。若T非空，则用LT替换T的左子树，并用LT返回T的原有左子树
 * @param T
 * @param LT
 * @return
 */
Status ReplaceLeft(BiTree &T, BiTree &LT);

/**
 * 中序遍历
 * @param T
 * @param visit
 * @return
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 * 使用栈的非递归中序遍历
 * @param T
 * @param visit
 */
void InorderTraverse_I(BiTree T, Status(*visit) (TElemType e));

/**
 * 使用队列的非递归遍历
 * @param T
 * @param visit
 */
void LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 * 销毁二叉树T
 * @param T
 */
void DestroyBiTree(BiTree &T);

/**
 * 求二叉树深度
 * @param T
 * @return
 */
int BiTreeDepth(BiTree T);

/**
 * 二叉树的叶子结点计数
 * @param T
 * @param count
 */
void CountLeaf(BiTree T,  int &count);

/**
 * 基于先序遍历框架构造二叉树。defBT为树形描述序列，i为defBT的当前位标，
 * 初值为0。
 * @param defBT
 * @param i
 * @return
 */
BiTree CreateBiTree(char *defBT, int &i);

/**
 * 创建一棵空的二叉树
 * @param T
 */
void InitBiTree(BiTree &T);
#endif //DATASTRUCTURE_BITREE_H
