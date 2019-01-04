//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_BBSTREE_H
#define DATASTRUCTURE_BBSTREE_H

#include "../sort/RcdSqList.h"
#include "../base/statu.h"

typedef struct BBSTNode {
    RcdType data;
    int bf;  // 结点平衡因子
    struct BBSTNode *lchild, *rchild;
}*BBSTree;

/**
 * 插入平衡二叉树
 * @param T
 * @param e
 * @param taller
 * @return
 */
Status InsertAVL(BBSTree &T, RcdType e, Status &taller);
#endif //DATASTRUCTURE_BBSTREE_H
