//
// Created by Pan梓涵 on 2019/1/4.
//

#ifndef DATASTRUCTURE_CSTREE_H
#define DATASTRUCTURE_CSTREE_H

#include "../base/statu.h"

typedef int TElemType;

/**
 * 孩子兄弟表示法
 */
typedef struct CSTNode {
    TElemType data;                         // 数据域
    struct CSTNode *firstChild,*nextSibling;// 最左孩子指针、右兄弟指针
} CSTreeNode,*CSTree,*CSForest;             // 孩子兄弟链表

/**
 * 构造空树
 * @param T
 * @return
 */
Status InitTree(CSTree &T);

/**
 * 创建根结点e和n棵子树的树
 * @param e
 * @param n
 * @param ...
 * @return
 */
CSTree MakeTree(TElemType e, int n, ...);

/**
 * 销毁树
 * @param T
 * @return
 */
Status DestroyTree(CSTree &T);

/**
 * 返回树T的深度
 * @param T
 * @return
 */
int TreeDepth(CSTree T);

/**
 * 查找树T中的结点e，并返回其指针
 * @param T
 * @param e
 * @return
 */
CSTNode* Search(CSTree T, TElemType e);

/**
 * 插入c为T的第i棵子树，1≤i≤d+1（d为T所指结点的度），c非空并与T不相交
 * @param T
 * @param i
 * @param c
 * @return
 */
Status InsertChild(CSTree T, int i, CSTree c);

/**
 * 删除第i棵子树
 * @param T
 * @param i
 * @return
 */
Status DeleteChild(CSTree &T, int i);

#endif //DATASTRUCTURE_CSTREE_H
