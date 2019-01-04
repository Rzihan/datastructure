//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_SQBITREE_H
#define DATASTRUCTURE_SQBITREE_H

#include "../base/statu.h"

typedef char TElemType;     // 假设二叉树结点的元素类型为字符
typedef struct {
    TElemType *elem;        // 0号单元闲置
    int lastIndex;          // 二叉树最后一个结点的编号
} SqBiTree;    // 顺序存储的二叉树

/**
 * 判断完全二叉树T的v结点是否是u结点的子孙
 * @param T
 * @param u
 * @param v
 * @return
 */
Status is_Desendant(SqBiTree T, int u, int v);
#endif //DATASTRUCTURE_SQBITREE_H
