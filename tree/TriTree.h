//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_TRITREE_H
#define DATASTRUCTURE_TRITREE_H

#include "SqBiTree.h"

typedef struct TriTNode {
    TElemType data; // 数据域
    TriTNode *parent, *lchild, *rchild;
    // 双亲、左、右孩子指针
} TriTNode, *TriTree; //三叉链表

/**
 * 不使用栈的先序非递归遍历
 * @param T
 * @param visit
 * @return
 */
Status PreOrderTraverse(TriTree T, Status (*visit)(TElemType e));
#endif //DATASTRUCTURE_TRITREE_H
